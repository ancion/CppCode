// c++ 中常量定义
//
// 宏常量 (一般在main 函数上声明，使用全大写的字符命名J)
// 语法 #define cname value
//
// const type name  或者 type const name  均可
#include <iostream>

#define PI 3.14
#define MONTH 12

void const_usage() {

  std::cout << "PI values is: " << PI  << std::endl;

  // const 定义的常量(应该被理解为只读变量，理论上只是进行了标记，可以通过其他方式修改)
  // 可以在程序的任意地方定义常量, 一旦定义之后不可再赋值(在 C 中可以通过指针绕过限制修改days 值)
  const int days = 7;

  std::cout << "one week have :" << days << " days" << std::endl;
}
