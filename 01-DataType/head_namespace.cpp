#include <cstdio>
#include <cstring>
#include <iostream>

// 头文件的引入，主要是为了让程序更加简洁, 头文件的作用就是将
// 一部分定义在其他文件中的内容插入到声明 #include<> 的地方
//  ==> #include<stdio.h> == #include<cstdio>
//  ==> #include<string.h> == #include<cstring>


// 避免不同类库中的包中出现同名函数，所以使用的时候使用using声明命名空间
// 使用的时候可以省略对应的命名空间
using namespace std;

// 结构体一般小写, 注意标点符号要写全
// 结构体的声明要在使用之前
struct student {
  char name[13];
  int age;
};

/*
 * ------------------------------------------
 * 不使用命名空间的写法
 * ------------------------------------------
int main(void)
{
   int n ;
   std::cin >> n;
   std::cout << "Hello World!" << ++n << std::endl;
   return 0;
}
*/

/*
 * ------------------------------------------
 * 使用命名空间的写法
 * ------------------------------------------
 */
int main(void) {
  int n;
  cin >> n;
  // "\n" == endl
  cout << "Hello World!" << ++n << endl;
  return 0;
}
