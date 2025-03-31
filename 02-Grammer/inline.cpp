
// inline function replace function caller with code block
// but not always work, decide by compiler optimization
//
inline int square(int a) {
  return a * a;
}


// inline function can increase binary size
// usually used when code repear frequently and code block is small
// recursion is a good example
