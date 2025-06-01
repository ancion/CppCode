
#include <cstddef>
#include <ctime>
#include <iostream>
#include <chrono>

using namespace std;


void chrono_run() {

  // 一天的时间秒数
  chrono::duration<int, ratio<60 * 60 * 24>> oneday(1);

  // 今天
  chrono::system_clock::time_point today = chrono::system_clock::now();

  // 时间运算
  // 明天
  chrono::system_clock::time_point tomorrow = today + oneday;

  // 获取时间表示与输出
  time_t t = chrono::system_clock::to_time_t(today);
  cout << "today is : " << ctime(&t) << endl;

}

int main() {

  chrono_run();
}

