#include <iostream>
#include <stdio.h>
#include "CppAdd.h"

// 构建一个 C++ 代码库，供 C  来调用
//
int cppadd(int a, int b) {
  printf("from Cpp function\n");
  std::cout << "from Cpp function" << std::endl;
  return a + b;
}
