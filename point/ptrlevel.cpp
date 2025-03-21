#include <iostream>

using namespace std;

// -----------------------------------------------------------------
// > 二级指针
//  指针是指针变量的简称，也是变量, 是变量就有地址，指针用于存放普通变量的地址，
//
//  二级指针的语法 (数据类型＊* 指针名)
//
//  使用指针有两个目的： 1) 传递地址，2) 存放动态分配的内存的地址
//

// 二级指针
void two_level_ptr() {

  int a = 8;
  // 指针变量
  int *pa = &a;
  // 二级指针
  int **ppa = &pa;

  cout << "a    val : " << a << ", a ptr :  " << &a << endl;
  cout << "pa   val : " << pa << ", pa prt: " << &pa << endl;
  cout << "ppa  val : " << ppa << ", ppa prt: " << &ppa << endl;
  cout << "*ppa val : " << *ppa << ", **ppa: " << **ppa << endl;
}

void resign1(int *val) { val = new int(10); }

void resign2(int **val) { *val = new int(10); }

// 验证这时
// 实参内的值是否被改变
void changeval() {
  int *p = 0;
  resign1(p);
  // 验证 p 的值是否被改变
  cout << "p" << *p << endl;
  resign2(&p);
  cout << "p" << *p << endl;
}

int level_ptr() {

  // 二级指针
  two_level_ptr();

  // 怎样传参才会影响实参(传递指针, 如果变量本身是指针类型，则需要二级指针)
  changeval();

  return 0;
}
