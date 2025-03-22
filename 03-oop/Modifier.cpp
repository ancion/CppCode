#include "../include/Modifier.h"
#include <iostream>

using namespace std;

bool Flag::get_flag() const  {
  // 访问了 mutable 的变量
  accesses++;
  cout << "Accesses incremented to :: "  << accesses << endl;
  return flag;
}

void class_flag() {
  const Flag flag(true);

  for (int i = 0; i < 5; i++) {
    flag.get_flag();
  }
}
