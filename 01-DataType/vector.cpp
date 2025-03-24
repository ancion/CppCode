
#include "../include/DataType.h"
#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

void vector_usage() {
  cout << "---------------test of vector --------------------" << endl;

  // Declare a vector that expand with integer
  // More on template (<int>) later
  vector<int> v1;

  for (int i = 0; i < 10; i++) {
    // Method for expanding the vector
    v1.push_back(i);
  }

  // print the vector
  print_vector(v1);

  // print the first element
  cout << "first element: " << v1.front() << endl;

  // print the last element
  cout << "last element: " << v1.back() << endl;

  // print the first element using array like indexing
  cout << "first element using array-like indexing: " << v1[0] << endl;

  // clear a vector and print out it's size
  v1.clear();
  cout << "Cleared vector size is: " << v1.size() << endl;

  // Resize the vector and print size and vecotr
  v1.resize(10);
  cout << "Resized vector size is: " << v1.size() << endl;
  print_vector(v1);

  // Re-initialize vector
  for (int i = 0; i < 10; i++) {
    // Method for expanding the vector
    v1.at(i) = i;
  }

  // Inser into the vector before a chosen position
  v1.insert(v1.begin() + 4 , 5);
  print_vector(v1);

  // Erase an element at a specific position
  v1.erase(v1.begin() + 4);
  print_vector(v1);

  // Erase the end element
  v1.pop_back();
  print_vector(v1);
  cout << "---------------test of vector --------------------" << endl;
}
