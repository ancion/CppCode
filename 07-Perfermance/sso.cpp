// short string optimization 
//

#include <cstdlib>
#include <iostream>

using namespace std;

void* operator new(size_t n) {
  cout << "Allocation: " << n << endl;
  malloc(n);
}


void usage_short_string() {

  size_t string_size = sizeof(string);
  cout << "Size of string " << string_size << endl;

  for (size_t i = 0; i < string_size; i++){
    string s(i, 'x');
    cout << i << " : " << s << endl;
  }
}

int main() {
  usage_short_string();
}
