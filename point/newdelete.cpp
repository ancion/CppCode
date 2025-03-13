
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
// 2. 如果分配的内存不用了，必须用delete 来释放，否则有可能用尽系统的内存
// 3. 动态分配的内存生命周期与程序相同，程序退出时，如果没有释放则系统自动回收
// 4. 就算指针的作用域已经失效，所指向的内存也不会释放
// 5. 用指针跟踪已分配的内存，不能跟丢
//
// -----------------------------------------------------------------

// 动态内存分配
// 在 C++ 中动态内存分配可以使用 new 和 delete 运算符来完成
// new 运算符用于分配内存，
// delete 运算符用于释放内存
//
// malloc 和 free 运算符是 C 语言中的函数，用于分配和释放内存
// malloc 分配的内存不能使用 delete 运算符释放

#include "../include/cppmod.h"
#include <csetjmp>
#include <iostream>
#include <vector>

using namespace std;

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

  // -------------------------------
  int* myInt = new int;
  // 检查内存是否分配成功
  if (myInt == nullptr) {
    cout << "Memory not allocated" << endl;
    return;
  }
  // 在分配的内存中存储一个值
  *myInt = 10;
  cout << "Value of MyInt: " << *myInt << endl;
  // 使用 delete 释放内存
  delete myInt;
  myInt = nullptr; // 防止产生悬垂引用
  // 检查内存是否被释放
  if (myInt == nullptr) {
    cout << "Memory successfully freed." << endl;
  }
}

void array_pointer() {
  // 声明一个可以存储 10 个 int 类型数据的数组
  int *arr = new int[10];

  // 释放这部分内存空间, 必须使用[], 否则只会回收第一个元素的内存
  // 只会回收第一个元素内存地址, 数组的元数据(例如数组大小)也不会释放,
  // 如果数组内存储的是类对象，类的析构函数也不会被调用
  // delete arr; 
  delete[] arr;
}

int* good_point() {
  // 使用 new 分配了堆内存，返回返回了堆内存上的地址
  int *p = new int;
  *p = 10;
  return p;
}

int* bad_point() {
  // a 是一个局部变量, 分配在栈上，
  // 直接返回栈内存地址，栈内存随时会被回收，
  // 这是不安全的，可能导致未定义行为 (Undefined Behavior)
  int a = 10;
  return &a;
}

void bad_behaviors() {

  int* p2 = good_point();
  cout << "Address: " << p2 << ", Value " << *p2 << endl;
  // 释放内存
  delete p2;

  // 当有一个指针变量存储着在堆上分配的内存
  // 当这个指针被反复赋值时，会导致内存泄漏
  // 因为其他的被覆盖的内存没有被释放
  vector<int*> old_pointers;

  for (int i = 0; i < 5; i++) {
    p2 = good_point();
    old_pointers.push_back(p2);
  }
  // 只是删除了最后一次指向的堆内存
  delete p2;

  // 依然可以查看这些指针指向的值，并没有被释放
  // 释放所有堆内存(注意，最后一个已经被释放，不能重复释放)
  for (int i = 0; i < old_pointers.size() - 1; i++) {
    cout << "old_pointers[" << i  << "] Value: " << *old_pointers[i] << endl;
    delete old_pointers[i];
  }
}

// 如果不释放内存，一直申请会造成内存泄漏
void overflow_error() {
  for (int ii = 1; ii > 0; ii++) {
    int *p = new int[100000]; // 申请十万个整数的数组
    cout << "ii = " << ii << "p = " << p << endl;
  }
}

void new_delete_memory() { 
  // 数值的申请使用
  init(); 
  // 数将内存空间申请使用
  array_pointer();
  // 内存溢出
  // overflow_error();

  // 局部作用域中返回指针
  bad_behaviors();
}

