#include <iostream>
#include <memory>
#include "../include/Pointers.h"

using namespace std;

void share_weak() {

  // Create a shared pointer shared pointers are invalid while at lease shared pointer 
  // points to the data, the last pointer frees it
  shared_ptr<int> shared_int_1(new int(10));
  shared_ptr<int> shared_int_2 = shared_int_1;

  // print out use cout 
  cout << "Use count of shared_int: " << shared_int_1.use_count() << endl;

  // create a weak pointer
  // Weak pointers point to memory, but not an owner
  // Good when we don't want an owner, or hanling cycle references
  weak_ptr<int> weak_int = shared_int_1;
  // print out use count 
  cout << "Use count of shared_int: " << weak_int.use_count() << endl;

  // Convert the weak pointer to a shared pointers and print again
  auto shared_int_3 = weak_int.lock();
  cout << "Use count of shared_int: " << shared_int_3.use_count() << endl;


  // Destroy the memory for 2 of the shared pointers and check uniqueness
  shared_int_1.reset();
  shared_int_2.reset();
  cout << "Use Count of shared_int: " << shared_int_3.use_count() << endl;
  // 返回 1 表示是唯一的, 返回 0 表示不是
  cout << "Shared_int_3 is unique: " << shared_int_3.unique() << endl;

  // Reset the last pointer
  shared_int_3.reset();

  // check to see if it is valid
  // 0 is invalid
  // 1 is valid
  cout << "shared int valid: " << shared_int_3.get() << endl;

}

void unique() {

  // Creat a unique pointer
  // Unique pointers, but are the only owner of the memory it pointers to 
  // Good for exclude ownership
  unique_ptr<int> unique_int(new int(1));
}

void intelpointer() {
  share_weak();
  unique();
}
