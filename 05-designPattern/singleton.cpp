#include <atomic>
#include <cstdlib>
#include <iostream>
#include <mutex>

// 版本1
class Singleton1 {

public:
  static Singleton1 *GetInstance() {
    if (_instance == nullptr) {
      _instance = new Singleton1();
    }
      return _instance;
  }

private:
  Singleton1(){}
  ~Singleton1() {
    std::cout << "~Singleton1()\n";
  }
  Singleton1(const Singleton1 &) = delete;
  Singleton1&operator = (const Singleton1&) = delete;
  Singleton1(Singleton1 &&) = delete;
  Singleton1&operator = (Singleton1 &&) = delete;

  // 这个对象的指针存储在全局静态区
  // 但是他指向的对象实例是存储在堆区，这里没有地方能够释放这个空间
  static Singleton1 * _instance;
};



// 版本2
// 添加了一个接口，用于在退出的时候可以调用析构函数，处理堆空间回收
class Singleton2 {

public:
  static Singleton2 * GetInstance() {
    if (_instance == nullptr) {
      _instance = new Singleton2();
      atexit(Destructor);
    }
    return _instance;
  }
private:
  static void Destructor(){
    if (nullptr != _instance) {
      delete _instance;
      _instance = nullptr;
    }
  }
  Singleton2() {}
  ~Singleton2() {
    std::cout << "~Singleton2()\n";
  }
  Singleton2(const Singleton2 &) = delete;
  Singleton2 & operator = (const Singleton2 &) = delete;
  Singleton2(Singleton2 &&) = delete;
  Singleton2 & operator = (Singleton2 &&) = delete;

  static Singleton2 *_instance;
};


// 版本1 和 版本 2 都是单线程模式，在多线程上是不安全的
// 版本3
class Singleton3 {

public:
  static Singleton3 * GetInstance() {
    // srd::lock_guard<std::mutex> lock(_mutex); 3.1
    if (_instance == nullptr) {
      // lock_guard 在离开作用域会自动释放锁
      std::lock_guard<std::mutex> lock(_mutex); // 3.2
      if (_instance == nullptr) {
        // 1. 分配内存
        // 2. 调用构造函数
        // 3. 返回对象指针
        _instance = new Singleton3();
        atexit(Destructor);
      }
    }
    return _instance;
  }

private:
  static void Destructor() {
    if (nullptr != _instance){
      delete _instance;
      _instance = nullptr;
    }
  }
  Singleton3() {}
  ~Singleton3() {
    std::cout << "~Singleton3() \n";
  }
  Singleton3(const Singleton3 &) = delete;
  Singleton3& operator = (const Singleton3&&) = delete;
  Singleton3(Singleton3 &&) = delete;
  Singleton3& operator = (Singleton3 &&) = delete;
  static Singleton3 *_instance;
  static std::mutex _mutex;
};


// 由于构建对象是多步操作
// 当构建过程中可能会返回未完全构建的实例，因此需要控制构建对象的原子性

class Singleton4 {
public:
  static Singleton4 * GetInstance() {
    // 禁止指令重排序
    Singleton4* tmp = _instance.load(std::memory_order_relaxed);
    // 内存屏障
    std::atomic_thread_fence(std::memory_order_acquire);
    if (tmp == nullptr) {
      std::lock_guard<std::mutex> lock(_mutex);
      tmp = _instance.load(std::memory_order_relaxed);
      if (tmp == nullptr) {
        tmp = new Singleton4;
        std::atomic_thread_fence(std::memory_order_release);
        _instance.store(tmp, std::memory_order_relaxed);
        atexit(Destructor);
      }
    }
    return tmp;
  }

private:
  static void Destructor() {
    Singleton4* tmp = _instance.load(std::memory_order_relaxed);
    if (nullptr != tmp){
      delete tmp;
    }
  }
  Singleton4(){}
  ~Singleton4(){
    std::cout << "~Singleton4()\n";
  }
  Singleton4(const Singleton4 &) = delete;
  Singleton4& operator = (const Singleton4&) = delete;
  Singleton4(Singleton4 &&) = delete;
  Singleton4& operator = (Singleton4 &&) = delete;
  static std::atomic<Singleton4*>_instance;
  static std::mutex _mutex;
};

// 版本5(C++11 标准生效)
//

class Singleton5 {
public:
  static Singleton5 * GetInstance() {
    // 利用了 C ++ 11 中静态局部变量是线程安全的这个特性
    // 这个代码也是懒汉模式的操作，只有用到了才会初始化
    // 因为静态变量存储在全局静态区，因此也不用关心析构函数
    static Singleton5 instance;
    return &instance;
  }
private:
  Singleton5(){}
  ~Singleton5(){
    std::cout << "~Singleton5() \n";
  }
  Singleton5(const Singleton5&) = delete;
  Singleton5 & operator = (const Singleton5&) = delete;
  Singleton5(Singleton5 &&) = delete;
  Singleton5 & operator = (Singleton5 &&) = delete;
};

// 为了提高复用性，封装复杂性，可以构建一个模板，
// 让需要单例模式的类继承这个模板，自动具备单例
template<typename T> class Singleton {
public:
  static T* GetInstance() {
    static T instance;
    return &instance;
  }
protected:
  Singleton(){}
  virtual ~Singleton() {
    std::cout << "~Singleton()\n";
  }
private:
  Singleton(const Singleton&) = delete;
  Singleton& operator = (const Singleton&) = delete;
  Singleton(Singleton &&) = delete;
  Singleton& operator = (Singleton &&) = delete;
};

// 需要实现单利模式的代码就只要继承之后私有构造函数即可
class DesignPattern : public Singleton<DesignPattern> {
  // 把父类设置为 friend, 则父类可以访问子类的私有对象
  friend class Singleton<DesignPattern>;
private:
  DesignPattern(){}
  ~DesignPattern(){
    std::cout << "~DesignPattern()\n";
  }
};

int main (int argc, char *argv[]) {
  // 版本 1 
  Singleton1 *s1 = Singleton1::GetInstance();
  // 堆上资源能够正常析构(在程序回收的时候会调用析构)
  Singleton2 *s2 = Singleton2::GetInstance();
  // 双检查锁，可能造成内存泄露(可能没有调用析构函数)
  Singleton3 *s3 = Singleton3::GetInstance();
  // 双检查锁，解决内存泄露的问题
  Singleton4 *s4 = Singleton4::GetInstance();
  // 基于静态局部变量的版本，利用了 C++11 的新特性
  Singleton5 *s5 = Singleton5::GetInstance();
  // 
  DesignPattern *s6 = DesignPattern::GetInstance();
  return 0;
}
