#include <cstdlib>
#include <iostream>

using namespace std;

// C++ 中的返回值优化

struct WrapString {

  string s;
  WrapString(string s1): s(s1) { }
  // if we copy, we want to know, so print something
  WrapString(const WrapString &s2) {
    cout << "Copying the string!" << endl;
    s = s2.s;
  }
};


// This function benefit from RVO
// Function with return values secretly have 1 argument
// (where to store the return value).
// if we know ahead of time what is going to be returned, don't 
// make a local version and copy it, make the string where it will 
// be copied in the first place 
WrapString rvo() {
  WrapString ms("Hey There!");
  return ms;
}

// This function does not benefit from RVO
// Which string we return depends on a condition, therefore can't
// be know ahead of time. 
// There we have to copy the object on a return 
WrapString no_rvo(int condition) {
  WrapString ms1("Hi filla");
  WrapString ms2("Ahoy");

  // Can't kow which string will be returned ahead of, 
  // so we can't elide the copy
  if (condition) {
    return ms1;
  } else {
    return ms2;
  }
}

int main() {
  // Set the seed and set the condition to 1 or 0
  srand(time(NULL));
  int condition = rand() % 2;

  // Get the string with RVO
  cout << "Getting a string with RVO" << endl;
  WrapString s1 = rvo();

  // Get the String without RVO
  cout << "Get a string without RVO" << endl;
  WrapString s2 = no_rvo(condition);

  // print the strings
  cout << "String s1: " << s1.s << endl;
  cout << "String s2: " << s2.s << endl;
  return 0;
}
