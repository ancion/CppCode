#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

// 定义线程池的别名
typedef struct thread_pool_s thread_pool_t;

// 定义线程接受的任务对象
typedef void (*handler_pt)(void *);

// 创建线程池
thread_pool_t *thread_pool_create(int thread_count);

// 终止线程池
void thread_pool_terminate(thread_pool_t *pool);

// 向线程池提交任务
int thread_pool_post(thread_pool_t *pool, handler_pt func, void *arg);

// 等待线程池任务完成
void thread_pool_waitdone(thread_pool_t *pool);

#endif
