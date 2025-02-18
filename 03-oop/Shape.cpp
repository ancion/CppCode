#include "../include/Factory.h"
#include <vector>


void oop_shape_game() {

  vector<ShapeGenerator*> genlist {
    new RectangleGenerator(),
    new CircleGenerator(),
    new TriangleGenerator()
  };

  while(true) {
    cout << "请选择需要计算的图形" << endl;
    int i = 0;
    for(i = 0; i < genlist.size(); i++) {
      cout << i << ":" << genlist[i]->getShapeName() << ","  << endl;
    }
    cout << i << ":" << "退出" << endl;

    unsigned int choice;
    cin >> choice;

    if (choice == i) {
      return;
    }
    if (choice > i) { 
      cout << "没有这个选项，请重新选择, " << endl;
    }

    Shape* pShape = genlist[choice] -> createShape();
    float area = pShape -> area();
    float perimeter = pShape -> perimeter();
    cout << "========================================= " << endl;
    cout << "面积: " << area  << endl;
    cout << "周长: " << perimeter << endl;
    cout << "========================================= " << endl;
  }
}
