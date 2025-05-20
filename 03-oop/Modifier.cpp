#include "../include/Modifier.h"
#include <iostream>

using namespace std;

// 类中声明的静态变量，需要在全局进行初始化
int Flag::apoll = 20;

bool Flag::get_flag() const  {
  // 访问了 mutable 的变量
  accesses++;
  cout << "Accesses incremented to :: "  << accesses << endl;

  // 对象方法中可以访问 static 变量
  cout << "static value " << apoll << endl;

  return flag;
}

void oop_modifer() {

  const Flag flag(true);

  // 无法在一个类的外部访问 static 变量
  cout << "static value: " << flag.apoll << endl;

  for (int i = 0; i < 5; i++) {
    flag.get_flag();
  }
}
