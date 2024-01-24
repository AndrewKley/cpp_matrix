#ifndef SRC_S21_MATRIX_OOP_H
#define SRC_S21_MATRIX_OOP_H

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cmath>

#include "s21_exceptions.h"

#define EPS 1e-7

class S21Matrix {
    public:
        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix&& other);
        ~S21Matrix();
        bool EqMatrix(const S21Matrix& other);
        void SumMatrix(const S21Matrix& other);
        void SubMatrix(const S21Matrix& other);
        void MulNumber(const double num);
        void MulMatrix(const S21Matrix& other);
        int GetRow();
        int GetCol();
        void SetRow(int row);
        void SetCol(int col);
        S21Matrix Transpose();
        S21Matrix CalcComplements();
        double Determinant();
        S21Matrix InverseMatrix();
        S21Matrix operator+(S21Matrix &other);
        S21Matrix operator-(S21Matrix &other);
        S21Matrix operator*(S21Matrix &other);
        friend S21Matrix operator*(const S21Matrix m, const double num);
        friend S21Matrix operator*(const double num, const S21Matrix m);
        bool operator==(S21Matrix &other);
        S21Matrix& operator=(const S21Matrix &other);
        S21Matrix& operator+=(S21Matrix &other);
        S21Matrix& operator-=(S21Matrix &other);
        S21Matrix& operator*=(S21Matrix &other);
        S21Matrix& operator*=(const double num);
        double& operator()(int i, int j);
        void FillMatrix(double* arr, int len);
        void PrintMatrix();
        bool eq_size(const S21Matrix &matrix);
        void CalculateDeterminant(S21Matrix *tmp, double *result);

    private:
        int rows_, cols_;
        double **matrix_;
        void InitMatrix(int rows, int cols);
        double Fabs(double num);
        double CalculateMinor(int m, int n, S21Matrix *tmp);
};

#endif  // SRC_S21_MATRIX_OOP_H
