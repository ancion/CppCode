#include <cstdio>
#include <cstring>
#include <iostream>
#include "../include/DataType.h"

// 避免不同类库中的包中出现同名函数，所以使用的时候使用using声明命名空间
// 使用的时候可以省略对应的命名空间
using namespace std;

/*
 * -------------------------------------------------------------
 * 结构体一般小写, 注意标点符号要写全, 结构体的声明要在使用之前
 * -------------------------------------------------------------
 */
struct student {
  char name[13];
  int age;
};

// 在定义结构体的同时定义变量 teacher
// 注意与前面添加 typedef 时的区别
struct Teacher {
  string name;
  int age;
  float score;
}teacher;

// 定义变量的同时进行初始化
struct Major {
  string name;
  int age;
}major = { "work", 2 };

void test_struct() {
  struct student s;
  strcpy(s.name, "macloo");
  s.age = 25;
  printf("%s %d", s.name, s.age);

  // 这也是一种直接初始化的方式
  struct student k = { "alex", 23 };

  // C++ 中前面的 struct 关键字可以省略
  // 等号也可以省略
  student l { "maria", 1 };

  // 先初始化，后续再赋值
  student p = {};
}


/*
 * -----------------------------------------------------------
 * 这是一个定义结构体的另一种方式，效果与 struct 相同
 * -----------------------------------------------------------
 * 其实就是使用 typedef 给结构体起个别名, 后续这个别名
 * 就相当于是 sdemo ==> struct Demo
 */
typedef struct Demo{
  char c1; // 1字节
  short s; // 2字节
  char c2; // 1字节
  int i;   // 4字节
} sdemo;

// 测试内存对齐的问题
void test_memory_align() {
  sdemo a; // 创建实例
  printf("%p\n", &a);
  printf("%p\n", &a.c1);
  printf("%p\n", &a.s);
  printf("%p\n", &a.c2);
  printf("%p\n", &a.i);
}

/**
* -------------------------------------------------------
*  结构体在 C++ 中的扩展
* -------------------------------------------------------
*  1. C++ 中 结构体被扩展为类的另一种表达方式,只是其中的内容都是public
*
*/
struct Woman {
  string name;
  string id;
  short gender;
  time_t birthday;

  // 定义函数
  const string& getName() const { return name; }
};


void struct_usage() {

  test_struct();
  test_memory_align();
}
