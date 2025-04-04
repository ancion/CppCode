#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

//
// 伪内存共享
//

void work(atomic<int>& a) {
  for(auto i = 0; i < 10000; i++) {
    a++;
  }
}

// 单线程操作
void single_thread() {
  atomic<int> a;
  a = 0;

  work(a);
  work(a);
  work(a);
  work(a);
}


// 相同的变量，由于存在多线程之间的竞争关系
// 大部分的时候线程都在等待其他线程操作结束
void same_var() {
  atomic<int> a;
  a = 0;

  thread t1([&](){work(a);});
  thread t2([&](){work(a);});
  thread t3([&](){work(a);});
  thread t4([&](){work(a);});
}


// 使用不同的变量
