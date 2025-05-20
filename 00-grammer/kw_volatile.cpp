//
// 禁止编译器对变量的优化
// volatile 修饰符
// volatile 修饰符的作用是告诉编译器不要对该变量进行优化
//
// 部分时候, 变量可能用于接收外部硬件的值, 但是编译器从代码层面认为值没有在变
// 被优化掉

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// 如果 wait 被优化掉，会导致无限循环
// int wait = 1;
volatile int wait = 1;

void* function(void* arg) {
  while(1) {
    sleep(1);
    wait = 0;
    printf("flag wait = %d\n in thread \n", wait);
  }
  return NULL;
}

int main(void) {
  pthread_t tid;
  pthread_create(&tid, NULL, function, NULL);
  while(wait);
  printf("flag wait = %d in main\n", wait);
  return 0;
}
