#include <stdio.h>

// 编译指令，表明 gcc 是可以处理 包含 c 库头文件代码的 c++ 文件
// gcc -x c++ main_clib.cpp -o mainc
int main(int argc, char *argv[]) {
  printf("hello.\n");
  return 0;
}
