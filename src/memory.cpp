#include <iostream>



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
