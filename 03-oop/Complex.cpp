#include <iostream>
#include "../include/Complex.h"


Complex::Complex(double real, double imag): real(real), imag(imag) {}

Complex Complex::operator+(const Complex& other) const {
  return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
  return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
  return Complex(
    real * other.real - imag * other.imag, 
    real * other.imag + imag * other.real
  );
}

Complex Complex::operator/(const Complex& other) const {
  double denom = other.real * other.real + other.imag * other.imag;
  if (!denom) throw std::invalid_argument("Denominator is zero");
  return Complex(
    (real * other.real + imag * other.imag) / denom, 
    (imag * other.real - real * other.imag) / denom
  );
}

void Complex::print() const {
  std::cout << real <<  "+" << imag << "i" << std::endl;
}

std::ostream & operator<<(std::ostream &os, const Complex& c) {
  if (c.real == 0 && c.imag == 0) 
    return os << "0";
  if (c.real) 
    os << c.real;
  if (c.imag < 0) {
    os << c.imag << "i";
  } else if (c.imag > 0) {
    os << "+" << c.imag << "i";
  }
  return os;
}

void operator_overload() {
  Complex c1(1, 2);
  Complex c2(3, 4);
  std::cout << c1 + c2 << std::endl;
  std::cout << c1 - c2 << std::endl;
  std::cout << c1 * c2 << std::endl;
  std::cout << c1 / c2 << std::endl;
}

