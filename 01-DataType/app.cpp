#include <iostream>
#include <stdio.h>

void test() { printf("hello-----\n"); }

// 主函数
int main() {
  int a = 10;
  if (a == 10) {
    printf("hello\n");
  }
  test();
  // iostream
  std::cout << "hello world\n";
  std::cout << "hello world\n";
  std::cout << "hello world\n";
  std::cout << "hello world\n";
  return 0;
}
