#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(S21Matrix &other) {
  S21Matrix tmp(*this);
  tmp.SumMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator-(S21Matrix &other) {
  S21Matrix tmp(*this);
  tmp.SubMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator*(S21Matrix &other) {
  S21Matrix tmp(*this);
  tmp.MulMatrix(other);
  return tmp;
}

S21Matrix operator*(S21Matrix m, const double num) {
  S21Matrix res(m);
  res.MulNumber(num);
  return res;
}

S21Matrix operator*(double num, S21Matrix m) { return m * num; }

bool S21Matrix::operator==(S21Matrix &other) { return EqMatrix(other); }

S21Matrix &S21Matrix::operator=(S21Matrix &other) {
  if (matrix_) {
    delete[] matrix_[0];
    delete[] matrix_;
  }
  rows_ = other.rows_;
  cols_ = other.cols_;
  InitMatrix(other.rows_, other.cols_);
  memcpy(matrix_[0], other.matrix_[0], rows_ * cols_ * sizeof(double));
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  if (other.rows_ <= 0 || other.cols_ <= 0) {
    throw std::out_of_range("Values ain't be less or equal to 0");
  }
  if (matrix_) {
    delete[] matrix_[0];
    delete[] matrix_;
  }
  rows_ = other.GetRow();
  cols_ = other.GetCol();
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
  return *this;
}

S21Matrix &S21Matrix::operator+=(S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(double num) {
  MulNumber(num);
  return *this;
}

double &S21Matrix::operator()(int i, int j) const {
  if (i >= rows_ || i < 0 || j >= cols_ || j < 0) {
    throw std::out_of_range("Index out of range");
  }
  return matrix_[i][j];
}
