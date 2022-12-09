#include <cstdio>
#include <cstring>
#include <iostream>

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

void test_struct() {
  struct student s;
  strcpy(s.name, "macloo");
  s.age = 25;
  printf("%s %d", s.name, s.age);
}

/*
 * -----------------------------------------------------------
 * 这是一个定义结构体的另一种方式，效果与 strct 相同
 * -----------------------------------------------------------
 */
typedef struct {
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

int main() {

  test_struct();
  test_memory_align();

  return 0;
}
