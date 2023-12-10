// c++ 中常量定义
//
// 宏常量 (一般在main 函数上声明，使用全大写的字符命名J)
//
// 语法 #define cname value
//
//
#include <iostream>

#define PI  3.14
#define MONTH  12

int main() {

  std::cout << "PI values is: " << std::endl;

  // const 定义的常量
  // 可以在程序的任意地方定义常量, 一旦定义之后不可再赋值
  const int days = 7;
  std::cout << "one week have :" <<  days << " days" << std::endl;

  return 0;
}
