#include <stdio.h>
#include "CppAddWrapper.h"


int main() {
  int c = cppaddwrapper(1, 2);
  printf("1 + 2 = %d\n", c);
  return 0;
}

