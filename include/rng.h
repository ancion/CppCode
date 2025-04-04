#pragma 

#include <cstdlib>
#include <vector>

std::vector<int> rng(int begin, int end, int cout) {
  std::vector<int> v;
  for(int i = 0; i < cout; i++) {
    v.push_back((std::rand() % end) + begin);
  }
  return v;
}
