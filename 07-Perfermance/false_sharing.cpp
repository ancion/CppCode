#include <cstddef>
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
// Tries to parallelize the work across multiple threads
// However, each core invalidates the other core copies on a write
// This is EXTREME example of poorly thought out code
void same_var() {
  atomic<int> a;
  a = 0;

  thread t1([&](){work(a);});
  thread t2([&](){work(a);});
  thread t3([&](){work(a);});
  thread t4([&](){work(a);});
}

// 使用不同的变量
// How well does it work if we use different atomic ints?
// Not that well! But look at the address! They all reside 
// on the same cache line. That means we have to false sharing!
// (We invalidate variables that aren't actually being accessed
// because they happen to be on the same cache line)
void diff_var(){
  atomic<int> a;
  a = 0;
  cout << "Address of a: " << &a << endl;

  atomic<int> b;
  b = 0;
  cout << "Address of b: " << &b << endl;

  atomic<int> c;
  c = 0;
  cout << "Address of c: " << &c << endl;

  atomic<int> d;
  d = 0;
  cout << "Address of d: " << &d << endl;

  // create fout thread and use lambda to launch work
  thread t1([&](){work(a);});
  thread t2([&](){work(b);});
  thread t3([&](){work(c);});
  thread t4([&](){work(d);});

  // Join the threads
  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

// cache line 64byte
// simple fix ,just make sure we can't get two atomic on the same cache line
struct alignas(64) aligned_type {
  atomic<int> a;
};

// No more invalidations, so our code should be roughtly the same as the 
void diff_line() {
  aligned_type a;
  a.a = 0;
  cout << "Address of a: " << & a << endl;

  aligned_type b;
  b.a = 0;
  cout << "Address of b: " << &b << endl;

  aligned_type c;
  c.a = 0;
  cout << "Address of c: " << &c << endl;

  aligned_type d;
  d.a = 0;
  cout << "Address of d: " << &d << endl;

  // Launch the four threads now using our aligned data
  thread t1([&](){ work(a.a);});
  thread t2([&](){ work(b.a);});
  thread t3([&](){ work(c.a);});
  thread t4([&](){ work(d.a);});

}



// 
// run with perf stat looking for instructions per cycle
// perf stat ./false_sharing

void test_false_sharing() {
  // single_thread();
  // same_var();
  diff_var();
}
