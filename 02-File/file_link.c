
/*
 * 文件的链接 
 *
 *  > 硬链接 (link), 在文件浏览器中显示的是原始文件的地址, inode 中文件的引用数量会增加,
 *    原始文件和硬链接都是有效，删除任何一个，不会影响其他文件，所有的都删除才会被清理
 *
 *    int link(const char *oldpath, const char *newpath)
 *
 *
 *  > 软连接 (symlink), 没有创建文件 新的 inode 索引不会增加文件的引用数量，因此没有限制创建数量
 *    当原始文件被删除，所有的软连接都将失效
 *
 *    int symlink(const char *targat, const char *source)
 *
 *  > 解链接(unlink) : 解除文件链接
 *   
 *    - 一个符号链接，解链接之后就是删除了这个符号链接, 
 *    - 
 *
 */

#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]){

  // 创建硬链接
  link("../temp/file.txt", "../temp/file_hardlink.txt");
  symlink("../temp/file.txt", "../temp/file_symbliclink.txt");

  // 
  unlink("../temp/file_hardlink.txt");
  unlink("../temp/file_symbliclink.txt");

  return EXIT_SUCCESS;
}
