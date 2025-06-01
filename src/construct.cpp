
// C++ 中 struct 和 class 是一样的, struct 被封装为公开的类
// 内部所有的变量，函数都是 public 的

#include <iostream>

using namespace std;

struct A {
  // 结构体不申明构造函数，默认有一个无参的构造函数
};

struct B {

  // 1.当存在有参构造的时候，默认构造函数就不存在了, 
  //   使用 default 关键字来申明默认的构造函数

  // 保留默认的构造函数
  B() = default;

  // 2.这里不能是有默认参数的构造, 存在构造函数歧义
  // B(int x = 1) {}
  B(int x) { 
    cout << "B(int x)" << endl; 
  }
};

struct C {
  // 表明删除了默认的构造函数
  C() = delete;

  C(int x = 10) {
    cout << "C(int x)" << endl;
  }
};

int struct_construct() {
  A a;
  B b(2);
  C c(1);

  return 0;
}
