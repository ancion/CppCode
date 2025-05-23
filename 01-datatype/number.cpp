//
//  C 中最早的数据类型是 char, short, int, long, float, double, long double, unsigned (关键字表示无符号)
//  C90 标准添加了 signed (关键字表示有符号)， void (无类型，无值)
//  C99 标准添加了 _Bool (布尔值，只有两个取值 true, false)，_Complex (复数), _Imaginary (虚数)
//
//
// c++ 中的 数字主要分为
// int 整数 (整数总共分为六种)
// --------------------------------------------------------- 
// (signed / unsigned)short (int)  ==> 简写 => short / unsigned short
// (signed / unsigned)(long) int    ==> 简写 => int   / unsigned int
// (signed / unsigned)long long (int)   ==> 简写 => long  / unsigned long
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
#include "../include/DataType.h"

using namespace std;

void multicode() {

  int a = 0b1011111; // 二进制数据只能使用01组合而成
  int b = 042344444; // c++ 程序数字前的 0 表示的是八进制，不能随意修改
  int c = 0xffffa12; // 十六进制数据, 由 0-9 和 a-f 组成
  cout << "多进制数据 cout 时会自动转换为十进制" << a << b << c << endl;
}

void number_float() {

  // 浮点类型的数据表示，
  //
  // 在标准规范中，浮点类型一般使用科学计数法来表示，通常一个浮点数至少需要六位有效数字
  // 至少占用 32 位的空间，其中 8 位表示指数部分, 24 位表示尾数(有效数)及其符号
  //
  // double 最小取值范围与float 相同，但是至少必须保存 10 位有效数字，
  // 一般情况下，double 占用 64 位而不是32 位, 
  // > 一些系统将多出来的 32 位全部用于表示非指数部分,这不仅增加了有效数字的位数(提高了精度) 还减少了舍入误差。
  // > 另外一些系统将这 32 位一部分用于指数部分，以容纳更大的指数，增加可表示的范围。
  // > 无论那种方式，double 类型都有至少 13 位的有效数字，超过了标准的最低要求
  //
  // 字面量的小数会被认为是 double 类型，如果要标定是 float, 数字后使用 f 标记
  float a = 342.456467f;
  double b = 123243354535.353564;

  // long double 精度只要求比 double 更高，没有具体的要求，实际上很少使用
  // 大部分的场景使用 double 精度已经能满足要求
  long double c = 123243354535.353564;

  // 科学计数法表示浮点数  
  // 指数部分与有效数之间不能有空格, 以下一些写法都是可以的
  // 可以省略整数部分(这时候 `.` 必须存在)，小数部分(这时候整数部分必须存在)
  // 指数部分如果是正数可以省略 `+`
  double d = 100e-12;
  double e = 3.131415;
  double f = 1.56e+12;
  double g = 4e16;
  double h = .8e-5;
  double i = 3.e10;

  // 默认情况下，浮点数字面亮被认为是 double 类型的精度, 
  // 如果想要使用单精度, 需要`f` 标识

  // 使用 cout 会使用科学计数的方式输出, C++ 默认使用 6 位有效数字
  // 如果需要更多位的有效数字可以使用 c 语言中 printf()
  // %f 表示浮点数的输出
  // %lf 表示 double 类型的浮点数的输出
  // %Lf 表示 long double 类型的浮点数的输出
  printf("%f\n", a);
  printf("%lf\n", b);
  printf("%Lf\n", c); 
  printf("%lf\n", d);
}


void number_usage() {
  
  number_float();

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

  cout << "name: " << name << "age:" << age << "weight: "  << weight  << "gendle:" << gendle << std::endl;

}

