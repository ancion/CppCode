// c++ 中的 数字主要分为
// int 整数 (整数总共分为六种)
// --------------------------------------------------------- 
// (signed / unsigned)short  ==> 简写 =>
// (signed / unsigned)int    ==> 简写 =>
// (signed / unsigned)long   ==> 简写 =>
//
// -------------------------------------
// > 进制数
//   * 0b / 0B  ==> 示例 Ob0101 (二进制数是编译器扩展的写法，不是C++标准)
//   * 0        ==> 示例 027100 (八进制数以 0 开头，这点设计比较奇怪), 
//   * 0x / 0X  ==> 示例 0x123A (十六进制以 0x 开头, 字母不区分大小写)
//
// > C++11 标准
//   long long 类型
//
// ---------------------------------------------------------
//
// double / float 浮点数
//



#include <iostream>
#include <string>


void multicode() {


}

int main() {
  
  // 变量的声明
  std::string name;
  int age;
  double weight;
  char gendle;
  
  // 赋值
  name = "Alex";
  age = 19;
  weight = 89.9;
  gendle = 'X';

  std::cout << "name: " << name << "age:" << age << "weight: "  << weight << std::endl;

}

