#pragma once
#include <iostream>

using namespace std;
class IntArray {
public:
  int *data;
  int size;

  IntArray(int size){
    data = new int[size];
    // `this` refers to the object we are in 
    // Allows us to differentlate between parameters and fields
    this -> size = size;
  }

  // A destructor for integer array
  ~IntArray(){
    cout << "IntArray destructor" << endl;
    delete[] data; 
  }

  // A necessary copy constructor for this to work
  // intuitively Performs what known as a deep copy
  // Default copy constructor does a shallow copy (just fields)
  IntArray(IntArray &o) {
    data = new int[o.size];
    size = o.size;
    for (int i = 0; i < size; i++) {
      data[i] = o.data[i];
    }
  }
};

void class_destructor();
