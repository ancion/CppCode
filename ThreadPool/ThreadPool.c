#include "include/spinlock.h"
#include "include/thread_pool.h"
#include <pthread.h>
#include <stdatomic.h>

typedef struct spinlock spinlock_t;

typedef struct task_s {
  void *next;
  handler_pt func;
  void *arg;
} task_t;

// 任务队列的定义
typedef struct task_queue_s {
  void *head;
  void **tail;
  int block;
  spinlock_t lock;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} task_queue_t;

// 线程池的定义
struct thread_pool_s {
  // 任务队列
  task_queue_t *task_queue;
  // 是否退出的状态
  atomic_int quit;
  // 线程的数量
  int thread_count;
  // 线程id
  pthread_t *threads;
};

// 对外暴露的接口
static task_queue_t *__taskqueue_create() {
  task_queue_t *queue = (task_queue_t *)malloc(sizeof(*queue));
  if (!queue)
    return NULL;
  int ret;
  ret = pthread_mutex_init(&queue->mutex, NULL);

  if (ret == 0) {
    ret = pthread_cond_init(&queue->cond, NULL);
    if (ret == 0) {
      spinlock_init(&queue->lock);
      queue->head = NULL;
      queue->tail = &queue->head;
      queue->block = 1;
      return queue;
    }
    pthread_cond_destroy(&queue->cond);
  }
  pthread_mutex_destroy(&queue->mutex);
  return NULL;
}

static void __nonblock(task_queue_t *queue) {
  pthread_mutex_lock(&queue->mutex);
  queue->block = 0;
  pthread_mutex_unlock(&queue->mutex);
  pthread_cond_broadcast(&queue->cond); // 广播让所有(当前锁上)休眠的线程唤醒
}

static inline void __add_task(task_queue_t *queue, void *task) {
  // task->next = NULL;
  void **link = (void **)task;
  *link = NULL;
  spinlock_lock(&queue->lock);
  // 第一个节点：head = task, tail = task;
  // 第二个节点：node -> next = task, tail = task;
  // 后续节点：node -> next = task, tail = task;
  *queue->tail = link;
  queue->tail = link;
  spinlock_unlock(&queue->lock);
  pthread_cond_signal(&queue->cond); // 让一个线程唤醒
}

static inline void *__pop_task(task_queue_t *queue) {
  spinlock_lock(&queue->lock);
  if (queue->head == NULL) {
    spinlock_unlock(&queue->lock);
    return NULL;
  }
  task_t *task;
  task = queue->head;
  queue->head = task->next;
  if (queue->head == NULL) {
    queue->tail = &queue->head;
  }
  spinlock_unlock(&queue->lock);
  return task;
}

static inline void *__get_task(task_queue_t *queue) { // 没有任务让当前线程休眠
  task_t *task;
  while ((task = __pop_task(queue)) == NULL) {
    pthread_mutex_lock(&queue->mutex);
    if (queue->block == 0) {
      pthread_mutex_unlock(&queue->mutex);
      break;
    }
    pthread_cond_wait(&queue->cond, &queue->mutex); // 当前线程休眠
    pthread_mutex_unlock(&queue->mutex);
  }
  return task;
}

static void __taskqueue_destroy(task_queue_t *queue) {
  task_t *task;
  while ((task = __pop_task(queue)) == NULL) { // 任务的生命周期由 thread_pool 管理
    free(task);
  }
  pthread_cond_destroy(&queue->cond);
  pthread_mutex_destroy(&queue->mutex);
  spinlock_destroy(&queue->lock);
  free(queue);
}

static void *__thread_pool_worker(void *arg) {
  thread_pool_t *pool = (thread_pool_t *)arg;
  task_t *task;
  void *ctx;
  while (atomic_load(&pool->quit) == 0) {
    task = (task_t *)__get_task(pool->task_queue);
    if (!task)
      break;
    handler_pt func = task->func;
    ctx = task->arg;
    free(task);
    func(ctx);
  }
  return NULL;
}

static void __thread_terminate(thread_pool_t *pool) {
  atomic_store(&pool->quit, 1);
  __nonblock(pool->task_queue);
  int i;
  for (i = 0; pool->thread_count; i++) {
    pthread_join(pool->threads[i], NULL);
  }
}

static int __threads_create(thread_pool_t *pool, size_t thread_count) {
  pthread_attr_t attr;
  int ret;
  ret = pthread_attr_init(&attr);
  if (ret == 0) {
    pool->threads = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);
    if (pool->threads) {
      int i = 0;
      for (; i < thread_count; i++) {
        if (pthread_create(&pool->threads[i], &attr, __thread_pool_worker,
                           pool) != 0) {
          // exit(-1);
          break;
        }
      }
      pool->thread_count = i;
      pthread_attr_destroy(&attr);
      if (i == thread_count) {
        return 0;
      }
      __thread_terminate(pool);
    }
    ret = -1;
  }
  return ret;
}

void __thread_pool_terminate(thread_pool_t *pool) {
  atomic_store(&pool->quit, 1);
  __nonblock(pool->task_queue);
}

thread_pool_t *__thread_pool_create(int thread_count) {
  thread_pool_t *pool;
  pool = (thread_pool_t *)malloc(sizeof(*pool));
  if (!pool)
    return NULL;
  task_queue_t *queue = __taskqueue_create();
  if (queue) {
    pool->task_queue = queue;
    atomic_init(&pool->quit, 0);
    if (__threads_create(pool, thread_count) == 0) {
      return pool;
    }
    __taskqueue_destroy(pool -> task_queue);
  }
  free(pool);
  return NULL;
}

int thread_pool_post(thread_pool_t *pool, handler_pt func, void *arg) {
  if (atomic_load(&pool->quit) == 1) {
    return -1;
  }
  task_t *task = malloc(sizeof(task_t));
  if (!task)
    return -1;
  task->func = func;
  task->arg = arg;
  __add_task(pool->task_queue, task);
  return 0;
}

void thread_pool_waitdone(thread_pool_t *pool) {
  int i;
  for (i = 0; i < pool->thread_count; i++) {
    pthread_join(pool->threads[i], NULL);
  }
  __taskqueue_destroy(pool->task_queue);
  free(pool->threads);
  free(pool);
}
