#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
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
//  > difftime() 用来进行两个时刻的时间差, 返回秒数
// 
//    double difftime(time_t t1, time_t t0) 
//      - t1 - t0 的时间差 (返回秒数)
//
//  > localtime() 一个时间戳返回的详细信息
//
//     struct tm *localtime(const time_t timep)
//
//     // 返回的数据结构体
//       struct tm {
//          int tm_sec;    /* Seconds (0-60) */
//          int tm_min;    /* Minutes (0-59) */
//          int tm_hour;   /* Hours (0-23) */
//          int tm_mday;   /* Day of the month (1-31) */
//          int tm_mon;    /* Month (0-11) */
//          int tm_year;   /* Year - 1900 */
//          int tm_wday;   /* Day of the week (0-6, Sunday = 0) */
//          int tm_yday;   /* Day in the year (0-365, 1 Jan = 0) */
//          int tm_isdst;  /* Daylight saving time */
//       };
//


void local() {

  time_t t;
  time(&t);

  struct tm *day = localtime(&t);

  printf(
    "%d-%d-%d %d:%d:%d", 
         1900 + day->tm_year, 
         1 + day->tm_mon, 
         day->tm_mday, 
         day->tm_hour, 
         day->tm_min, 
         day->tm_sec
  );
}

void diff() {

  time_t a;
  time(&a);

  for (int i = 0; i < 3; i++) {
    // 休眠 1s
    sleep(1);
  }

  time_t b;
  time(&b);

  // b - a 的秒数
  double s = difftime(b,a);
  printf("执行时间: %lf\n", s);

}

void show_time() {

  // 获取当前的时间戳
  time_t t;
  t = time(NULL);
  printf("time: %ld\n", t);

  // 以文本方式显示时间
  char *s = ctime(&t);
  printf("stime: %s\n", s);
}

int time_usage() {
  show_time();
  diff();
  local();
  return 0;
}
