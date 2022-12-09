#include <stdio.h>

#include <cstdio>
#include <cstring>
#include <iostream>

// 避免不同类库中的包中出现同名函数，所以使用的时候使用using声明命名空间
// 使用的时候可以省略对应的命名空间
using namespace std;

// 演示 c 语言中的字符串表示方法
int c_str() {
  // c 语言中定义一个字符串,
  char s[] = "hello world";
  printf("%s", s);
  return 0;
}

// c++ 中字符串的使用方式
int str_test() {
  // const 用于定义一个常量，常量的值不能改变
  const string str = "Hello World!";

  cout << str.substr(0, 5) << endl;
  cout << str.substr(5) << endl;
  cout << str.length() << endl;

  // 用于接受命令行输入的一行值
  // cin 只能接收一个单词，一旦出现空格，空格之后值就收不到了
  // getline(cin, str);

  return 0;
}

int main() {
  c_str();
  str_test();
  return 0;
}
