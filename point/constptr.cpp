#include <cstdio>
#include <iostream>

using namespace std;

//  > const 修饰指针变量
// ----------------------------------------------------------------
//  > 常量指针(const type *variable)：
//   不能通过指针修改内部指向的值, 但是可以修改指向的内存地址
//
//   1. 一般用于修饰函数的形参，表示不希望在函数里修改内存地址中的值
//   2. 如果用于形参，虽然指向的值可以改变，但是这么做没有任何意义
//   3. 如果形参的值不需要改变，建议加上 const, 程序可读性更好
//
// > 指针常量(type *const variable):
//  不能修改指向的内存地址,但是可以修改内存地址中的值
//   1. 由于不能修改指针指向地址，所以一般在初始化时进行赋值。
//
//
// > 常指针常量(const type* const variable)
//  不能修改指针指向的内存地址，也不能修改内存地址中的值
//

// 指针常量
void ptr_const() {

  int a = 10, b = 20;

  int *const p = &a;
  cout << *p << endl;
  // 可以直接通过解引用后重新赋值改变内存地址中的值
  *p = 20;

  // 修改指向的内存地址是不被允许的
  // p = &b;

  cout << a << endl;
}

// 常量指针
void const_ptr() {
  // const
  int a = 2, b = 8;
  const int *p = &a;
  // p 被 const 修饰之后是只读的，不能通过指针修改值
  // *p = 10;
  // 原始的变量 a 是可以正常修改的.
  a = 10;

  // 但是常量指针指向的内存地址是可以变化的,
  // 这是被允许的(就是不能解引用后重新赋值)
  p = &b;
}

// 常指针常量

void const_type_const_ptr(){

  int a = 10, b = 20;
  const int *const p = &a;  

  // 此时指针指向的值不可修改
  // *p = 20;
  // 指针指向的地址也不可变  
  // p = &b;
}


int main() {

  // 常量指针
  const_ptr();

  // 指针常量
  ptr_const();

  return 0;
}
