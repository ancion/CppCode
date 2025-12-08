// This program shows off the basics of enums in C++

#include "../include/DataType.h"
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

/**
  *  可以声明 enum, 但是 声明的枚举成员存在于作用域，并不在类型的作用域范围
  *  同一个范围内不能存在相同名称的枚举成员，还可能存在隐式转换问题(默认枚举值是整形数值，会隐式转换)
  */

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

void c_enum() {
  // Make two suit_t variables
  suit_t card1 = CLUBS;
  suit_t card2 = DIAMONDS;

  // print out the string from our function, and the actual value
  cout << "Card1 is a  " << print_suit(card1) << " with value" << card1 << endl;
  cout << "Card2 is a  " << print_suit(card2) << " with value" << card2 << endl;
}

/**
*
* 枚举类
*/
enum class SUIT : size_t {
  CLUBS,
  DIAMONDS,
};

auto enum_name(SUIT suit) -> string {
  switch (suit) {
    case SUIT::CLUBS:
      return "clubs";
    case SUIT::DIAMONDS:
      return "diamonds";
    default:
      return "unknown";
  }
}

void enum_class() {
  // 适用时需要在类型的作用域中
  cout << enum_name(SUIT::CLUBS) << endl;

  // 真要转换的时候需要显示转换
  cout << "SUIT::CLUBS" << static_cast<size_t>(SUIT::CLUBS) << endl;
}

void enum_usage() {
  c_enum();
  enum_class();
}
