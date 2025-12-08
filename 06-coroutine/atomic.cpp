
#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>


// 
// 无任何保证多线程安全的措施
//
namespace {

int count1 = 0;

void increment_no() {

  for (int i = 0; i < 100000; ++i) {
    ++count1;
  }
}

auto normal_mutli_increment() {

  {
    std::jthread t1(increment_no);
    std::jthread t2(increment_no);
  }
  std::cout << "Final count: " << count1 << std::endl;
}
} // namespace

// 
// 使用互斥锁
//
namespace {
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::high_resolution_clock;

std::mutex mtx;
int count2 = 0;

void increment_lock() {

  for (int i = 0; i < 10'000'000; ++i) { 
    mtx.lock();
    ++count2;
    mtx.unlock();
  }
}

auto normal_mutli_increment_lock() {
  auto start = high_resolution_clock::now();
  {
    std::jthread t1(increment_lock);
    std::jthread t2(increment_lock);
  }
  auto end = high_resolution_clock::now();
  std::cout << "Final count: " << count2
            << ", cost: " << duration_cast<milliseconds>(end - start).count()
            << std::endl;
}
} // namespace


// 
// 使用原子类
//
namespace {

std::atomic<int> count3(0);

void increment_atomic() {
  for (int i = 0; i < 10'000'000; ++i) {
    count3.fetch_add(1);
  }
}

auto normal_mutli_increment_atomic() {
  auto start = high_resolution_clock::now();
  {
    std::jthread t1(increment_atomic);
    std::jthread t2(increment_atomic);
  }
  auto end = high_resolution_clock::now();
  std::cout << "Final count: " << count3
            << ", cost: " << duration_cast<milliseconds>(end - start).count()
            << std::endl;

  // 原子类是否是无锁结构，取决于是否是简单类型
  std::cout << "is lock free: " << (count3.is_lock_free() ? "true" : "false") << std::endl;
}
} // namespace

// 自定义类型是否是无锁
namespace  {

struct Ato {
  int a;
  int b;
  int c;
  int d;
};

auto atoislock() {

  std::atomic<Ato> ats;

  std::cout << "is lock free: " << (ats.is_always_lock_free ? "true" : "false") << std::endl;

}
} // namespace


auto main() -> int {
  // normal_mutli_increment();
  // normal_mutli_increment_lock();
  // normal_mutli_increment_atomic();
  atoislock();
}
