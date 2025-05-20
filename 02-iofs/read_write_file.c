#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
// read (int fd, void *buf, size_t count)
//
// write 文件写入, 将 buf 中内容写入到给定的文件描述符
// write (int fd, void *buf, size_t count)
//
//-------------------------------------------------------------
// 从文件的读写可以看出，当我们读取文件后写入文件，这时候文本中
// 指针的位置在读取数据结束的位置，写入的时候直接从这个位置开始
// 继续往文件中写入。而不是在文件末尾追加，也不是从文件头部写入
//
//
// 当想要把内容写入某个位置时, 可以使用 lseek 来调整文件指针位置
// int lseek(int fd, off_t offset, int whence)
//
//     > offset, 文件内指针的偏移量, 可以是负数，则往反方向偏移
//     > whence, 偏移量计算的方式
//        - SEEK_SET : 从文件头开始计算
//        - SEEK_CUR : 从文件指针当前所在位置计算
//        - SEEK_END : 从文件的末尾开始计算
//
//     > 返回当前文件指针偏移的位置,

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

  // 在数据写入之前将指针偏移到不同的位置，查看文件输出的效果
  // int s = lseek(fd, 0, SEEK_SET);
  // int s = lseek(fd, 2, SEEK_CUR);
  int s = lseek(fd, 0, SEEK_END);
  printf("cur seek position: %d\n", s);

  // 文件写入
  int w = write(fd, buf, strlen(buf));
  printf("write content len: %d\n", w);

  // 释放内存缓冲区
  free(buf);
  // 关闭文件返回一个 int
  // 0 关闭成功，-1 关闭出现错误
  close(fd);
}
