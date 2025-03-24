// Cpp stdlib have a new datatype array

#include "../include/DataType.h"
#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename T> void print_container(T t) {
  for (auto i : t) {
    cout << i << " ";
  }
  cout << endl;
}

// 数组对象的使用
void arrays_example() {
  // Arrays are fixed-size containers
  // specify a type and size
  // Has fast random access
  array<int, 10> int_array = {9, 1, 23, 19, 93, 1, 5, 8, 3, 7};

  // print the array, sort it, and print again
  cout << "Array:" << endl;
  print_container(int_array);
  sort(int_array.begin(), int_array.end());
  print_container(int_array);
}

void vector_example() {

  // Vector are a flexable-size array (strings are similar)
  // specify a type
  // Has fast random access, but adding elements to a position other
  // than the back may be slow
  // Use vector unless you have a reson to use another container
  vector<int> int_vector;
  for (int i = 0; i < 10; i++) {
    int_vector.push_back(i * i);
  }

  // Print the vector, remove back elements, then print again
  cout << "Vector: " << endl;
  print_container(int_vector);
  int_vector.pop_back();
  int_vector.pop_back();
  int_vector.pop_back();
  print_container(int_vector);
}

void list_example() {

  // Forward lists and list are singly and doubly linked lists
  // respectively
  // specify a type
  // Fast insert/delete at any point in the list
  list<int> int_list;
  for(int i = 0; i < 5; i++) {
    int_list.push_back(i);
  }

  // print the list
  // Insert into some elements at different positions ,then angin
  cout << "List " << endl;
  print_container(int_list);
  auto itr = int_list.begin();
  int_list.insert(itr, 5);
  print_container(int_list);
  int_list.insert(itr, 6);
  print_container(int_list);
  int_list.insert(int_list.begin(), 7);
  print_container(int_list);

  // Benefit of list is that we can traverse backwards
  for(auto r_itr = int_list.rbegin(); r_itr != int_list.rend(); r_itr++) {
    cout << *r_itr << " ";
  }
  cout << endl;
}

void deque_example() {

  // Deques are double ended queues
  // Specify a type
  // Fast random access and insert/delete at front or back
  deque<int> int_deque;
  for(int i =0; i < 5; i++) {
    int_deque.push_back(i);
  }

  // print the deque
  cout << "Deque: " << endl;
  print_container(int_deque);
  int_deque.push_front(5);
  int_deque.push_front(6);
  int_deque.push_front(8);
  print_container(int_deque);
}

void container_usage() {
  arrays_example();
  vector_example();
  list_example();
  deque_example();
}
