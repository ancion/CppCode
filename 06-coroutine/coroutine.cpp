#include "../include/cppmod.h"
#include <coroutine>
#include <functional>
#include <iostream>
#include <memory>
#include <thread>


using namespace std;

// ----------------------------------------------------------
// 多重回调
// ----------------------------------------------------------

class IoReader {
public:
  void BeginReader(const function<void(int)> & callback) {
    thread thread([callback] () {
      this_thread::sleep_for(chrono::seconds(1)); // 模拟耗时操作
      int value = 1;
      callback(value);
    });
    thread.detach();
  }
};

void PrintInt() {
  IoReader reader1;
  int total = 0;
  reader1.BeginReader([&total](int value) {
    total += value; // 第一次相加

    IoReader reader2;
    reader2.BeginReader([&total](int value){
      total += value;

      IoReader reader3;
      reader3.BeginReader([&total](int value) {
        total += value;
        cout << total << endl;
      });
    });
  });
}

// 多种回调构成的回调地狱问题, 
// 可以将回调代码转换为协程方式，类似同步代码的写法，可以有效提高代码的阅读性
void nested_callback () {
  PrintInt();
}

// ------------------------------------------------------------------
// co_await 
// ------------------------------------------------------------------


// Awaitable 对象用来协程的挂起行为
// 必须要实现如下的三个函数
class IntReader {
public:
  bool await_ready() {
    cout << "awaitable_ready: " <<  this_thread::get_id() << endl;
    return false;
  }
  void await_suspend(coroutine_handle<> handle) {
    cout << "awaitable_suspend: " <<  this_thread::get_id() << endl;
    // thread thread([this, handle]() {
      this_thread::sleep_for(chrono::seconds(1));
      value_ = 1;
      handle.resume();
    // });
    // thread.detach();
  }
  int await_resume() {
    cout << "awaitable_resume: " <<  this_thread::get_id() << endl;
    return value_;
  }
private:
  int value_{};
};

// Promise 对象, 控制协程的行为
// 是协程函数的返回值需要具备的内容
class Task {
public:
  class promise_type {
  public:
    Task get_return_object() { 
      return Task{coroutine_handle<promise_type>::from_promise(*this)};
    }
    suspend_always initial_suspend() noexcept { return {};}
    suspend_always final_suspend() noexcept { return {};}
    void unhandled_exception() {}
    void return_void() {}
  };

  coroutine_handle<promise_type> handle;
  Task(coroutine_handle<promise_type> handle): handle(handle) {}
  ~Task() {if(handle) handle.destroy();}
};


Task fibo() {

  cout << "Coroutine start....." << endl;
  IntReader reader1;
  int total = co_await reader1;

  IntReader reader2;
  total += co_await reader2;

  IntReader reader3;
  total += co_await reader3;

  cout << "FibVoid: " << total << endl;
}


// -------------------------------------------------------------------
//  co_return
// -------------------------------------------------------------------

class TaskValue {
public:
  struct promise_type {
  public:
    // 创建对象的时候初始化智能指针
    promise_type(): value_(make_shared<int>()) {}

    TaskValue get_return_object() {
      cout << "Promise_create: " <<  this_thread::get_id() << endl;
      return TaskValue{value_};
    }

    suspend_never initial_suspend() noexcept {
      cout << "initial_suspend: " <<  this_thread::get_id() << endl;
      return {};
    }
    suspend_always final_suspend() noexcept { 
      cout << "final_suspend: " <<  this_thread::get_id() << endl;
      return {};
    }
    void unhandled_exception() { terminate(); }

    void return_value(int value) noexcept {
      cout << "Promise_return: " <<  this_thread::get_id() << endl;
      *value_ = value;
    }

  private:
    shared_ptr<int> value_;
  };

  TaskValue(const shared_ptr<int>& value): value_(value) {}
  int GetValue() {
    return *value_;
  }

private:
  shared_ptr<int> value_;
};


TaskValue fibValue() {

  cout << "调用协程函数内部执行1: " <<  this_thread::get_id() << endl;

  IntReader reader1;
  int total = co_await reader1;
  cout << "调用协程函数内部执行2: " <<  this_thread::get_id() << endl;

  IntReader reader2;
  total += co_await reader2;
  cout << "调用协程函数内部执行3: " <<  this_thread::get_id() << endl;

  IntReader reader3;
  total += co_await reader3;

  co_return total;
}

// -------------------------------------------------------------------
// 生成器 co_yield
// -------------------------------------------------------------------

// 定义一一个生成器，就是一个协程类型
template<typename T>
struct FibonacciGenerator {
  // 一个 Coroutine 对象必须有一个Promise 对象用来处理协程行为
  // Promise 对象定义了协程返回值或者处理异常的行为
  struct promise_type {
    T current_value;
    suspend_always yield_value(T value) noexcept {
      current_value = value; // 保存当前值
      return {};             // 暂停协程
    };
    suspend_never initial_suspend() noexcept  { return {}; } //  一开始不暂停
    suspend_always final_suspend() noexcept { return {}; }  // 结束暂停
    void return_void() noexcept {}; // 无返回值
    void unhandled_exception() noexcept { terminate(); } 
    FibonacciGenerator get_return_object() {
      return FibonacciGenerator<T>{ coroutine_handle<promise_type>::from_promise(*this) };
    }
  };

  // 协程句柄，用于控制协程恢复或者销毁
  coroutine_handle<promise_type> handle;
  explicit FibonacciGenerator(coroutine_handle<promise_type> h): handle(h) {};
  ~FibonacciGenerator() { if(handle) handle.destroy(); } // 清理协程
 

  T next() {
    handle.resume(); // 恢复协程执行
    return handle.promise().current_value; // 返回生成的值
  }

  // 检查是否结束
  bool done() { return handle.done();}
};

FibonacciGenerator<int> fibogen(int max_count) {
  int a = 0, b = 1;
  while (max_count-- > 0) {
    co_yield a;
    int temp = a;
    a = b;
    b = temp + b;
  }
}

void generator() {
  auto fib = fibogen(10);
  while (!fib.done()) {
    cout << fib.next() << endl;
    sleep(1);
  }
}


// -------------------------------------------------------------------
// Coroutine
// -------------------------------------------------------------------

void coroutine() {

  // 多重回调函数
  // nested_callback();

  // 生成器的例子
  // generator();

  // co_void
  Task s = fibo();
  s.handle.resume();

  // co_return;
  // cout << "主程序: " <<  this_thread::get_id() << endl;
  // TaskValue x = fibValue();
  // cout << "FibValue: " <<  x.GetValue() << endl;

  this_thread::sleep_for(chrono::seconds(5));
}
