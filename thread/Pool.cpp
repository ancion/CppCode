#include <pthread.h>


#define ADD_TASK(item, list) do { \
    item -> prev = NULL;          \
    item->next = list;            \
    if (list != NULL) list -> prev = item; \
    list = item;                  \
} while(0)


#define REMOVE_ADD(item, list) do {        \
    if (item -> next != NULL) item -> next -> prev = item -> prev; \
    if (item -> prev != NULL) item -> prev -> next = item -> next; \
    if (list == item) list = item -> next; \
    item -> next = item -> prev = NULL;    \
} while(0)



// 工作的数据结构
struct work_entry {

  struct work_entry *next;
  struct work_entry *prev;

  pthread_t id;
  int terminate;
  struct thread_pool *pool;
};


// 任务的数据结构
struct task_entry {

  struct task_entry *next;
  struct task_entry *prev;

  void (*handler) (void *arg);
  void *userdata;

};

// 线程池的数据结构
struct thread_pool {
  struct work_entry *workq;
  struct task_entry *taskq;

  pthread_cond_t cond;
  pthread_mutex_t mutex;
};


void thread_task_cycle(void *arg) {

  struct worker_entry *worker = (struct worker_entry*)arg;
  // 线程池循环处理任务
  while (worker->terminate == 0) {
    pthread_mutex_lock(&worker->pool->mutex);

    // 线程在有任务的时候会自动执行
    while(worker -> pool -> taskq == NULL) {
      pthread_cond_wait(&workder->pool->cond, &worker -> pool -> mutex);
    };

    struct task_entry *task = worker -> pool -> taskq;

    REMOVE_ADD(task, worker -> pool -> taskq);

    task -> handler(task -> userdata);

    pthread_mutex_unlock(&workser-> pool -> mutex):
  }

}

