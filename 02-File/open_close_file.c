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

int main() {

  // 可以同时指定多种模式
  int fd = open("./temp/hello.txt", O_CREAT | O_RDWR);
  // 返回的文件描述符，当文件不存在的时候，返回 -1
  printf("test open: %d \n", fd);
  // 关闭文件返回一个 int
  // 0 关闭成功，-1 关闭出现错误
  close(fd);
}
