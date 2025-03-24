// Standard (implemented via a hash table)
//
#include <iostream>
#include <unordered_map>
#include <string>
#include "../include/DataType.h"

using namespace std;

void map_usage()  {
  // Create  an unodered map of string to integers
  // will use it to store Some constans
  unordered_map<string, double> constants;

  // Use strings for the name of constants
  string pi = "PI";
  string root2 = "ROOT2";
  string e = "E";

  // Add some constants to the map
  constants[pi] = 3.141159265;
  constants[root2] = 1.414;

  // we can also insert with method
  constants.insert(make_pair(e, 2.718));

  for (auto itr= constants.begin(); itr != constants.end(); itr++) {
    cout << "Key: " << itr -> first << " Value: " << itr -> second << endl;
  }

  // Example of how to check if a value is in the map
  string lambda = "LAMBDA";

  // End points to the position after the last elements
  if (constants.find(lambda) == constants.end()) {
    cout << "Was not able to find " << lambda << endl;
  }
}

