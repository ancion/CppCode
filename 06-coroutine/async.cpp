#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include "../include/cppmod.h"

using std::async;
using std::future;
using std::vector;
using std::chrono::milliseconds;
using std::this_thread::get_id;
using std::this_thread::sleep_for;

using namespace std;


/**
  * C++ 11 异步编程 
  *
  *  future + async 为开发者提供了简单的异步编程模型, 可以轻松进行异步程序编码
  *  
  *  async 函数用来启动一个异步任务
  *  async 函数返回一个 future 对象
  *  future 对象可以用来获取异步任务的执行结果
  *
  */

namespace {
auto compute() -> size_t {
  sleep_for(milliseconds(2));
  std::hash<std::thread::id> hasher;

  auto threadId = get_id();

  auto threadHash = hasher(threadId);
  return threadHash;
}
} // namespace

void async_future() {

  vector<future<size_t>> vec;
  vec.reserve(20);

  for(int i = 0; i != 20; ++i) {
    // 强制使用异步启动 launch::async
    // 使用延迟启动 launch::deferred
    vec.emplace_back(async(launch::async, compute));
  }

  cout << "Doing other work.. " << endl;

  for (auto &f : vec) {
    cout << "other work thread id : " << f.get() << endl;
  }
}
