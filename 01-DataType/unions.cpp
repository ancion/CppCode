#include <iostream>
#include "../include/DataType.h"

// unicn 是一种在 C/C++ 都存在的数据结构
// 与结构体非常类似，但是不同的是，有时只有一个字段是有效的
//

using namespace std;

struct various_data {
  // 1 byte
  char a;
  // 4 byte
  int b;
  // 4 byte
  float c;
  // 8 byte
  double d;
};

// union 对象占用的空间为内部最大成员的占用空间大小
// 可能会存在内存对齐问题，非完全的字段大小的累加结果
// -----------------------------------------------
// 内部无论存储的是哪个成员，都会占用最大成员的空间
// 联合体无论存储的是那个成员的数据，指针总是指向那个已经分配好的
// 最大内存空间
union union_data {
  various_data union_struct;
  int union_int;
  float union_float;
  double union_double;
};

void union_usage() {

  various_data v_data;

  v_data.a = 'a';
  v_data.b = 10;
  v_data.c = 876.5300;
  v_data.d = 2011.1020;

  // print out the size of a struct
  cout << "sizeof(various_data) = " << sizeof(various_data) << endl;

  // Creat a union 
  union_data u_data;
  u_data.union_struct = v_data;

  // print out the address of the union, and of the field
  cout << "sizeof(union) = " << sizeof(u_data) << endl;

  // print out the address of the union and of the field
  cout << "Union Pointer: " << &u_data << ", Field pointer = " << &(u_data.union_struct) << endl;

  // re-assing the union to contain an integer now
  u_data.union_int = 5;

  // print size of the Union and pointer again
  // 这里的指针地址还是与存储 union_struct 时指向相同
  cout << "sizeof(union) " << sizeof(u_data) << endl;
  cout << "Union Pointer: " << &u_data << ", Field pointer = " << &(u_data.union_int) << endl;
}

