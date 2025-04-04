#include <iostream>

using namespace std;

/**
* ------------------------------------------------------
*  结构体的内存布局
* ------------------------------------------------------
*/

// 在 64bit 机器上，地址的word 为 8Byte, 因此对齐的时候
// 会补齐到 8 Byte, 由于结构体在内存空间的使用是按照字段的顺序
// 这里会使用 4(int) + 8(double) + 4(int) + 8(double)
// 但是 integer 后面放不下一个 double, 因此只能补齐到 8 Byte
// 总共使用 32 Byte
struct bad_struct {
  int id_1;
  double weight_1;
  int id_2;
  double weight_2;
};

// 由于内存地址读取没有换行，因此前面两个 int 可以共用
// 这里使用 4(int) + 4(int) + 8(double) + 8(double)
// 总共使用 24 Byte
struct good_struct {
  int id_1;
  int id_2;
  double weight_1;
  double weight_2;
};

// Now what happens when we tell the compiler to pack these value;
// Depends! We could have un-aligned accesses depending on what is  in your struct
// 可以使用宏定义来告知编译器，不使用对齐而使用连续内存
// 这样排列之后，(1)char + (1)char 之后空出 6 byte 
// 但是放不下 double, 就造成 double 的地址存在两个 word 中
struct potentially_unsafe_products {
  // IDs for the products
  char id_1;
  char id_2;
  double weight_1;
}
// 告诉编译器不要对齐(压缩存储空间)
__attribute__((packed));


void space() {

  // create an instance of the three structs 
  bad_struct A;
  good_struct B;
  potentially_unsafe_products C;

  // print out the size of each struct 
  cout << "sizeof(bad_struct) = " << sizeof(bad_struct) << endl;
  cout << "sizeof(good_struct) = " << sizeof(good_struct) << endl;
  cout << "sizeof(potentially_unsafe_products) = " << sizeof(potentially_unsafe_products) << endl;

}

