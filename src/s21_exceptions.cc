#include "s21_exceptions.h"

MatrixSizeError::MatrixSizeError(const string message) : message_(message) {}

const char* MatrixSizeError::what() const noexcept {
    return message_.c_str();
}

MatrixCalculationError::MatrixCalculationError(const string message) : message_(message) {}

const char* MatrixCalculationError::what() const noexcept {
    return message_.c_str();
}
