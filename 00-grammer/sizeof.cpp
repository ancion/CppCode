#include <iostream>
using namespace std;

//
// cpp 中的一个运算符, 用于计算数据类型或者变量占用的内存空间
// sizeof(type)  || sizeof variable

int main() {

  cout << "sizeof int : "  << sizeof(int) << endl;
  cout << "sizeof float : " << sizeof(float) << endl;
  cout << "sizeof double: " << sizeof(double) << endl;
  cout << "sizeof char : " << sizeof(char) << endl;
  cout << "sizeof bool : " << sizeof(bool) << endl;

  // string 不是 c++ 的基本数据类型，
  // 使用 sizeof 求内存大小没有实际意义, 或者的只是这个类型的指针的大小
  cout << sizeof(string) << endl;


  // 计算变量占用空间的大小
  int a = 10;
  cout << sizeof(a) << endl;


  // 直接计算字面量的大小
  // 
  cout << sizeof(10) << endl;


}

