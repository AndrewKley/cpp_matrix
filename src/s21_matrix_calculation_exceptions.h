#ifndef SRC_S21_MATRIX_CALCULATION_EXCEPTIONS_H
#define SRC_S21_MATRIX_CALCULATION_EXCEPTIONS_H

#include <exception>
#include <iostream>

using namespace std;

class MatrixCalculationError : public exception {
 public:
  MatrixCalculationError(const string message) : message_(message) {}

  const char* what() const noexcept override { return message_.c_str(); }

 private:
  string message_;
};

#endif  // SRC_S21_MATRIX_CALCULATION_EXCEPTIONS_H
