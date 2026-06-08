
#include <expected>
#include <iostream>


enum class Error {
  HTTP_ERROR,
  DB_ERROR
};

std::ostream& operator<<(std::ostream& os, Error e) {
  switch (e) {
    case Error::HTTP_ERROR: return os << "HTTP_ERROR";
    case Error::DB_ERROR:   return os << "DB_ERROR";
  }
}


std::expected<int, Error> f_expect(int a, int b) {
  if (b == 0) {
    return std::unexpected(Error::DB_ERROR);
  }
  return a / b;
}


void call_expect() {
  auto result = f_expect(10, 0);
  if (result) {
    std::cout << "result: " << result.value() << std::endl;
  } else {
    std::cout << "error: " << result.error() << std::endl;
  }
}


