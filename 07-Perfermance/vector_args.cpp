
#include <iostream>
#include <vector>

using namespace std;


// Load number using pass-by-value
// usse copy constructor in
// 值作为参数传递，实际上调用的是 copy contructor 
// 进行了浅拷贝
vector<int> load_numbers_value(vector<int> v, int iter) {
  // print out the size and capacity on a specific iteration
  if (iter) {
    cout << "From Function:  load_numbers_value:" << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
  }

  // keep track of allocation
  int allocations = 0;
  int prev = v.capacity();

  // Load  the vector with 1k values
  for(auto i = 0; i < 1000; i++) {
    v.push_back(i);

    // check to see if we re-allocated anything
    if (v.capacity() > prev) {
      prev = v.capacity();
      allocations++;
    }
  }

  if (iter) {
    cout << "Loading 1000 numbers required " << allocations << " dynamic allocations" << endl;
    cout << "Ending capacity was : " << v.capacity() << endl;
  }

  // Return the vector
  // Uses automatic move on return for pass-by-value param
  return v;
}


// 1.
// Load number using pass-by-rvalue-ref( no move out)
// No copy constructor
// 值作为参数传递，实际上调用的是 move contructor 
// 进行了深拷贝
vector<int> load_numbers_rvalue_ref_1(vector<int>&& v, int iter) {

  // print out the size and capacity on a specific iteration
  if (iter) {
    cout << "From Function:  load_numbers_rvalue_ref_1:" << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
  }

  // keep track of allocation
  int allocations = 0;
  int prev = v.capacity();

  // Load  the vector with 1k values
  for(auto i = 0; i < 1000; i++) {
    v.push_back(i);

    // check to see if we re-allocated anything
    if (v.capacity() > prev) {
      prev = v.capacity();
      allocations++;
    }

  }

  if (iter) {
    cout << "Loading 1000 numbers required " << allocations << " dynamic allocations" << endl;
    cout << "Ending capacity was : " << v.capacity() << endl;
  }

  // Return the vector
  // No longer a by-value parameter, so it uses a copy constructor
  // Returns with a fitted capacity
  return v;
}

// 2.
// Load number using pass-by-rvalue ref (move out)
// No copy constructor
// vector<int>&& v ==> think of this somewhat as a constant reference
vector<int> load_number_rvalue_ref_2(vector<int>&& v, int iter) {

  // print out the size and capacity on a specific iteration
  if (iter) {
    cout << "From Function:  load_numbers_rvalue_ref_2:" << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
  }

  // keep track of allocation
  int allocations = 0;
  int prev = v.capacity();

  // Load  the vector with 1k values
  for(auto i = 0; i < 1000; i++) {
    v.push_back(i);

    // check to see if we re-allocated anything
    if (v.capacity() > prev) {
      prev = v.capacity();
      allocations++;
    }
  }

  if (iter) {
    cout << "Loading 1000 numbers required " << allocations << " dynamic allocations" << endl;
    cout << "Ending capacity was : " << v.capacity() << endl;
  }

  // Return the vector
  // No longer a by-value parameter, so it uses a move constructor
  return std::move(v);
}

void load_numbers_ref(vector<int>& v, int iter){
  // print out the size and capacity on a specific iteration
  if (iter) {
    cout << "From Function:  load_numbers_ref:" << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
  }

  // keep track of allocation
  int allocations = 0;
  int prev = v.capacity();

  for(auto i = 0; i < 1000; i++){

    v.push_back(i);

    // check to see if we re-allocated anything
    if (v.capacity() > prev) {
      prev = v.capacity();
      allocations++;
    }
  }

  if (iter) {
    cout << "Loading 1000 numbers required " << allocations << " dynamic allocations" << endl;
    cout << "Ending capacity was : " << v.capacity() << endl;
  }

}


int main(int argc, char* argv[]) {
  if (argc == 1) {
    cout << "Not Enought arguments" << endl;
    return 1;
  }

  string arg = argv[1];
  size_t pos;
  int iter = stoi(arg, &pos);

  // Create a new vector
  vector<int> v;

  // Do this step 10x
  for (auto i = 0; i < 10; i++) {

    if (i == iter) {
      cout << "From function main " << endl;
      cout << "Before clear: " << endl;
      cout << "Size: " << v.size() << " Capacity: " << v.capacity() << endl;
    }

    // clear the vector each time
    v.clear();

    if (i == iter) { 
      cout << "After clear: " << endl;
      cout << "size: " << v.size() << " Capacity: " << v.capacity() << endl;
    }

    // Print ?
    int tmp = i == iter ? 1 : 0;

    // Load a new set of number
    // v = load_numbers_value(v, tmp);
    // v = load_numbers_rvalue_ref_1(std::move(v), tmp);
    // v = load_number_rvalue_ref_2(std::move(v), tmp);
    load_numbers_ref(v, tmp);
  
  }
  return 0;
}
