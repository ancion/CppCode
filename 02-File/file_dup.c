#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// 当出现多段代码中需要使用使用同一个 fd 对象是可以使用 dup 函数构建一个副本
// (这两个fd具有相同的 文件打开模式，和文件指针位置)
//
// int nfd = dup(int fd)
//
// 得到的是一个新的文件描述符，与原来的文件描述符并不相等
//
//
// dup2(int old_fd,int new_fd)
//
// > dup2 与 dup 之间的区别是，dup2 有第二个参数,可以将 old_fd 复制给 new_fd
//   * 如果 new_fd 是一个有效的 fd (打开的其他文件)
//      - 当 old_fd 和 new_fd 相同的时候，不会进行任何操作
//      - 当 old_fd 和 new_fd 不同的时候，再重用之前会先关闭 new_fd
//      这个文件描述符,
//
//   * 如果 new_fd 不是一个有效的 fd, 直接进行复制
//
//   ((
//        这样做的目的就是因为当我们dup 的时候不会直接关闭new_fd, 如果其他函数中
//        使用 open() 打开了同一个文件，是无法操作的.
//        dup2 会先关闭这个 new_fd, 然后才会将 old_fd 复制给 new_fd
//   ))
//
//   * 返回新的 fd, 如果失败返回 -1
//

int main() {

  int fd = open("./temp/hello.txt", O_RDWR);

  // int nfd = fd;
  // 与直接赋值一个新的变量的不同
  int nfd = dup(fd);

  // 这里查看文件描述符并不相同，关闭一个不会影响另一个
  printf("old: %d,  new: %d \n", fd, nfd);

  char buf[10];
  read(fd, buf, 1);
  puts(buf);

  // 复制出来之后，使用新获取的文件描述符进行读取
  // 可以看到，这时候读取的位置已经发生了改变
  char buf2[10];
  read(nfd, buf2, 1);
  puts(buf2);

  close(fd);
  close(nfd);

  return 0;
}
