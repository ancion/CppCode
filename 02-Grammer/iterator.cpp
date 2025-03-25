// This program show off the basics of iterators in c++

#include <iostream>
#include <vector>

using namespace std;

void iterator_usage() {


  // Create a simple vector of integers
  vector<int> int_vec;

  // while we can index into a vector like an array, we can use
  // iterator as a more general mechanism 
  // Let's declare one for our vector
  vector<int>::iterator itr_begin;
  vector<int>::iterator itr_end;

  // when going over a vector, we typically care about start and end
  // points, we can get these directly from our declared vector
  itr_begin = int_vec.begin();
  itr_end = int_vec.end();

  // we can use these as the bounds for a loop
  for (auto i = int_vec.begin(); i != int_vec.end(); i++) {
    cout << *i << " ";
  }
  cout << endl;

  // Reverse interator work backwords

  for(auto i = int_vec.rbegin(); i != int_vec.rend(); i++){
    cout << *i << " ";
  }
  cout << endl;
}
