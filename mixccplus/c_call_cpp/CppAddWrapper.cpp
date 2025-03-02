#include <stdio.h>
#include <iostream>
#include "CppAddWrapper.h"
#include "CppAdd.h"


int cppaddwrapper(int a, int b) {
  std::cout<< "from wapper function" << std::endl;
  printf("from wrapper function\n");
  return cppadd(a, b);
}
