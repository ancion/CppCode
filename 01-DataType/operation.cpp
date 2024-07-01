// c++ 中的运算

#include <iostream>
#include <ostream>
#include <string>

// 基本运算
void basic_operaton() {

  // + - * / % 是基本运算，
  // 基本运算时有几点注意事项
  // - 整数进行除法运算，如果分母为 0，程序将异常退出
  // - 浮点数进行除法运算时，如果分母为 0.0，得到 inf(infinite) 无穷大
  // - 零个整数进行除法运算时，将会舍去小数部分，得到一个整数
  // - 整数与浮点数进行除法运算时, 得到的结果时浮点数，
  // - 在整数前面添加（float) 或 （double) 可以直接将整数转换为浮点数
  // - 取余运算只适用于整数之间，分母也不能为 0

  double x = 0.0;
  int y = 10;
  int z = 0;

  // 除 浮点数 0.0 会得到无限大
  double r = y / x;
  std::cout << r << std::endl;

  // 异常退出
  // int k = y / z;
  // std::cout << k << std::endl;
  //

  int p = 3;
  // 整数除法会自动忽略小数部分
  std::cout << y / p << std::endl;

  // 添加（double/float) 会将整数转换为浮点数
  std::cout << (double)y / p << std::endl;
}

// 自增或者自减
void auto_incre_decre() {

  int i = 0;
  // 测试自增自减
  std::cout << i++ << ++i << i-- << --i << std::endl;
}

// 赋值运算符
void equals() {

  // +=
  // -+
  // *=
  // /=
  // %=

  // 字符串只能使用等号赋值，上述的这些运算都是不支持使用在字符串上的
  // 浮点数不支持 `%=` 操作
  // 等号（=) 赋值运算符可以连续使用
  int a;
  int b;
  int c;
  a = b = c = 1000;
  // 如果赋值运算符两边操作数的类型不同，C++ 将自动转换数据类型，可能会丢失精度
  // 也可能会超出取值范围，如果不能转换成功，编译器会报错.

  // 初始化赋值，在申明变量的时候赋予初始值
  // 已下三种是相同的含义
  int x = 10;
  int y = (20);
  int z(30);
  std::cout << x << y << z << std::endl;

  // C++ 11 标准中有新的写法, 在 linux 平台编译的时候需要添加 -std=C++11
  int p = {10};
  int o{20};
  std::cout << o << p << std::endl;
}

// 关系运算，主要得到的是 bool 类型的结果 (得到 0 / 1)
// 主要表示的是逻辑关系
void relation() {

  //  !=
  //  ==
  //  <
  //  <=
  //  >=
  //  >
  //
  int a = 10;
  int b = 20;
  // 关系运算符的两边可以是数值，也可以是表达式
  // 用 std::cout 来输出的时候，关系表达式需要添加括号，
  // 运算表达式可以不用添加
  std::cout << "a >= b : " << (a > b) << std::endl;
  // 关系运算也适用于字符串类型，字符串常用的关系运算是 `==` `!=`
  // ,其他的基本用不上
  std::string x = "alex";
  std::string y = "alox";
  std::cout << "x == y : " << (x == y) << std::endl;
}

// 逻辑运算
void logic() {

  //  &&
  //  ||
  //  !
  // 逻辑运算符的两边可以都是数值，也可以是表达式
  // std::cout 输出逻辑运算的时候需要使用括号, 否则无法编译
  //
  bool a = false;
  bool b = true;

  std::cout << "a && b" << (a && b) << "a || b" << (a || b) << " ! b" << (!b)
            << std::endl;
}

// c++ 中可以使用 逗号来连接多个表达式，表达式从左向右执行
void comma() {

  // 虽然表示式可以使用逗号隔开写在一行，但是实际开发过程中
  // 一般只会把相关的表达式写在一行，不相关的表达式不会写在一行
  // 逗号隔开的用法多见于用在 变量的声明与赋值的过程中.

  // 声明变量后赋值
  int a, b;
  a = 10, b = 10;

  // 声明两个变量，一个赋值一个不赋值
  int x = 10, y;

  // a, b 都赋值为 2, a * 2 后没有接收处理
  b = a = 2, a * 2;
  std::cout << "first b: " << b << std::endl;

  // 先计算括号内的值，a 被赋值为 2，然后 a * 2 = 4, 最后将 4 赋值给 b
  b = (a = 2, a * 2);
  std::cout << "second b: " << b << std::endl;
}

// 运算的顺序
void ops_order() {

  // 赋值运算的结合律是先右后左
  int a, b, c;
  a = b = c = 20;

  // 赋值表达式作为一个表达式，它本身也是有运算结果的，它的结果就是等号右边表达式的值
  std::cout << "b = 10 语句的值是: " << (b = 10) << std::endl;

  // 数组下标取值的运算级别最高，其次是使用 （）
  // 为了防止运算语义的不清晰，建议多使用括号来表达运算的优先级
  // 括号可以提高所有运算符的优先级
}

int main() {

  // 基本运算
  basic_operaton();

  // 自增自减
  auto_incre_decre();

  // 赋值运算符
  equals();

  // 关系运算符
  relation();

  // 逻辑运算
  logic();

  // 逗号运算符
  comma();

  // 运算的顺序
  ops_order();

  // 位运算

  return 0;
}
