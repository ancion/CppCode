#include <iostream>
#include <string>
#include "../include/cppmod.h"
#include "../include/Vehicle.h"

using namespace std;


// even this function be implementatio of base class
// const string Vehicle::getDescription() const {
  // return "Vehicle: license [ " + license + " ] year: [" + to_string(year) + "]";
// }

const string Car::getDescription() const {
  return "Car: license [ " + license + " ] year: [" + to_string(year) + "] style: [" + style + "]";
}

const string Truck::getDescription() const {
  return "Truck: license [ " + license + " ] year: [" + to_string(year) + "] bed_length: [" + to_string(bed_length) + "]";
}

void class_polymorphism() {

  cout << "---------------- class polymorphism -----------------" << endl;

  // Create two different classes
  Car car1("ABC - 123", 2004,  "Four-Door");
  Truck truck1("456-DEF", 2014, 7);


  // abstract method `getDescription = 0` make it not instantiable
  //
  // Vehicle vehicle1("NAHA", 2004);
  // cout << vehicle1.getDescription() << endl;

  Vehicle *v1;

  v1 = &car1;
  cout << v1 -> getDescription() << endl;

  v1 = &truck1;
  cout << v1 -> getDescription() << endl;

}

void class_inherite() {
  cout << "---------------- class inherite -----------------" << endl;
  // Create two different classes
  Car car1("ABC - 123", 2004,  "Four-Door");
  Car car2("VANITY", 2018, "Two-Door");

  // print out license of using common method from base class 
  cout << "car1 License: " << car1.getLisence() << endl;
  cout << "car2 License: " << car2.getLisence() << endl;

  // print out the year of each car
  cout << "car1 Year: " << car1.getYear() << endl;
  cout << "car2 Year: " << car2.getYear() << endl;

  // print out the style
  cout << "car1 Style: " << car1.getStyle() << endl;
  cout << "car2 Style: " << car2.getStyle() << endl;

  // Create Truck Object
  // print out usingg Vehicle, and Truck specific method
  Truck truck1("456-DEF", 2014, 7);
  cout << "Truck1 License: " << truck1.getLisence() << endl;
  cout << "Truck1 Year: " << truck1.getYear() << endl;
  cout << "Truck1 Bed Length: " << truck1.getBedLength() << endl;
  cout << "---------------- class inherite -----------------" << endl;
}


void oop_feature() {
  class_inherite();
  class_polymorphism();
}
