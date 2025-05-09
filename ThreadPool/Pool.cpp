#include <pthread.h>


//  宏替换的时候需要注意在替换之后,可能造成语义改变, 或者语法错误
// =============================================================================
// 1.使用宏定义表达式, 需要添加适当的括号，防止替换后出现语义改变
//    > * 例如在使用数字计算的时候,需要使用括号包裹,防止替换后计算优先级改变
// 2.当使用宏定义函数时，防止替换后出现语法错误
//    > * 需要使用 do {} while(0) 包裹, 
// =============================================================================
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

