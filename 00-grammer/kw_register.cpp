#include <time.h>
#include <stdio.h>

// C 语言中 register 关键字的作用
//
// > 如果一些变量使用频繁，为了提高执行效率，允许将局部变量的值
//   放入到 CPU 寄存器中.(这里是允许放入 CPU 寄存器，不一定会被放入)
// > 添加了此修饰符，不能使用 & 取放在 register 上的变量的地址, 因为其可能被放入寄存器
//   使用其地址是不安全的

int main(int argc, char *argv[]){


  // 根据是否有 REGISTER 这个宏的定义，来决定是使用 register 还是不使用
  // 看打印的结构验证 register 在程序中的作用.
  //
  // > 使用 register 时候编译参数 
  // gcc  register.c -D REGISTER
  // > 不使用 register 时候的编译参数
  // gcc register.c

  long long i =0, sum = 0;

#ifdef REGISTER
    register long long value = 10;
#else 
    long long value = 10;
#endif /* ifdef  REGISTER */

  
  time_t start = time(NULL);
  time_t end = start + 5;

  while (time(NULL) < end) {
    sum += value;
    i++;
  }
  printf("i=%lld\n", i);

  return 0;
}
