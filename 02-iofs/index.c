// 文件操作
//
// 打开  fopen()
// 关闭  fclose()
// 读取  fread()
// 写入  fwrite()
// 文件指针偏移       fseek()
// 获取文件指针偏移量 ftell()
// 清空文件缓冲区     fflush()
//
//
// -------------------------------------------------------------
//  C 语言中的约定 
//
//    > 参数标记 _In_ 标识指针参数表示真实的参数
//    > 参数标记 _Out_ 标识指针参数表示该参数用于返回结果

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 *  文件打开
extern FILE *fopen (
    // 文件描述符
    const char *__restrict __filename,   
    // 文件的操作模式 
    // 操作文本文件: w (写入)  r (读取)  a (追加), 如果操作二进制文件添加 b 
    // wb : 打开文件并写入，文件不存在创建文件, 每次写入内容从首位开始，原有内容被覆盖
    // rb : 以读取模式打开文件，文件不存在返回 NULL, 否则返回文件句柄
    // ab : 以追加模式打开文件，文件不存在创建文件，存在则将文件指针偏移到最末尾
		const char *__restrict __modes       
)
__attribute_malloc__ __attr_dealloc_fclose __wur;

*/

// ---------------------------------------------------------------

/*
 * 文件写入
 * 返回写入成功的次数 (这个数字与下面写入文件的次数相等)
 * 写入的总字节数为 (写入的大小 x 写入的次数) 
 * 如果想要写入的返回值为写入的字节数, 则将写入大小设置为 1, 这时写入次数与返回值相同
 * 如果在写入 UTF-8 汉字的时候，你指定写入大小为 3，这时返回值与写入的汉字的个数相同
extern size_t fwrite (    
    const void *__restrict __ptr,   // 写入文件的内容指针
    size_t __size,                  // 写入文件的大小 
		size_t __n,                     // 写入文件的次数 
		FILE *__restrict __s            // 文件句柄
);
*/

// ---------------------------------------------------------------

/*
 * 文件读取
 * 返回读取成功的次数(这个数字与下面读取的次数相等)
 * 读取的总字节数为 (读取的大小 x 读取的次数) 
 * 如果想要读取的返回值为读取的字节数, 则将读取大小设置为 1, 这时读取次数与返回值相同
 * 如果在读取 UTF-8 汉字的时候，你指定读取大小为 3，这时返回值与读取到的汉字的个数相同
 *
extern size_t fread (
    void *__restrict __ptr,      // 读取到内容的缓存区
    size_t __size,               // 读取的大小
    size_t __n,                  // 读取的次数
    FILE *__restrict __stream    // 文件句柄
) __wur;

*/

// ---------------------------------------------------------------
/*
extern int fseek (
    // 文件句柄
    FILE *__stream, 
    // 偏移量
    long int __off, 
    // 从什么地方开始偏移 
    //    SEEK_SET(文件头), 
    //    SEEK_CUR (指针当前位置), 
    //    SEEK_END(文件末尾)
    int __whence    
);
*/

// ---------------------------------------------------------------

/*
 * 获取文件偏移量
 * 该计算从文件头开始计算
 * 可以借助 fseek 移动指针到末尾，然后使用 ftell 获取偏移量可以计算文件大小
extern long int ftell (
    FILE *__stream
) __wur;

*/

int main() {
  // 文件打开
  FILE *fd = fopen("./temp/fileop.txt", "rb");
  if (NULL == fd) {
    printf("file open failed !! \n");
    exit(-1);
  }
  printf("file open success. \n");

  // 文件写入 
  // char buffer[] = "今天天气真不错";
  // fwrite(buffer, 1, strlen(buffer), fd);
  
  // 把文件缓冲区中的内容立即写入到文件，清空文件缓冲区
  // fflush(fd)  
  
  // 文件读取
  char buf[1024] = { 0 };
  size_t ret = fread(buf, 1, 6, fd);
  // size_t ret = fread(buf, 3, 2, fd);
  // size_t ret = fread(buf, 6, 1, fd);
  printf("读取到文件内容: %s, 读取文件大小: %ld\n", buf, ret);

  // 文件指针偏移
  fseek(fd, 0 ,SEEK_SET);
  // 再次读取
  ret = fread(buf, 1, 6, fd);
  // size_t ret = fread(buf, 3, 2, fd);
  // size_t ret = fread(buf, 6, 1, fd);
  printf("读取到文件内容: %s, 读取文件大小: %ld\n", buf, ret);

  ftell(fd);

  // 文件关闭
  fclose(fd);
  return 0;

}
