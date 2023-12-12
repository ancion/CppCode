//
// #include <cstdio>
#include <ctime>
#include <iostream>

using namespace std;

int fib(int x) {
  if (x <= 0) {
    return 0;
  }
  if (x <= 2) {
    return 1;
  }
  return fib(x - 1) + fib(x - 2);
}

int main() {
  int t1, t2;
  // clock 函数得到的是纳秒数。
  t1 = clock();
  cout << t1 << endl;
  fib(50);
  t2 = clock();
  cout << t2 << endl;
  cout << (double)(t2 - t1) / 1000 << "ms" << endl;
  cout << (double)(t2 - t1) / CLOCKS_PER_SEC << "s" << endl;
  return 0;
}
