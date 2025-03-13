#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include "../include/cppmod.h"

using namespace std;

// C++ 中的字符串
//   C++ 中的 string 类型是一个封装的类，具有自动扩展, 不会出现
//   数组越界，野指针等问题, 底层是对C 类型的字符数组的封装
// --------------------------------------------------------------
// > C 风格的字符串
//   C语言中约定: 如果字符型(char)数组的末尾包含了空字符\0(也就是0)
//   那么数组中的内容就是一个字符串(C++遵循了这个约定)
//
//  1.因为字符串需要使用0结尾, 所以在声明字符数组的长度的时候，就要
//    预留一个字节用来存放 0
//    char name[21]  // 可以用阿里最多存放 20 个英文或 10 个中文字符
//
//  2.字符串的创建与初始化
//    char name[11]; // 不初始化，内存中的值是混乱的
//    char name[] = "hello";   // 自动补结尾0, 长度由初始化串决定
//    char name[11] = "hello"; // 自动补结尾0
//    char name[11] = { "hello" }; // 自动补结尾0
//    char name[11] { "hello" };  // 自动补结尾0，C++11 标准
//    char name[11] = {0} ;  // 所有字符初始化为 0
//
//  3.清空字符串 metset, 可以将字符数组中所有制清空
//
//    metset(name, 0, sizeof(name));
//
//  4.字符串的复制与赋值 strcpy()
//
//    char* strcpy(char* dest const char* src)
//
//     - 功能: 函数可以将 src 字符串拷贝至参数dest 所指的地址
//     - 返回值：返回参数dest 的字符串起始地址
//     - 赋值完字符串后，会在dest后追加0
//     - 如果 dest 所指的内存不够大，则会数组越界
//
//    char* strncpy(char* dest, const char* src, const size_t n)
//     - 把原字符串 src 的前 n 个字符复制到 dest中 返回 dest 起始字符的地址
//     - 如果 src 长度小于 n, 则拷贝完字符串后，在dest后追加 0, 直到 n 个
//     - 如果 src 长度大于 n, 就截取 src 前 n 个字符，不会在 dest 后追加 0.
//     - 如果参数 dest 所指的内存空间不够大，会导致数组越界
// -------------------------------
//  5.获取字符串的长度 strlen()
//
//    size_t strlen(const char* str)
//
//     - 功能：计算字符的有效长度，不包含 0
//     - 返回值：返回字符串的字符数
//     - strlen() 函数计算的是字符串的实际长度，遇到0结束
//
// -------------------------------
//  6.字符串拼接
//
//   char* strcat(char* dest, const char* src);
//
//    - 功能：将src中的字符串拼接到 dest 所指的字符串尾部
//    - 返回值：返回 dest 字符串的起始地址
//    - dest 最后原有的结尾字符0会被覆盖掉，并在连接后的字符串的尾部增加一个0
//      如果dest所指的内存空间不够大，会导致数组的越界.
//
//   char* strncat(char* dest, const char* src, );
//    - 功能：将 src 的前 n 个字符拼接到 dest 字符的尾部
//    - 返回：返回destt字符串的起始地址。
//    - 如果n大于等于字符串 src 的长度, 那么 src 全部追加到 dest 的尾部，如果
//      n 小于 src 字符串的长度，只追加src的前n个字符
//    - strncat 会将dest的最后一个0覆盖掉，并在字符追加完后再追加0
//    - 如果 dest 所指向的内存空间不够大，会导致数组越界
//
// ------------------------------
//  7.字符串的比较
//
//   int strcmp(const char *str1, const char *str2);
//
//   - 功能：比价 str1 和 str2 的大小
//   - 返回：相等返回0，str1 大于 str2 返回1, str1小于str2返回-1
//
//   int strncmp(const char* str1, const char* str2, size_t n);
//
//   - 功能: 比较 str1 和 str2 的前 n 个字符的大小.
//   - 返回: 相等返回0，str1 大于 str2 返回1，str1 小于 str2 返回-1;
//
//  字符串大小的比较是比较字符的ASCII 码的大小，从两个字符串的第一个字符
//  开始比较，如果比较不出大小，就比较第二个，如果全部的字符斗比较不出大
//  小，就返回0,表示两个字符串相等.
//
// -------------------------------
// 8.字符查找
//
//   char* strchr(const char* s, const int c)
//
//   - 返回一个指向在字符串 s 中第一个出现 c 的位置, 如果找不到则返回 0.
//
//   char* strstr(const char* str, const char* substr)
//
//   - 功能：检索字串在字符串中首次出现的位置
//   - 返回值：返回字符串 str 中第一次出现字串 substr 的地址，如果没有
//   检索在子串，则返回 0.
//
// -------------------------------
// 9. 用于 string 的表达式
//
//  可以把 C 风格的字符串用于包含了 string 类型的赋值拼接等表达式中.
//
//
// -------------------------------
// 10. 注意事项
//
//  > 字符串的结尾标识是0, 按照约定，在处理字符串的时候，会从起始位置开始搜索0
//    一直找下去，找到为止，不会检查是否数组越界
//  > 结尾标志后面的都是垃圾内容
//  > 字符串在每次使用前都要初化，减少错误的可能，不是第一个，是每一次
//  > 不要在子函数中对字符指针用sizeof运算，无法得到数组的长度，得道的是指针的
//    长度固定值 8
//  > 在 VS 中，如果要使用 C 标准的字符串操作，要在源代码的最上面添加
//    #include_CRT_SECURE_NO_WARNINGS
//
//------------------------------------------------------------------------------------
// String class operation
//
//
// > 字符串比较使用 == / != 判断
// > 拼接字符串可以使用 +
// >

