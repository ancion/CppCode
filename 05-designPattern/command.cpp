#include <algorithm>
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

// 构建一个快捷指令的操作集合
//

// 1. 这里的快捷操作分为: 
//
//    - 获取天气消息
//      - 连接网络
//      - 调用天气服务
//    - 发送到微信
//      - 连接网络
//      - 调用微信服务
// ----------------------------------
//  底层的服务能力 (可以重用的原子能力)
//   - Network   - Weather    - Wechat

// ----------------------------------
//
// 命令模式的使用场景 
//
//   1. 指令的重放与回退
//   2. GUI 组件上事件触发时的任务管理等等

class Network {
  bool state = false;
public:
  void on() {
    if (!state) {
      state = true;
      cout << "Network has been connected." << endl;
    }
  }
};

struct WechatService {
  void sendMessage(const string &msg = "") {
    cout << "WechatService is sending message: " << msg << endl;
  }
};

struct WeatherService {
  void forecast() {
    cout << "Weather forecast: " << "It's sunnay in following 24 hours" << endl;
  }
};


// 抽象的指令结构
struct Command {
  virtual void execute() = 0;
  virtual ~Command() {}
};

// 对应的天气指令
class WeatherForecastCommand: public Command {
  Network& network;
  WeatherService& weather;
public: 
  WeatherForecastCommand(
    Network& network,
    WeatherService& weather 
  ): network(network), weather(weather) {}

  void execute() override {
    network.on();
    weather.forecast();
  }
};

// 对应的微信指令
class WechatCommand: public Command {
  // 微信指令与天气指令不同，具有一个动态变换的信息
  // 在命令模式中，通常以成员变量的方式来完成对应的命令中状态数据的存储
  // 在构建这条命令时传入这些参数
  // 从而保证公有的接口行为 execute() 的稳定性
  const string& msg;
  Network& network;
  WechatService& wechat;
public:
  WechatCommand(
    const string& msg,
    Network& network,
    WechatService& wechat
  ): msg(msg), network(network), wechat(wechat) {}

  void execute() override {
    network.on();
    wechat.sendMessage();
  }
};

// 组合快捷指令
class Shortcut {
  vector<Command*> commands;
public:
  Shortcut(initializer_list<Command*> commands) : commands(commands) {}

  void addCommand(Command* cmd) {
    commands.push_back(cmd);
  }

  void run() {
    for(const auto& cmd: commands) {
      cmd -> execute();
    }
  }
};

int main() {
  Network network;
  WechatService wechat;
  WeatherService weather;

  WechatCommand wechatCommand {
    "hello world", network, wechat
  };
  
  WeatherForecastCommand weatherForecastCommand {
    network, weather
  };

  Shortcut shortcut {
    &wechatCommand,
    &weatherForecastCommand
  };
  shortcut.run();
}

