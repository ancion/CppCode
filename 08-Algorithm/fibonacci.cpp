//
// fibonacci 数列的定义
// f(1) = 1
// f(n) = f(n-1) + f(n-2)

#include <iostream>
using namespace std;

// 1.转化为 c++ 代码 (递归代码)
// 随着递归深度的加深，递归的效率会逐步下降, 时间复杂度 O(2^n)
unsigned int fibonacci(unsigned int n) {
  if (n <= 1) {
    return 1;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

// 2.缓存优化的递归代码，可以提高递归的效率，时间复杂度 O(n)
// n > 46 的时候已经超出了 unsigned int 的范围, 因此这个计算方式造成在 n > 46 的时候会出错
unsigned int cache[50] = {0};

unsigned int fib(unsigned int n) {
  if (n >= 50) { // 太大了
    return -1;
  }
  if (n <= 1) {
    return 1;
  }
  if (cache[n]) {
    return cache[n];
  }
  cache[n] = fib(n-1) + fib(n-2);
  return cache[n];
}

// 3.任务分解(使用数组和变量通过递归循环的方式来计算这个数列) -> 动态规划法
unsigned int fib2(unsigned int n) {
  if (n <= 1) {
    return 1;
  }
  int fn_2 = 1;
  int fn_1 = 1;
  int fn = 0;
  for (int i = 2; i < n; i++) {
    fn = fn_2 + fn_1;
    fn_1 = fn_2;
    fn_2 = fn;
  }
  return fn;
}

int main (int argc, char *argv[]) {
  int x = fib2(2);
  cout << x << endl;

  return 0;
}
