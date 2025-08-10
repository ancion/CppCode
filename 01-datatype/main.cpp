#include <cstdio>
#include <cstring>
#include "../include/DataType.h"

// 避免不同类库中的包中出现同名函数，所以使用的时候使用using声明命名空间
// 使用的时候可以省略对应的命名空间
using namespace std;


void dataType() {

  bool_usage();

  char_usage();

  number_usage();

  datatype_trans();

  void_usage();

  str_usage();

  array_usage();

  container_usage();

  vector_usage();

  struct_usage();

  union_usage();

  map_usage();

  enum_usage();

  // C++11
  tuple_usage();
}
