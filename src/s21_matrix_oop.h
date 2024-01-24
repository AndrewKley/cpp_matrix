#ifndef SRC_S21_MATRIX_OOP_H
#define SRC_S21_MATRIX_OOP_H

#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>

#include "s21_matrix_calculation_exceptions.h"
#include "s21_matrix_size_exceptions.h"

#define EPS 1e-7

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();
  bool EqMatrix(const S21Matrix& other) noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  int GetRow() const noexcept;
  int GetCol() const noexcept;
  /**
      @brief create a matrix with specified number of rows and fill empty cells
     with zeros
  */
  void SetRow(int row);
  /**
      @brief create a matrix with specified number of columns and fill empty
     cells with zeros
  */
  void SetCol(int col);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
  S21Matrix operator+(S21Matrix& other);
  S21Matrix operator-(S21Matrix& other);
  S21Matrix operator*(S21Matrix& other);
  friend S21Matrix operator*(S21Matrix m, double num);
  friend S21Matrix operator*(double num, S21Matrix m);
  bool operator==(S21Matrix& other);
  S21Matrix& operator=(S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  S21Matrix& operator+=(S21Matrix& other);
  S21Matrix& operator-=(S21Matrix& other);
  S21Matrix& operator*=(S21Matrix& other);
  S21Matrix& operator*=(double num);
  double& operator()(int i, int j) const;
  void FillMatrix(double* arr, int len);
  void PrintMatrix();
  bool IsEque(const S21Matrix& matrix);
  void CalculateDeterminant(S21Matrix* tmp, double* result);

 private:
  int rows_, cols_;
  double** matrix_;
  void InitMatrix(int rows, int cols);
  double Fabs(double num) noexcept;
  double CalculateMinor(int m, int n, S21Matrix* tmp);
};

#endif  // SRC_S21_MATRIX_OOP_H
