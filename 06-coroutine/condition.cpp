

/**
*
* 条件变量
*
*/
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <iostream>
#include <thread>

namespace {
using std::condition_variable;
using std::cout;
using std::endl;
using std::lock_guard;
using std::mutex;
using std::queue;
using std::unique_lock;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

// 共享数据队列
queue<int> data_queue;

//互斥锁
mutex mtx;

// 条件变量: 用于在线程间传递 数据就绪的信号
condition_variable conv;

void consumer() {

  // 使用 unique_lock 自动管理互斥锁的加锁和解锁
  // wait 会在内部原子地释放锁并阻塞，直到被唤醒
  unique_lock<mutex> lock(mtx); 

  // wait第二个参数是谓词(predicate),防止虚假唤醒
  // 只有当 data_queue 非空时，wait 才会返回，继续执行后续逻辑
  conv.wait(lock, [] { return !data_queue.empty(); });

  cout << "Consumeed " << data_queue.front() << endl;
  data_queue.pop();

}

// 生产者线程函数，将指定值放入队列，并通知等待的消费者
void producer(int value) { 
  lock_guard<mutex> lock(mtx);

  sleep_for(milliseconds(2000));

  data_queue.push(value);

  // 通知一个正在等待的线程(此处即消费者)
  // 即使此时没有等待者，调用 notify_one() 也是安全的(无副作用)
  conv.notify_one();

}
} // namespace

auto main() -> int {

  // 启动消费者线程
  std::jthread cons(consumer);

  sleep_for(milliseconds(2));

  // 启动生产者线程
  std::jthread prod(producer, 24);

  return 0;
}
