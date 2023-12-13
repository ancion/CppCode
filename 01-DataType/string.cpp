#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;



// C++ 中的字符串
// -----------------------------------------
// > 字符串比较使用 == / != 判断
// > 拼接字符串可以使用 + 
// > 

// 演示 c 语言中的字符串表示方法
int c_str() {
  // c 语言中定义一个字符串, 本质就是字符数组
  char s[] = "hello world";
  printf("%s", s);
  return 0;
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
void str_face_val(){

  // 在C++中使用一些较长字符串中有较多字符需要转义的时候，比较冗余，容易出错
  string path1 = "C:\\Program File\\Microsoft OneDrive\\tail\\nation";
  // 使用 R"()" 这样的字面量在括号中只需要写原始字符即可，不需要转义
  string path2 = R"(C:\Program File\Microsoft OneDrive\tail\nation)";
  // 还可以给这个扩号内的字符做一个标签, 标签需要成对出现, 标签不作为字符串的一部分
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


int main() {
  c_str();
  str_test();
  return 0;
}
