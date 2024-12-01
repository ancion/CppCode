#include <functional>
#include <iostream>
#include <list>
#include <string>

using namespace std;

/**
 * 场景: 当股票价格变化的时候，显示器和电子板上的显示内容都需要随之发生变化
 */



// ==================================================================
// 1. 强制对象耦合的写法(直接调用显示器和电子板的更新逻辑)
// ==================================================================
/*  
  * 

struct Monitor {
  void print(int msg) {
    cout << "Monitor: " << msg << endl;
  }
};


struct BiliBoard {
  void display(int msg) {
    cout << "Display: " << msg << endl;
  }
};


struct Stock {
  int price = 20;
  Monitor* monitor;
  BiliBoard* board;

  // 构造器
  Stock(Monitor* monitor, BiliBoard* board) : monitor(monitor), board(board) {}

  void setPrice(int price) {
    price = price;
    board-> display(price);
    monitor-> print(price);
  }
};

// 测试
int main() {

  Monitor monitor;
  BiliBoard board;
  Stock stock { &monitor, &board };
  stock.setPrice(10);
}
*/

// ==================================================================
// 2. 观察者模式
// ==================================================================


// 对应观察者的行为被抽离为一个接口, 所有观察者都实现这样的接口. 通过
// 复写接口方法的方式完成观察到变化时对应的行为
//
//
/*
struct Stock;

struct Observer {
  // 包含被观察的对象
  Stock* stock;
  Observer(Stock* stock);
  virtual ~Observer();
  virtual void update(int) = 0;
};


struct Monitor: Observer {
  // 构造器
  Monitor(Stock* stock) : Observer(stock) {}
  void print(int msg) {
    cout << "Monitor: " << msg << endl;
  }

  void update(int v) override {
    print(v);
  }
};

struct BiliBoard : Observer {
  BiliBoard(Stock* stock) : Observer(stock) {}
  void display(int msg) {
    cout << "BiliBoard" << msg << endl;
  }

  void update(int v) override {
    display(v);
  }
};

// 作为被观察的对象，需要有一个容纳观察者的容器，内部维护所有观察当前对象的
// Observer 的 实现类
// 1. attach(Observer*)  用于添加观测者
// 2. detach(Observer*) 用于删除观测者
// 3. notify(int) 用于通知观测者
//
struct Stock {
  int price = 20;

  // 观察者列表
  list<Observer*> observerList;

  // 添加观察者
  void attach(Observer* o) {
    observerList.push_back(o);
  }
  // 移除观察者 
  void detach(Observer* o) {
    observerList.remove(o);
  }

  // 通知每一位观察者
  void notify(int v) {
    for (auto observer: observerList) {
      observer -> update(v);
    }
  }

  void setPrice(int price) {
    price = price;
    notify(price);
  }
};

Observer::Observer(Stock* stk): stock(stk) {
  stock -> attach(this);
}

Observer::~Observer() {
  stock -> detach(this);
}

int main() {
  Stock stock;
  Monitor monitor { &stock };
  BiliBoard board { &stock };
  stock.setPrice(10);

}
*/

// ==================================================================
// 3. 观察者模式(抽离被观察者)
// ==================================================================

struct Observer;

struct Subject {
  list<Observer*> observerList;
  virtual void attach(Observer* o) = 0;
  virtual void detach(Observer* o) = 0;
  virtual void notify() = 0;
};

class Stock: public Subject {
  int price = 0;
public:
  int getPrice();
  void setPrice(int);
  void attach(Observer* o) override;
  void detach(Observer* o) override;
  void notify() override;
};

struct Observer {
  Subject* sub;
  Observer(Subject* sub);
  virtual ~Observer();
  virtual void update() = 0;
};

struct Monitor: Observer {
  Monitor(Subject* sub): Observer(sub) {}
  void print(int v) const {
    cout << "Monitor: " << v << endl;
  }
  void update() override {
    print(static_cast<Stock*>(sub)-> getPrice());
  }
};

struct BiliBoard: Observer {
  BiliBoard(Subject* sub): Observer(sub) {}
  void display(int v) {
    cout << "BiliBoard: " << v << endl;
  }
  void update() override {
    display(static_cast<Stock*>(sub) -> getPrice());
  }
};

int Stock::getPrice(void) {
  return price;
}

void Stock::setPrice(int v) {
  price = v;
  notify();
}

void Stock::attach(Observer* o) {
  observerList.push_back(o);
}

void Stock::detach(Observer* o) {
  observerList.remove(o);
}

void Stock::notify() {
  for(auto observer: observerList){
    observer -> update();
  }
}

Observer::Observer(Subject* sub) : sub(sub) {
  sub -> attach(this);
}

Observer::~Observer() {
  sub -> detach(this);
}

int main() {
  Stock stock;
  Monitor monitor { & stock };
  BiliBoard board  { & stock };
  stock.setPrice(10);
}


