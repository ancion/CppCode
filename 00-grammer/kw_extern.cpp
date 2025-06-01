
// 
// 1. C 语言中可以使用 extern 来引入其他文件中定义的变量和函数，
//    (一个变量被多个文件引入并操作,会引发数据冲突，难以维护, 建议在架构中不要使用)
// 2. C++ 中多使用 extern "C" 来完成 C++ 对 C 语言代码的兼容性调用


// 当 kw_static.cpp 中定义了 int b = 10; 一起编译的时候可以正常编译通过
extern int c;
// 引入 kw_static.cpp 中定义的函数 
extern void static_func(void);

// 无法引入，因为 kw_static.cpp 中定义的函数 fun 是 static 修饰的
// extern void fun(void);

// 用于兼容 C 语言, 使用 g++ 编译器的时候告知编译器，这个部分编译，链接适用 C 语言的规则
extern "C" {
  
}
