#pragma once

// 讨论类中的修饰符号
// > 1.static,  static 在类中表示静态变量,为类持有,不属于实例
// > 2.const,   const 修饰的变量不允许修改,修饰的方法不允许修改对象变量，mutable 的除外
// > 3.final,   final 修饰的类不允许继承，修饰方法不允许重写
// > 4.mutable, 允许修改(在使用 const 修饰的函数中可以修改这个变量)
// > 5.private, 未明确标注时默认都是 private, 对象外部无法访问
// > 6.public,  对象外部允许访问
// > 7.protected, 派生类可以访问
// > 


class Flag { 
private:
  // Create mutale variable
  // These can be modifed from a const member function
  mutable int accesses;
  bool flag;

public:

  // Constructor
  Flag(bool f) {
    accesses = 0;
    flag = f;
  }

  // const 修饰方法不允许修改对象变量
  virtual bool get_flag() const;

  // 静态类成员需要在类中申明，在类外进行初始化，该变量属于
  // 类，而不属于实例对象. 可以使用类和实例访问
  static int apoll;


  // c++11 之前，只允许 整形和枚举类型在类中直接初始化
  //    - 一旦涉及到 ODR-used 就需要在类外进行定义
  // C++11 之后, 
  // const static 定义的整形(char, int)、枚举和字面量(double, const char*)可以直接在类中初始化
  // 或者使用 constexpr 
  //
  const static int mifo = 100;


  // 只有 virtual 函数才可以使用 final 修饰 
  virtual void  set_flag(bool f) final { flag = f; };

};



// 不允许继承
class Peek final {};

// 不允许
// class Pub final : Peek {};
//
// 继承 Flag 之后，不允许被其他类继承
class Pub final : Flag {};


void oop_modifer();
