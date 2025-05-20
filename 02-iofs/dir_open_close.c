
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
//
//
// 目录操作
//
//  > 打开目录
//    DIR *opendir(const char* path)
//
//  > 读取文件夹中的内容, 获取目录打开之后的指针，或者打开失败 -1
//    struct dirent *readdir(DIR *dirp);
//       struct dirent {
//           ino_t          d_ino;       /* Inode number */
//           off_t          d_off;       /* Not an offset; see below */
//           unsigned short d_reclen;    /* Length of this record */
//           unsigned char  d_type;      /* Type of file; not supported
//                                          by all filesystem types */
//           char           d_name[256]; /* Null-terminated filename */
//       };
//
//
//  > 关闭文件目录
//    int closedir(DIR *dirp);
//
// ------------------------------------------------------------------------
//
//  > 切换目录
//    int chdir(const char* dirp)
//
//  > 创建一个新的目录
//    int mkdir(const char* dirp, mode_t mode)
//
//  > 删除一个目录
//   int rmdir(const char* dirp)
//
//
// ------------------------------------------------------------------------
//
//  > 获取当前工作目录
//   int getcwd(char *buf, size_t size);
//
//

// 读取文件夹的内容
void read_dir() {

  // 创建目录
  mkdir("../temp/c_app", 0755);

  // 打开
  DIR *temp_dir = opendir("../temp");
  while (1) {
    // 读取
    struct dirent *d = readdir(temp_dir);
    if (!d) {
      break;
    }
    printf("name : %s\n", d->d_name);
  }

  // 删除多余的目录
  rmdir("../temp/c_app");

  // 关闭
  closedir(temp_dir);
}

void operation_dir() {

  // 修改目录
  chdir("temp");

  // 获取工作目录
  char buf[1024];
  getcwd(buf, 1024);

  puts(buf);
}

int main(int argc, char *argv[]) {
  read_dir();
  operation_dir();
  return EXIT_SUCCESS;
}
