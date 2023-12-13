// c++ 中的 数字主要分为
// int 整数 (整数总共分为六种)
// --------------------------------------------------------- 
// (signed / unsigned)short  ==> 简写 => short / unsigned short
// (signed / unsigned)int    ==> 简写 => int   / unsigned int
// (signed / unsigned)long   ==> 简写 => long  / unsigned long
//
//
//  需要注意的是，不同整数长度的类型都有自己取值范围，会出现数据溢出的问题
//  使用的时候需要认真考虑使用的数据类型的大小，不要超出范围的使用数据类型
//  (将整数类型区分的这么细致的目的在于在小的数据使用可以节省内存空间)
//  (值得注意的是，在不同的操作系统中, long 类型的取值范围是不同的)
//
// -------------------------------------
// > 进制数
//   * 0b / 0B  ==> 示例 Ob0101 (二进制数是编译器扩展的写法，不是C++标准)
//   * 0        ==> 示例 027100 (八进制数以 0 开头，这点设计比较奇怪), 
//   * 0x / 0X  ==> 示例 0x123A (十六进制以 0x 开头, 字母不区分大小写)
//
// > C++11 标准
//   long long 类型, 至少64位(8byte)，且至少与 long 一样长
//   (因为在 Windows 系统中long 类型为 4 byte, 而 linux 为 8 byte)
// ---------------------------------------------------------
//
// 浮点数(主要有三种)
// --------------------------------------------------------------------------
//  float : 单精度,  4 byte (7位有效数字)
//  double : 双精度, 8 byte (15-15位有效数字)
//  long double : 扩展精度(不低于 double) <Windows 中与double相同,linux 中用16byte>
// --------------------------------------------------------------------------
//  浮点数的存储方式和整数不一样，比较复杂，这里不做深入研究，遇到特定场景可以自行研究
//  > 实际开发中, 大多数场景使用整数替代浮点数, 整数运算更快，精度更高



#include <iostream>
#include <string>

using namespace std;

void multicode() {

  int a = 0b1011111; // 二进制数据只能使用01组合而成
  int b = 042344444; // c++ 程序数字前的 0 表示的是八进制，不能随意修改
  int c = 0xffffa12; // 十六进制数据, 由 0-9 和 a-f 组成
  cout << "多进制数据 cout 时会自动转换为十进制" << a << b << c << endl;
}

void number_float() {

  // 字面量的小数会被认为是 double 类型，如果要标定是 float, 数字后使用 f 标记
  float a = 342.456467f;
  double b = 123243354535.353564;
  long double c = 123243354535.353564;
  // 使用 cout 会使用科学计数的方式输出, C++ 默认使用 6 位有效数字
  // 如果需要更多位的有效数字可以使用 c 语言中 printf()
  printf("%lf\n", a);
  printf("%lf\n", b);
  printf("%Lf\n", c);
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

