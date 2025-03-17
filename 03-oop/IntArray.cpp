#include "../include/IntArray.h"

// 测试析构函数
void class_destructor() {

  // Create a new integer array using our class
  IntArray x(10);

  // Fill the array with some values
  for (auto i = 0; i < x.size; i++) {
    x.data[i] = i;
  }

  // Copy the object, but this will only be destroyed after it leaves
  // the scope of the if statement
  if (true) {
    auto y = x;
  }
}
