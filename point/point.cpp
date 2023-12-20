#include <iostream>

using namespace std;
//
// C++ 中的指针
// ---------------------------------------------------------------
//  > 变量其实是内存变量的简称, 每定义一个变量，系统就会给
//    变量分配一块内存, 内存是有地址的. 使用十六进制数表示
//
//  > C++ 中使用 &variable 的方式获取内存地址的起始位置
//
//  > 指针变量简称指针，是一种特殊的变量，专用于存放内存中
//    的起始地址（type *variable）
//    - type 必须是合法的 C++ 类型，基本类型或者自定义类型
//    - 这里的 * 表示当前变量是指针类型
//
//  > 指针赋值的语法 type *ptr = &variable
//
//  > 指针占用内存的大小: 64 位操作系统不管是什么类型都占用 8 字节.
//
//
//  > 指针的使用
// -----------------------------------------------------------------
//  > 指针申明之后，在没有赋值之前，里面的值是乱七八糟的，这时候不能使用指针
//
//  > * 运算符被称为解引用运算符符，将它应用于指针，可以获取指针指向内存地址
//    中存储的值。
//
//

void show_ptr_val() {
  int a;
  char b;
  bool c;
  string d;

  // 获取内存地址，可能对应数据并不能准确显示
  cout << "variable a addr: " << &a << endl;
  cout << "variable b addr: " << &b << endl;
  cout << "variable c addr: " << &c << endl;
  cout << "variable d addr: " << &d << endl;

  // 转换为 void* (16 进制数)
  cout << "variable a addr: " << (void *)&a << endl;
  cout << "variable b addr: " << (void *)&b << endl;
  cout << "variable c addr: " << (void *)&c << endl;
  cout << "variable d addr: " << (void *)&d << endl;
}

void ptrdeclare() {

  // 指针型变量的赋值
  int a;
  char b;
  bool c;
  string d;

  // 指针赋值
  // 对指针的赋值通常被叫做`指向某变量`, 被指向的变量的数据类型为`基类型`
  int *pa = &a;
  char *pb = &b;
  bool *pc = &c;
  string *pd = &d;

  cout << "sizeof(pa) " << sizeof(int *) << " " << sizeof(pa) << endl;
  cout << "sizeof(pb) " << sizeof(char *) << " " << sizeof(pb) << endl;
  cout << "sizeof(pa) " << sizeof(bool *) << " " << sizeof(pc) << endl;
  cout << "sizeof(pd) " << sizeof(string *) << " " << sizeof(pd) << endl;

  // 当基类型与指针类型不相符的时候，可以强制转换，但是不安全
  int *x = (int *)&b;
  char *y = (char *)&a;

  // 或者转换为 long long 类型来表示(10 进制数)
  //
  cout << "variable a addr: " << (long long)&a << endl;
  cout << "variable b addr: " << (long long)&b << endl;
  cout << "variable c addr: " << (long long)&c << endl;
  cout << "variable d addr: " << (long long)&d << endl;
}

int main() {

  // 展示指针的实际值
  show_ptr_val();
  // 指针的声明与赋值
  ptrdeclare();

  return 0;
}
