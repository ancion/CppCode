#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <utime.h>
#include <time.h>

//
// stat 函数主要用于获取文件/文件夹的信息
//
// int stat(const char *path, struct stat *buf)
//
//   > path 参数是要获取信息的文件路径
//   > buf 参数是一个指向 struct stat 的指针，用于存储文件信息
//   > 返回值为整形，0 表示函数执行成功，-1 表示失败
//|------------------------------------------------------------------
// stat 结构体在 linux 中用于表示文件的元数据信息，其成员包括
//
//   > dev_t     st_dev       : 文件所在设备的ID
//   > ino_t     st_ino       : 文件的索引节点号
//   > mode_t    st_mode      : 文件的类型和访问权限
//   > nlink_t   st_nlink     : 文件的硬链接数量
//   > uid_t     st_uid       : 文件的所有者的用户 ID
//   > gid_t     st_gid       : 文件的所有者的组 ID
//   > dev_t     st_rdev      : 如果文件时一个特殊文件，则为设备 ID
//   > off_t     st_size      : 文件的大小，以字节为单位
//   > blksize_t st_blksize   : 文件系统 I/O 缓冲区的大小
//   > blkcnt_t  st_blocks    : 文件所占用块数量
//   > timespec  st_atime     : 文件的最后访问时间
//   > timespec  st_mtime     : 文件的最后修改时间
//   > timespec  st_ctime     : 文件的状态信息最后修改时间
//   > timespec  st_birthtime : 文件的创建时间(有些系统支持,
//   但不是所有系统都有这个字段)
//
// 这些成员提供了有关文件的各种信息，可以帮助在程序中更好的处理文件
// 
//
// > utime() : 修改文件的访问时间和修改时间, 这个函数可以在不打开文件
//             的情况下修改这个时间
// 
//    int utime(const char *filename, const struct utimbuf *times);
//       struct utimbuf {
//            time_t actime;       /* access time */
//            time_t modtime;      /* modification time */
//       };
// 
//
//


void stat_file(){
  // 构建一个结构体，用于接收对应的 stat 函数执行的结果
  struct stat s;

  stat("./temp/hello.txt", &s);

  printf("size: %ld\n", s.st_size);
  printf("size: %d\n", s.st_mode);
  time_t t = s.st_atime;
  printf("atime: %ld\n", t);
  printf("block: %ld\n", s.st_blocks);

}

void modify_time() {

  time_t t;
  time(&t);

  struct utimbuf buf = {
    .actime = t,
    .modtime = t - 200
  };

  utime("../temp/a.log", &buf);

}


int main() {
  // stat_file();
  modify_time();
  return 0;
}
