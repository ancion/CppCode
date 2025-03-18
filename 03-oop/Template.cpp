
#include "../include/Template.h"
#include <iostream>

using namespace std;

void template_usage() {
  cout << add(10, 20) << endl;
  cout << add(10.5, 20.0) << endl;
  cout << add(10, 20.2) << endl;

  // --------------------------------

  auto a = Point(1, 10);
  cout << "(x: "  <<  a.getX() << ", y: " << a.getY() << ")" << endl;
  auto b = Point(10.2, 10.5);
  cout << "(x: "  <<  b.getX() << ", y: " << b.getY() << ")" << endl;

  // --------------------------------

  auto o = Container<int> (10);
  cout << "container<int>: " << o.inc() << endl;

  auto c = Container<char> ('B');
  cout << "container<char>: " << c.uppercase() << endl;

}




