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

S21Matrix operator*(const S21Matrix m, const double num) {
  S21Matrix res(m);
  res.MulNumber(num);
  return res;
}

S21Matrix operator*(const double num, const S21Matrix m) { return m * num; }

bool S21Matrix::operator==(S21Matrix &other) {
    return EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix &other) {
    this->rows_ = other.rows_;
    this->cols_ = other.cols_; 
    this->matrix_ = other.matrix_;
    return *this;
}

S21Matrix& S21Matrix::operator+=(S21Matrix &other) {
    SumMatrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator-=(S21Matrix &other) {
    SubMatrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator*=(S21Matrix &other) {
    MulMatrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
    MulNumber(num);
    return *this;
}

double& S21Matrix::operator()(int i, int j) {
    if (i >= rows_ || i < 0 || j >= cols_ || j < 0) {
        throw std::out_of_range("Index out of range");
    }
    return matrix_[i][j];
}
