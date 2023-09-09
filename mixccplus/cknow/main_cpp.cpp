
#include <cstdio>
#include <iostream>
#include <ostream>

// 编译包含 c++ 标准库的代码
// 编译指令 gcc -x c++ main_cpp.cpp -lstdc++ -o maincpp
int main(int argc, char *argv[]) {
  std::cout << "hello" << std::endl;
  printf("Hello.\n");
  return 0;
}
