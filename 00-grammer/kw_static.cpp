// static 关键字在 C 语言中有两种作用
//
// 1. static 修饰符
//    控制变量在全局静态区中分配内存
// 2. static 函数
//    控制函数在当前文件中有效，无法导入到其他文件中使用
//
#include <iostream>


void static_func() {
  // 静态变量申请在全局静态区中，只会初始化一次，并且生命周期是整个程序的生命周期
  static int count = 0;
  count++;

  std::cout << "static function called " << count << " times" << std::endl;
}

// static 修饰符 修饰的函数和变量作用在当前文件中，不会在其他文件中生效
static int b = 10;

int c = 20;

// static 函数
static void func() {}


