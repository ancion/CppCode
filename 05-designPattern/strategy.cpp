// 策略模式
//

#include <iostream>
#include <memory>

using namespace std;

// 车辆的制动系统的抽象, 以方便不同的车型可以使用不同的制动系统
// 灵活的扩展更多的制动系统
struct Brake {
  virtual void brake() = 0;
  virtual ~Brake() {}
};

struct ABSBrake: Brake {
  void brake() override {
    cout << "ABS Brake Applied" << endl;
  }
};

struct SimpleBrake: Brake {
  void brake() override {
    cout << "Simple Brake Applied" << endl;
  }
};

struct Car {
  // 汽车的模型中应该要包含有一个指定系统
  shared_ptr<Brake> breakSystem;
  // 在构建汽车实例的时候应该具象化一个制动系统实例
  Car(shared_ptr<Brake> brake): breakSystem(brake) {}
};

struct Sedan: Car {
  Sedan(shared_ptr<Brake> brake): Car(brake) {}
};

struct SUV: Car {
  SUV(shared_ptr<Brake> brake): Car(brake) {}
};

struct Race: Car {
  Race(shared_ptr<Brake> brake): Car(brake) {}
};

int main () {
  Sedan sedan {
    make_shared<ABSBrake>()
  };
  sedan.breakSystem -> brake();
  return 0;
}
