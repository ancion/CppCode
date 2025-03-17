// define 叫做宏定义，语法格式
//
//  #define 名称 值
//
//  1. 结尾没有分号
//  2. 和 #include 一样，在预处理阶段执行，文本替换
//  3. 值可以时数字，表达式，代码语句等
//  4. 宏定义的好处，便于程序的阅读和维护

//
//  查看预处理的结果，可以观测到宏的内容被替换到具体的文本
//
//  gcc -E define.c -o define.i
//

// 下面是一些宏定义

#define PI 3.14
#define MAX 50
#define NULL 0
#define EOF -1
#define ERROR -1
#define M 3 + 2
#define N (3 + 2)

#include <stdio.h>
#include <stdlib.h>

void simple() {
  int a[MAX] = {0};
  a[0] = 100;
  printf("%d\n", a[0]);
  printf("%d\n", M * 2);
  printf("%d\n", N * 2);
}

//
// 2. 没有值的宏的定义
//
//  > 这种宏的定义是用于条件编译的, 配合其他的预处理指令来检测这个宏是否被定义
//  > 可以在编译时通过 -D 选项来定义宏, 以决定是否启用某一段代码, 这时候宏定义的值默认为 1
//  > 当你想要比较宏定义的值，可以使用 #if __DEBUG__ == 1 这样的形式来判断
//
//
// 下面这个示例表示，如果定义了 DEBUG 的宏的时候，
// printf 函数打印的时候会打印出来如下的内容
//
// #define DEBUG
// #ifdef DEBUG
//
// printf("%s : This error is in %s on line %d.\n",
//        __FUNCTION__, // 这个宏可以返回函数名称
//        __FILE__,     // 这个宏可以返回文件名称
//        __LINE__);    // 这个宏可以返回行号
//
// #endif

// 对这个宏定义进行取消或者打开的时候，编译运行出不一样的结果
#define __DEBUG__

void condition_compile() {
#ifdef __DEBUG__
  printf("%s : This error is in [%s] on line [%d].\n",
         __FUNCTION__, // 这个宏可以返回函数名称
         __FILE__,     // 这个宏可以返回文件名称
         __LINE__);    // 这个宏可以返回行号
#endif
}

// 3. 宏定义中符号的意义
// # 此符号可以在宏定义中用来展示变量文本 例如
#define printvar(x) printf("%s is %d\n", #x, x) // 则第一个%s 处显示的是传入的实参的名称

// ## 两个连用的时候表示连接符号
// 主要用于定义一些连续变量的时候, 例如一个月的每一天
#define DATE(x) int day##x
#define DATE_VALUE(x) day##x


void test() {
  DATE(1) = DATE_VALUE(x);
}

// 4. 宏函数的定义
// #define 函数名(参数列表) 函数体
//

int main(int argc, char *argv[]) {

  simple();
  condition_compile();
  return EXIT_SUCCESS;
}
