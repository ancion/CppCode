#pragma
#include "./Shape.h"
#include <iostream>

class ShapeGenerator {
protected:
  string m_shapeName;
public:
  virtual Shape* createShape()=0;
  virtual string& getShapeName() {
    return m_shapeName;
  }
};


class RectangleGenerator: public ShapeGenerator {
public:
  RectangleGenerator() {
    m_shapeName = "矩形";
  }
  virtual Shape* createShape() override {
    float width, height;
    cout << "请输入矩形的宽: ";
    cin >> width;
    cout << "请输入矩形的高: ";
    cin >> height;

    return new Rectangle(width, height);
  }
};


class CircleGenerator: public ShapeGenerator {
public:
  CircleGenerator() {
    m_shapeName = "圆";
  }
  virtual Shape* createShape() override {
    float r;
    cout << "请输入圆的半径: ";
    cin >> r;
    return new Circle(r);
  }
};

class TriangleGenerator:public ShapeGenerator {
public: 
  TriangleGenerator() {
    m_shapeName = "三角形";
  }
  virtual Shape* createShape() override {
    float a, b, c;
    cout << "请输入三角形的第一条边: ";
    cin >> a; 
    cout << "请输入三角形的第二条边: ";
    cin >> b;
    cout << "请输入三角形的第三条边: ";
    cin >> c; 
    return new Triangle(a, b, c);
  }
};
