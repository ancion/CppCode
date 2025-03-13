#pragma once

#include <string>

using namespace std;

class Vehicle {
  // May be accessed from within the class or inherited class
protected:
  string license;
  int year;
public:
  // Constructor with initilization list (needed for constants)
  Vehicle(const string &myLicense, const int &myYear): license(myLicense), year(myYear){}
  const string &getLisence() const  { return license;}
  const int getYear() const { return year;}

  // if not virtual, this function will be called
  // and eventually vehicle type point to (->) a subclass 
  // Vehicle *v1 = &Car(...);
  // const string getDescription() const { return ""; }

  // virtual function can dynamic dispatch override implementation of sub class
  // virtual const string getDescription() const {
  //    return "Vehicle: license [ " + license + " ] year: [" + to_string(year) + "]";
  // }

  // this function make class is abstract, so it can't be instantiated
  // and can't be called
  virtual const string getDescription() const = 0;

};

// Car class inherited from Vehicle class
// Public lets us keep original access specifiers
class Car: public Vehicle {
private:
  string style;
public:
  // Aother initilization list
  Car(const string &myLicense, const int myYear, const string myStyle)
    :Vehicle(myLicense, myYear), style(myStyle) {}

  const string &getStyle() const { return style;}

  virtual const string getDescription() const override;

};

// Truck class that also inherited from Vehicle
class Truck: public Vehicle {
private: 
  int bed_length;
public:

  // Another initialization list
  Truck(const string &myLicense, const int myYear, const int myBedLength) 
  : Vehicle(myLicense, myYear), bed_length(myBedLength){}
  const int getBedLength() const { return bed_length;}

  virtual const string getDescription() const override;
};
