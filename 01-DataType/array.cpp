
#include <cstring>
#include <iostream>

using namespace std;

// cpp 中的数组
// -----------------------------------------------------------
// > 数组是一组数据类型相同的变量存储在一起
//  1. 创建数组语法 数据类型， 数组名称[数据长度]
//     数据的长度必须是整数，可以是常量，可以是变量或者表达式
//     (
//       > C90 中规定必须使用常量表达式定义数组的大小
//       > C99 中允许使用整形非常量表达式
//       > VS 中可以使用整形非常量表达式
//       > Linux 中还可以使用整形变量
//     )
//  2. 数据的使用
//    > 数组使用下标来访问元素，数组下标从 0 开始
//    > 数组中的每个元素的特征和使用方法与单个变量完全相同
//    > 数组长度的取值是[0~(length-1)]
//
//  3. 数组内存
//    > 数组在内存中占用空间是连续的
//    > 可以使用 sizeof(数组名) 可以得道整个数据占用内存空间的大小
//      这种方式只能适用于 C++ 的基本数据类型
//
//  4. 数组的初始化
//
//    > 直接使用 int arr[] = {} 完成数组的初始化赋值
//    > 可以直接对内部元素赋值，当 {} 为 0 或者空白的时候数组被全部初始化为0
//
//  5. 清空数组
//      > 调用函数 void * memset(void *s, int c, size_t n);
//      > Linux 下使用 memset() 需要包含头文件 <csting> -> <string.h>
//
//  6. 复制数组
//      > memcpy() 函数可以把数组中全部的元素复制到另一个相同大小的数组
//        只适用于 C++ 基本数据类型
//      > 函数原型 void *memcpy(void *dest, const void *src, size_t n);
//      > Linux 下使用 memset() 需要包含头文件 <csting> -> <string.h>
//
// ---------------------------------------------------------------------
// > 数组指针
//
//  1. 指针的算数
//    - 将一个整形变量加1后, 其值将加1.
//    - 但是，将指针变量(地址的值) 加1 后, 增加的量等于它指向的数据类型的字节数
//      也就是数组中下一个元素的位置
//  2. 数组的地址
//    - 数组在内存中占用的空间是连续的
//    - C++ 将数组名解释为数组第 0 个元素的地址
//    - 数组第 0 个元素的地址和数组首地址的取值是相同的.
//    - 数组中第 n 个元素的地址是: 数组的首地址 + n
//    - C++ 编译器把 数组名[index] 解释为 *(数组首地址 + 下标)
//  3. 数组的本质
//    数组是占用连续空间的一块内存，数组名被解释为数组第一个元素的地址，
//    C++ 操作这块内存有两种方法，数组解释法和指针表示法，他们是等价的
//
//  4. 数组名不一定会被解释为地址
//    在多数情况下，C++ 将数组名解释为数组的第一个元素的地址，但是, 将
//    sizeof 元算符用于数据名时，将放回整个数组占用内存空间的字节数
//    __可以修改指针的值，但数组名是常量，不可修改__
//
// -------------------------------------------------------------------------
//  > 用作函数参数
//   1. 在函数中使用数组参数时，可以使用数组表示法，也可以使用指针表示法
//   2. 一维数组用于函数的参数时，只能传递数组地址，并且必须把数组长度传入函数，
//      除非数组中有最后一个元素的标志.
//   3. 在函数中，不要对指针名使用sizeof运算符，它不是数组名
//
//

// -------------------------------------------------------------------------
// 作为函数参数
// -------------------------------------------------------------------------

// 由于此时无法通过数组指针计算出长度，需要传入长度
void quick(int *arr, int len) {

  // 此时 arr 表示的是指针地址，无法计算出数组所占用的空间的大小
  cout << sizeof(arr) << endl;
  for (int i = 0 ; i < len; i++) {
    // 使用数组表示法
    cout << "arr[" << i << "] = " << arr[i] << endl;
    // 使用指针表示法
    cout << "*(arr +" << i  << ") = " << *(arr + i) << endl;
  }
}

void array_ptr_param() {
  int a[5] = {1, 3, 5, 9, 19};

  // 此时可以用数组名来计算所占用的空间
  cout << sizeof(a) << endl;

  quick(a,sizeof(a) / sizeof(int));
}

//-----------------------------------------------------------------------
// 指针相关
//-----------------------------------------------------------------------

void more_ptr() {

  int a[5] = {1, 2, 4, 45, 6};

  int *p = a;

  for (int i = 0; i < 5; i++) {
    cout << "*(p+" << i << ") = " << *(p + i)
         << endl; // 数组名[下标] 解释为 *(数组首地址+下标)
    cout << "p[" << i << "] = " << p[i]
         << endl; // 地址[下标] 解释为 *(地址 + 下标)
  }

  cout << "_________________________________" << endl;

  int *k = &a[2]; // 第三个元素的地址
  // 获取的地址使用起来就像是一个新数组
  cout << p[0] << endl; // 表示原数组的第三个元素
  cout << p[1] << endl; // 表示原数组的第四个元素
  cout << p[2] << endl; // 表示原数组的第五个元素
}

