/**
* 
* Promise 是一个承诺，允许在某个线程中设置一个值，然后在另外一个线程可以通过与之关联的 Future 中获取到这个结果, 
* 从而实现线程之间的结果传递; Promise 的使用方式非常直观，
*   - 创建一个 Promise 对象 
*   - 调用它的成员函数 `get_future()` 获取到与之关联的 `Future` 对象
*   - 之后在子线程中调用 `set_value()` 来兑现承诺 
*   - 主线程中则可以通过 `future.get()` 来阻塞等待并获取到这个结果 
*/

#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

using std::exception;

namespace {

using std::promise;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

void worker(promise<int> prom) {

  // 模拟耗时计算
  sleep_for(milliseconds(2));

  // 兑现承诺
  prom.set_value(42);
}

} // namespace

auto main() -> int {

  try {
    promise<int> prom;

    auto fut = prom.get_future();

    // prom 移动傲其他线程，不要再使用
    // jthread 在离开作用域之后自动 join
    std::jthread jthrd(&worker, std::move(prom));

    cout << "Result: " << fut.get() << endl;

  } catch (exception &e) {
    cerr << e.what();
  }
}
