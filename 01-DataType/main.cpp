#include<iostream>
#include<cstring>
#include<cstdio>

// 头文件的引入，主要是为了让程序更加简洁
//  ==> #include<stdio.h> == #include<cstdio>
//  ==> #include<string.h> == #include<cstring>


// 不适用命名空间的写法
// int main(void)
// {
//    int n ;
//    std::cin >> n;
//    std::cout << "Hello World!" << ++n << std::endl;
//    return 0;
// }


// 避免不同类库中的包中出现同名函数，所以使用的时候使用using声明命名空间
// 使用的时候可以省略对应的命名空间
using namespace std;

int main(void)
{
    int n ;
    cin >> n;
    // "\n" == endl
    cout << "Hello World!" << ++n << endl;
    return 0;
}


int string(){
    // const 用于定义一个常量，常量的值不能改变
    const string str = "Hello World!";

    cout << str.substr(0,5) << endl;
    cout << str.substr(5) << endl;
    cout << str.length() << endl;

    // 用于接受命令行输入的一行值
    // cin 只能接收一个单词，一旦出现空格，空格之后值就收不到了
    getline(cin,str);

    return 0;
}

int boolean(){
    // cpp 中的布尔值，只有两个值，true 和 false
    // C中是没有布尔值的，只有0和1
    // cpp 在进行逻辑判断的时候，会将一切非零数字转换为true，0转换为false
    int a = 1;
    int b = 0;
    int c = -1;
    bool flag = true;
    bool flog = false;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << flag << endl;
    cout << flog << endl;
}



