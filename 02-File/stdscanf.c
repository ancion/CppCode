#include <stdio.h>

/*
 *  C 语言中的位运算
 *
 *  - &  : 按位与(操作数对应的二进制位都为 1，则结果位为 1，否则为 0)
 *  - |  : 按位或(操作数对应的二进制位有一个为 1 则结果位为 1, 否则为 0 )
 *  - ^  : 异或 (操作数对应二进制位相同则结果位为 0，不同则为 1)
 *  - ~  : 取反 ~a = -(a + 1), ( 操作数对应二进制位为0，则结果位为1, 操作数为1，结果位 为 0)
 *  - >> : 右移 (a >> 3 = a / 2^3) 对应的计算公式为右移多少位置就是除上 2 的多少次幂
 *  - << : 左移(a << 3 = a * 2^3) 对应的计算公式为左移多少位置就是乘上 2 的多少次幂
 *
 */

// 位运算案例
int main(void) {

  int n1;
  int n2;
  int n3;
  int n4;
  int n5;

  // 打印提示信息, 输入的五个数字里面，必须两两相同，
  // 找出剩下一个没有配对的数字
  printf("输入5个数字: \n");

  scanf("%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5);

  int ans = n1 ^ n2;
  ans = ans ^ n3;
  ans = ans ^ n4;
  ans = ans ^ n5;

  printf("没有配对的数字是: %d\n", ans);
  return 0;
}