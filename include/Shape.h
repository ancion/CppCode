// 1. 第一种方式，使用宏定义
// #ifndef SHAPE_H
// #define SHAPE_H
//
// 2.为了避免头文件重复导入的问题
//   使用 #pragma once
#pragma once

#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.1415926


class Shape {
public:
  virtual float area() = 0;
  virtual float perimeter() = 0; 
  virtual ~Shape(){}
};


// 继承,可以使用访问修饰符来设置继承时的访问控制权限
// 默认是 private, 一般使用的是 public
class Circle: public Shape {
private:
  float m_r;
public:
  virtual float area() override {
    return PI * m_r * m_r;
  }
  virtual float perimeter() override {
    return 2 * PI * m_r;
  }
  Circle(float radius){
    m_r = radius;
  }
  virtual ~Circle(){}
};

class Triangle: public Shape {
private:
  float m_a;
  float m_b;
  float m_c;
public:
  virtual float area() override {
    float p = (m_a + m_b + m_c) / 2;
    return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
  }
  virtual float perimeter() override {
    return m_a + m_b + m_c;
  }
  Triangle(float a, float b, float c) {
    m_a = a;
    m_b = b;
    m_c = c;
  }
  virtual ~Triangle(){}
};

class Rectangle: public Shape {

private: 
  float m_width;
  float m_height;
public:
  virtual float area() override {
    return m_width * m_height;
  }
  virtual float perimeter() override {
    return (m_width+m_height) * 2;
  }
  Rectangle(float width, float height) {
    m_width = width;
    m_height = height;
  }
};


void oop_shape_game();

// #endid