// linux 中如果数组越界并不会报错
// 但是越界的数据会出现一些不是预期的结果
void out_of_index() {

  int arr3[] = {1, 2, 3, 4, 3, 5};

  for (int i = 0; i < 8; i++) {
    cout << "a[" << i << "]= " << arr3[i] << endl;
  }
  int *p = arr3;

  // 即使我们将数组下标从负数开始计算，同样不会报错
  // 按内存地址排布, 可以看出 C++ 将索引结束为指针
  for (int i = -2; i < 8; i++) {
    cout << "*p(" << i << ") = " << (p + i) << endl;
  }
}

// 数组指针的本质
void ptr_tran_index() {

  int a[5] = {1, 3, 10, 4, 1};

  cout << "a val is : " << (long)a << endl;
  cout << "&a val is : " << (long)&a << endl;
  cout << "a[0] address val is : " << &a[0] << endl;
  cout << "a[1] address val is : " << &a[1] << endl;
  cout << "a[2] address val is : " << &a[2] << endl;
  cout << "a[3] address val is : " << &a[3] << endl;
  cout << "a[4] address val is : " << &a[4] << endl;

  int *p = a;

  cout << "p val is : " << (long)p << endl;
  cout << "&p val is : " << *p << endl;
  cout << "p[0] val is : " << *(p + 0) << endl;
  cout << "p[1] val is : " << *(p + 1) << endl;
  cout << "p[2] val is : " << *(p + 2) << endl;
  cout << "p[3] val is : " << *(p + 3) << endl;
  cout << "p[4] val is : " << *(p + 4) << endl;
}

void ptr_arr() {

  char a;
  cout << "sizeof(char) = " << sizeof(char) << endl; // 1 字节
  cout << "  > a 的地址是：" << (void *)&a << endl;
  cout << "  > a 的地址+1 是：" << (void *)(&a + 1) << endl;
  short b;
  cout << "sizeof(short) = " << sizeof(short) << endl; // 2 字节
  cout << "  > b 的地址是：" << &b << endl;
  cout << "  > b 的地址+1 是：" << (&b + 1) << endl;
  int c;
  cout << "sizeof(int) = " << sizeof(int) << endl; // 4 字节
  cout << "  > c 的地址是：" << &c << endl;
  cout << "  > c 的地址+1 是：" << (&c + 1) << endl;
  double d;
  cout << "sizeof(double) = " << sizeof(double) << endl; // 8 字节
  cout << "  > d 的地址是：" << &d << endl;
  cout << "  > d 的地址+1 是：" << (&d + 1) << endl;
}

//------------------------------------------------------------------------
// 数组使用相关
//------------------------------------------------------------------------

// 创建数组
void create_array() {

  // 声明一个数组
  int arr[3];
  string names[3];

  // 给数据赋值，数组下表从0 开始
  for (int i = 0; i < 3; i++) {
    arr[i] = i + 10;
    names[i] = "for-" + to_string(i);
  }
}

// 数组的数据内存
void mem_arr() {}

// 数据的初始化
void init_arr() {

  // 数组的初始化 1
  int arr1[3] = {2, 4, 5};
  // 初始化按照顺序赋值，不足的以 0 补全
  int arr2[5] = {3, 4, 5};
  // 不写数组长度，按照赋值的长度作为数组的长度
  int arr3[] = {1, 2, 3, 4, 3, 5};

  // 可以将数组直接赋予 0 作为初始值
  int arr5[5] = {0};
  int arr4[5] = {}; // 0 可以不写
  //

  for (int i = 0; i < (sizeof(arr3) / sizeof(int)); i++) {
    cout << arr3[i] << endl;
  }

  // 直接对数组进行循环输出数据
  for (int i = 0; i < 5; i++) {
    cout << "string:: = " << arr5[i] << endl;
  }
}

// 清空数组
// void * memset(void *s, int c, size_t n);
// Linux 下使用 memcpy() 需要包含头文件 <sting.h>
void clear_arr() {

  int arr3[] = {1, 2, 3, 4, 3, 5};

  for (int i = 0; i < (sizeof(arr3) / sizeof(int)); i++) {
    cout << arr3[i] << endl;
  }
  memset(arr3, 0, sizeof(arr3));

  for (int i = 0; i < (sizeof(arr3) / sizeof(int)); i++) {
    cout << arr3[i] << endl;
  }
}

// 复制数组
void copy_arr() {

  int arr3[] = {1, 2, 3, 4, 3, 5};
  // 声明一个大小一样的数组
  int arr4[(sizeof(arr3) / sizeof(int))];
  // 进行数据拷贝
  memcpy(arr4, arr3, sizeof(arr3));

  for (int i = 0; i < (sizeof(arr4) / sizeof(int)); i++) {
    cout << "arr3 = " << arr3[i] << ", arr4 = " << arr4[i] << endl;
  }
}

//
int main() {
  cout << "------------>> test of array <<-----------------" << endl;

  // 创建数组并赋值
  create_array();

  // 初始化数组
  init_arr();

  // 清空数组
  clear_arr();

  // 数组拷贝
  copy_arr();

  // 数组指针地址规律
  ptr_arr();

  // 数组指针的本质
  ptr_tran_index();

  // 数组的越界
  out_of_index();

  cout << "------------>> ends of array <<-----------------" << endl;
}
