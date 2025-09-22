// c++ 中常量定义
//
// 宏常量 (一般在main 函数上声明，使用全大写的字符命名J)
// 语法 #define cname value
//
// const type name  或者 type const name  均可
#include <iostream>

#define PI 3.14
#define MONTH 12

void const_usage() {

  std::cout << "PI values is: " << PI  << std::endl;

  // const 定义的常量(应该被理解为只读变量，理论上只是进行了标记，可以通过其他方式修改)
  // 可以在程序的任意地方定义常量, 一旦定义之后不可再赋值(在 C 中可以通过指针绕过限制修改days 值)
  const int days = 7;

  std::cout << "one week have :" << days << " days" << std::endl;
}

// C++ 中将指针的的操作更加规范起来, 将 const 修饰分为顶层和底层
// 顶层 const 修饰的是指针本身，底层 const 修饰的是指针指向的数据
// 有如下的几条规律
// 1. 当执行对象拷贝操作时，常量的顶层 const 不受什么影响，而底层 const 需要保持一致.
//

void test_const() {

  // const 表示 a 是常量，不能赋予其他值
  const int a = 10;
  int b = a;

  // 既是顶层(修饰变量本身)，也是一个底层(指向的底层值不可修改)
  const int *const p = new int(10);

  // 顶层 const 可以忽略，底层 const 需要保持一致 
  //  顶层不一致, 底层也不一致
  //  int *p1 = p;

  // 顶层一致，底层不一致
  // int *const p2 = p;

  // 底层一致即可
  const int* p3 = p;


  // 但是 &a 是有一个底层 const 的，(引用看成是值的别名), 它是不可变的
  // 如果没有const 我们则可以通过引用修改, 这就破坏了原本 a 的 const 定义
  const int *c = &a;


  // 引用是别名，不是拷贝, 不执行拷贝操作
  // const int &r1 = 20;
  const int &r1 = a;
  
  // r2 是对象的别名，但是 40 是一个临时值，没有对象，更没有别名的概念
  // 但是如果 使用 const 修饰了 &r2, 则右侧可以使用任何类型
  // int &r2 = 40;

  // r2 作为 a 的别名，需要报错 const 一致，否则可以通过 r2 修改值
  // int &r2 = a;

  // &r1 在右侧的时候，& 可以忽略，其实就是 r1, 只是使用了这个别名
  // int &r3 = &r1;  // (const 不一致) ( int &r3 = a;  int &r3 = &a; int &r3 = r1 都是等价的)
}

// 1. 引用不是对象且不进行拷贝，不满足上述的操作
// 2. 常量引用如果在左侧，右侧可以是任何类型
// 3. 非常量引用= 常量 （错误）
// 4. 引用如果在等号右侧，可以忽略 `&`
// 5. 非常量 = 常量引用 (正确)
//