// 字符串的比较

void compare_str() {}

// 字符串拼接
void concat() {

  char name[] = "hello";
  char value[13] = "world";

  strcat(value, name);

  cout << "value len: " << strlen(value) << endl;
}

// 字符串的长度
void len() {

  char name[] = "hello";
  char value[] = "天一生水";

  cout << "name len: " << strlen(name) << endl;
  cout << "name len: " << strlen(value) << endl;
}

void copy() {

  char name[11];
  // 拷贝函数，将字符串 hello 拷贝到 name 数组
  char *val = strcpy(name, "hello");
  // 返回的是首字符的地址, 解引用后是 h
  cout << "val = " << *val << endl;

  char value[11];

  // 赋值前 3 个字符到数组中, 这时候会导致赋值的 value 数组字符串没有以0结尾
  // 可能在使用的时候导致出现异常结果(建议数组使用前要初始化，或者清空)
  strncpy(value, "hello", 3);
}

// 演示 c 语言中的字符串表示方法
int c_style_string() {

  // 初始化方法(这种类型只有遇到0才会结束，所以没有赋值的时候可能会越界查找0)
  char name1[11]; // 可以存放十个字符(没有初始化的内部是一些垃圾值)
  // 初始化内容是 hello, 剩下的使用哪个0填充
  char name2[11] = "hello";
  // 数组初始化内容是 hello, 系统会自动加0, 数组长度由初始化字面量确定
  char name3[] = "hello"; // 长度是 6
  // 数组初始化内容是 hello, 系统会自动加0
  char name4[11] = {"hello"};
  // 数组初始化内容是 hello, 系统会自动加0
  char name5[11]{"hello"}; // C++ 标准
  // 数组全部元素初始化为 0
  char name6[11] = {0};

  // c 语言中定义一个字符串, 本质就是字符数组
  char s[] = "hello world";
  printf("%s\n", s);
  return 0;
}

// 清空字符串的两种方法
void clear_string() {
  char name[] = "hello";
  // 第一种
  memset(name, 0, sizeof(name));

  char value[] = "world";
  // 第二种，不规范，有隐患，不推荐
  value[0] = 0;
}

// 我们怎样验证 C++ 中的字符串遵循了C中关于字符数组中字符串的约定
void string_char() {

  string a = "XYZ";

  cout << "a[0] = " << (int)a[0] << endl;
  cout << "a[1] = " << (int)a[1] << endl;
  cout << "a[2] = " << (int)a[2] << endl;
  cout << "a[3] = " << (int)a[3] << endl;
}

// c++ 中字符串的使用方式
int str_test() {
  // const 用于定义一个常量，常量的值不能改变
  // c++ 中字符串是类，封装了C 语言的字符数组
  const string str = "Hello World!";

  cout << str.substr(0, 5) << endl;
  cout << str.substr(5) << endl;
  cout << str.length() << endl;

  // 用于接受命令行输入的一行值
  // cin 只能接收一个单词，一旦出现空格，空格之后值就收不到了
  // getline(cin, str);

  return 0;
}

// c++ 中的原始字面量
void str_face_val() {

  // 在C++中使用一些较长字符串中有较多字符需要转义的时候，比较冗余，容易出错
  string path1 = "C:\\Program File\\Microsoft OneDrive\\tail\\nation";
  // 使用 R"()" 这样的字面量在括号中只需要写原始字符即可，不需要转义
  string path2 = R"(C:\Program File\Microsoft OneDrive\tail\nation)";
  // 还可以给这个扩号内的字符做一个标签, 标签需要成对出现,
  // 标签不作为字符串的一部分
  string path3 = R"path(C:\Program File\Microsoft OneDrive\tail\nation)path";

  cout << path1 << endl;
  cout << path2 << endl;
  cout << path3 << endl;
}

void multi_line_str() {

  // 多行字符串可以使用 \ 来拼接
  string content = "\
    <no>001</no> \
    <name>Alex</name>\
    <age>19</age>\
    <weight>90</weight>\
    ";
  cout << content << endl;

  // 如果字符串的内容都是常量，拼接的时候可以不用书写 +, 也可以分成多行
  string con = "That's maybe the most importtant "
               "Once you know you will never be that"
               "face one fact";
  cout << con << endl;
}

void str_func() {
  // capacity >= size
  string s1 = "hello world!!";
  cout<< "size: " << s1.size() << ", capacity: " << s1.capacity() << endl;

  // resize 
  s1.resize(5);
  cout<< "size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
}


void str_usage() {
  cout << "---------------test of string --------------------" << endl;
  // C 类型的字符串
  c_style_string();

  // 清空字符串
  clear_string();

  // 字符串复制或者赋值 strcpy()
  copy();

  // 字符的长度
  len();

  // 字符串拼接
  concat();

  // 验证C++遵循了C关于字符串定义
  string_char();

  //
  str_test();

  str_func();

  // 字符串字面量
  str_face_val();

  // 字符串的多行表示法
  multi_line_str();

  cout << "---------------test of string --------------------" << endl;
}
