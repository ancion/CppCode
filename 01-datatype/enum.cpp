// This program shows off the basics of enums in C++

#include "../include/DataType.h"
#include <iostream>

using namespace std;

enum suit_t {
  CLUBS=0,
  DIAMONDS=1,
  HEARTS=2,
  SPADES=3,
};

// Had we used an integer here, it would be easyier to mistakenly 
// have an out-of bounds access, Restricting to the enum prevents
// this

const char* print_suit(const suit_t suit) {
  const char *names[] = { "Clubs", "Diamonds", "hearts", "Spades" };
  return names[suit];
}

void enum_usage() {
  // Make two suit_t variables
  suit_t card1 = CLUBS;
  suit_t card2 = DIAMONDS;

  // print out the string from our function, and the actual value
  cout << "Card1 is a  " << print_suit(card1) << " with value" << card1 << endl;
  cout << "Card2 is a  " << print_suit(card2) << " with value" << card2 << endl;
}


