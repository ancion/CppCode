#include <iostream>


// 动态内存分配
// 在 C++ 中动态内存分配可以使用 new 和 delete 运算符来完成
// new 运算符用于分配内存，
// delete 运算符用于释放内存
//
// malloc 和 free 运算符是 C 语言中的函数，用于分配和释放内存
// malloc 分配的内存不能使用 delete 运算符释放


using namespace std;

int main(int argc, char* argv[]) {

  int* myInt = new int;

  // 检查内存是否分配成功
  if (myInt == nullptr) {
    cout << "Memory not allocated" << endl;
    return 1;
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
