# 编译函数定义与函数的实现 (使用 c 编写)
hello: hello.c hello.h
	gcc -c hello.c -o hello.so

# 在 cpp 文件中引用了 c 编写的函数与引用
maincpp: main.cpp hello.so
	# gcc 中无法编译使用
	# gcc -x c++ main.cpp hello.so -lstdc++ -o main
	# g++ 编译 (c 文件编写的时候做了特殊处理,利用了g++ 中 __cplusplus 的定义)
	g++ main.cpp hello.so -o main

# 证明当前的 hello.h 文件在定义上是没有问题的
# 在 c 文件中可以被正确引用并编译执行
mainc: main.c hello.so
	gcc main.c hello.so -o mainc

