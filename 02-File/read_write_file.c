#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
//
// open 函数以某种模式打开一个路径，返回一个文件描述符
//
//  int open (const char *pathname, int flags)
//  int open (const char *pathname, int flags, node_t node)
//
//-------------------------------------------------------------
//
// close 关闭一个文件描述符
// int close(int fd)
//-------------------------------------------------------------
//
// read 文件读取 : 将一个文件描述符中读取内容到 buf 中
//
// read (int fd, void *buf, size_t count)
//
//
// write 文件写入
// write (int fd, )
//

int main() {

  // 可以同时指定多种模式
  int fd = open("./temp/hello.txt", O_CREAT | O_RDWR);
  // 返回的文件描述符，当文件不存在的时候，返回 -1
  printf("test open: %d \n", fd);
  // 申请一个内存缓冲区
  char *buf = malloc(20);
  // 返回读取的字节数量
  int r = read(fd, buf, 15);
  // 指定字符序列的结尾,
  buf[r] = '\0';

  // 输出打印的文件
  printf("read file content: %s\n", buf);

  // 释放内存缓冲区
  free(buf);
  // 关闭文件返回一个 int
  // 0 关闭成功，-1 关闭出现错误
  close(fd);
}
