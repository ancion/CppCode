// c++ 中的注释
//
//
// 单行注释
//
//
/* 
 * 多行注释
 */

#include <iostream>
#include <string>

int main() {
  
  // 变量的声明
  std::string name;
  int age;
  double weight; 

  // 变量赋值
  name = "Alex";
  age = 19;
  weight = 89.0;

  // 注释可以放在一行之内，
  std::cout << "name: " << name << /* "age:" << age << */ "weight: "  << weight << std::endl;

}
