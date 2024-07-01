#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
//
// 时间戳 1970-01-01 00:00:00 往后的毫秒数, (long int)
//
//
//  > `time_t` 是一个用于表示时间的数据类型，它在 c 语言中广泛使用
//     可以把它看作一个整数类型，用于存储时间戳
//
//  > time() : 用于获取当前的日历时间，返回纪元以来经过的秒数
//
//   time_t time(time_t *tloc)
//     - 参数为 NULL 时获取到当前时间
//     - 参数不为 NULL 则将获取的当前时间赋值给参数对应的指针
//
//  > ctime() 处理一个时间，返回时间的字符串表示方式
//
//   char *ctime(const time_t *timep)
//     - 参数为时间戳指针
//     - 返回时间的字符表示方式
//
//
//
//
//
//

int main() {

  time_t t;

  t = time(NULL);
  printf("time: %ld\n", t);

  char *s = ctime(&t);
  printf("stime: %s\n", s);
  return 0;
}
