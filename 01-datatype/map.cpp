// Standard (implemented via a hash table)
//
#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include "../include/DataType.h"

using namespace std;



// 基于 hash table 实现的无序 map 
// 数据输出与存储的先后顺序是无关的，底层基于 hash 函数来计算存储的位置
void unordered() {
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


void order() {

  map<int, int> ordermap;

  // Add three elements to the map
  ordermap[9] = 9 * 9;
  ordermap[4] = 4 * 4;
  ordermap[1] = 1 * 1;

  // print out key and values of the map
  // Implemented with a self balancing red-black tree
  for (auto itr = ordermap.begin(); itr != ordermap.end(); itr++) {
    cout << "Key; " << itr -> first << " Value: " << itr -> second << endl; 
  }
  

  // 查看当存储的 key 为 string 的排序情况
  // 按照字符顺序进行排序
  string animal1 = "aardvark";
  string animal2 = "baloon";
  string animal3 = "zebra";
  
  // Create an ordered map indexed by string key
  map<string, int> animals;

  // Insert using the method
  animals.insert(make_pair(animal3, 10));
  animals.insert(make_pair(animal1, 5));
  animals.insert(make_pair(animal2, 1));


  for (auto itr = animals.begin(); itr != animals.end(); itr++) {
    cout << "Key: " << itr -> first << " Value: " << itr -> second << endl;
  }
}

void map_usage()  {
  unordered();
  order();
}

