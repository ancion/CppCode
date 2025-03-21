// 函数指针

// 案例 pthread_create, 
//
// 
// int pthread_create(
//     pthread_t *restrict thread,
//     const pthread_attr_t *restrict attr,
//     void *(*start_routine)(void *),  // 函数指针, 用于执行传入的函数
//     void *restrict arg
// );
//
// 2.  signal
//
// void (*signal(int sig, void (*func)(int)))(int);

//
#include <stdio.h>

int add (int a, int b) { return a + b; }
int sub (int a, int b) { return a - b; }
int mul (int a, int b) { return a * b; }
int div (int a, int b) { return a / b; }

void funptr(){

  int (*p)(int, int) = NULL;
  int m = 40, n = 15;

  p = add;
  printf("+ %d\n", (*p)(m, n));
  p = sub;
  printf("- %d\n", (*p)(m, n));
  p = mul;
  printf("* %d\n", (*p)(m, n));
  p = div;
  printf("/ %d\n", (*p)(m, n));

}

