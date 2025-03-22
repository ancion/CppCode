#pragma once

// ------------------------------------
// function template
// ------------------------------------

#include <cctype>
template <typename T>
T add(const T a, const T b) {
  return a + b;
}

template<typename T, typename U>
U add(const T a, const U b) {
  return a + b;
}


// ------------------------------------
//  template class
// ------------------------------------

template<typename T>
class Point {
private:
  T x;
  T y;
public:
  Point(T x, T y): x(x), y(y) {}
  Point(): x(0), y(0) {}
  T getX() const { return x; } 
  T getY() const { return y; }
};



// 为模板中的某些类型指定特殊的实现方式
template <typename T>
class Container {
private:
  T element;
public:
  Container(const T e): element(e){}
  T inc() { return ++element; }
};


// -------------------------------------------------
// 使用 template<> 表明这是模板的特化
// 并非是重复定义了一个类
template<>
class Container<char> {
private:
  char element;
public:
  Container(const char e): element(e) {}
  char uppercase() { return std::toupper(element); }
};

void template_usage();
