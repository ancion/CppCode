# 编译指令

- 编译中间文件

```sh
g++ -c CppAdd.cpp
g++ -c CppAddWrapper.cpp
```

- 构建静态库

```sh
ar -r libCppAddWrapper.a CppAdd.o CppAddWrapper.o
```

- 编译可执行文件

```sh
gcc -o main main.c -L. -lCppAddWrapper -lstdc++ 
```
