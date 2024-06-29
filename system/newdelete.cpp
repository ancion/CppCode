
// cpp 程序怎么动态分配内存和释放内存
// -------------------------------------------------------
// > 1. 声明一个指针
// > 2. 用 new 运算符向系统申请一块内存，让指针指向这块内存
// > 3. 通过对指针解引用的方法，像使用变量一样使用这块内存。
// > 4. 如果这块内存不用了，用 delete 运算符释放它
// -------------------------
// 语法 :
//  - 申请内存: new 数据类型(初始值) // C++11 支持 {}
//    申请成功则返回对应的内存地址的值，否则返回一个空地址
//  - 释放内存: delete 地址
//
// -------------------------
//
// 1. 动态分配出来的内存没有变量名，只能通过指向它的指针来操作内存中的数据
// 2. 如果分配的内存不用类，必须用delete 来释放，否则有可能用尽系统的内存
// 3. 动态分配的内存生命周期与程序相同，程序退出时，如果没有释放则系统自动回收
// 4. 就算指针的作用域已经失效，所指向的内存也不会释放
// 5. 用指针跟踪已分配的内存，不能跟丢
//

#include <iostream>

using namespace std;

void not_delete() {

  for (int ii = 1; ii > 0; ii++) {
    int *p = new int[100000]; // 申请十万个整数的数组
    cout << "ii = " << ii << "p = " << p << endl;
  }
}

void init() {

  // 申请一块 int 类型的内存空间, 并赋初始值为 5
  int *p = new int(5);

  cout << "init p: " << *p << endl;
  // 通过解指针，像使用变量一样使用它,
  // 这里我们重新赋值
  *p = 8;

  cout << "change p " << *p << endl;

  // 释放内存
  delete p;
}

void make_arr() {

  // 声明一个可以存储 10 个 int 类型数据的数组
  int *arr = new int[10];

  // 释放这部分内存空间
  delete[] arr;
}

int main() { 
  // 数值的申请使用
  init(); 
  // 数将内存空间申请使用
  make_arr();
}