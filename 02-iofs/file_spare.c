
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// 
// 开辟一个空洞文件, 
//  > 前面空出一段空白空间(lseek, 设置文件内读写指针的位置)，
//    最终写入一些内容(必要的操作，否则为一个空文件不占用空间)
//
//
int main() {

  // 可以同时指定多种模式
  int fd = open("../temp/hello.txt", O_CREAT | O_RDWR);
  // 返回的文件描述符，当文件不存在的时候，返回 -1
  printf("test open: %d \n", fd);

  lseek(fd, 1024, SEEK_SET);
  write(fd, "A", 1);

  // 关闭文件返回一个 int
  // 0 关闭成功，-1 关闭出现错误
  close(fd);

  return 0;
}
