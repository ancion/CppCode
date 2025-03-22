#pragma once

// 讨论类中的修饰符号
// > 1. static,  static 修饰的变量只能在类中使用
// > 2. const,   const 修饰的变量不允许修改,修饰的方法不允许修改对象变量，mutable 的除外
// > 3. mutable, 允许修改(在使用 const 修饰的函数中可以修改这个变量)
// > 4. private, 未明确标注时默认都是 private, 对象外部无法访问
// > 5. public,  对象外部允许访问
// > 6. protected, 派生类可以访问
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
  virtual bool get_flag() const;
};
