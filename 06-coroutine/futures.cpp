/**
* Cpp 并发编程中，Future 是一个非常关键的组件，表示未来可能获得的值，即某个异步操作的结果，
*     Future 本身可以作为异步操作结果的占位符，主线程可以在适当的时候获取到结果; 
*     这样就可以更优雅，更加安全, 高效地从子线程向主线程传递异步结果。
* 
*  std::async 用以快速开启一个异步的任务, 并返回一个 `future` 对象，可以根据参数指定一个策略.
*      - `launch::async` : 强制异步执行, 内部创建线程并将任务的返回值包装进 `future` 
*      - `launch::deferred` : 延迟执行 
*
*  future 配合 async 为 Cpp 开发者提供了一种高效且直观的异步编程模型
*  隐藏了底层线程管理，代码更易读，易维护。足以应对常用的并发编程。
*
*/

#include <chrono>
#include <functional>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

using std::async;
using std::cout;
using std::endl;
using std::future;
using std::hash;
using std::thread;
using std::chrono::milliseconds;
using std::this_thread::get_id;
using std::this_thread::sleep_for;

using namespace std;

namespace {

auto compute() -> size_t { 
  // 模拟耗时任务
  sleep_for(milliseconds(2));
  hash<thread::id> hasher;

  auto thrdId = get_id();
  // 
  auto threadHash = hasher(thrdId);
  // 
  return threadHash;
}

}

auto main() -> int {

  vector<future<size_t>> vecs; 
  vecs.reserve(20);

  for (int i = 0; i < 20; ++i) {
    vecs.emplace_back(async(compute));
  }
  cout << "Doning other work" << endl;

  for (auto &fut : vecs) {
    cout << fut.get() << endl;
  }

  return 0;
}
