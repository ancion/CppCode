#include <iostream>
#include <cassert>
#include <variant>

using namespace std;
 
void usage_variant() {

  // Variant are type-safe union
  // Unlike unions, variant know what type they current hold
  variant<int, float> v, w;

  // Set v to have an int
  // we van not call get<int> on v
  // get<float> will be an error
  v = 12;
  
  // we can also set variant in a number of ways
  // Get the int from v
  w = get<int>(v);
  // Get the int at position 0
  w = get<0>(v);

  // Just use assignment and ignore get
  w = v;

  // Indexing our of bounds, or usinng an type doesn't exist in 
  // the variant will throw an error
  try {

    // This will clearly fail because int is avtive
    get<float>(w);

  }catch(const bad_variant_access&) {
    cout << "The float field isn't avtive right now!" << endl;
  }
}
