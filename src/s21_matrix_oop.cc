#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
    bool is_eq = true;
    if (other.rows_ == rows_ && other.cols_ == cols_) {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                if (Fabs(matrix_[i][j] - other.matrix_[i][j]) >= EPS) {
                    is_eq = false;
                    break;
                }
            }
            if (!is_eq) break;
        }
    } else {
        is_eq = false;
    }
    return is_eq;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
    if (eq_size(other) == false) {
        throw MatrixSizeError("The size of the matrices is different");
    }
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] += other.matrix_[i][j];
        }
    }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
    if (eq_size(other) == false) {
        throw MatrixSizeError("The size of the matrices is different");
    }
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] -= other.matrix_[i][j];
        }
    }
}

void S21Matrix::MulNumber(const double num) {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] *= num;
        }
    }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
    if (cols_ != other.rows_) {
        throw MatrixSizeError("The number of columns of the first matrix \
                                is not equal to the number of rows of the second matrix");
    }
    S21Matrix res(rows_, other.cols_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < other.cols_; j++) {
            for (int k = 0; k < cols_; k++) {
                res.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
            }
        }
    }
    this->~S21Matrix();
    this->rows_ = res.rows_;
    this->cols_ = res.cols_;
    this->matrix_ = res.matrix_;
    res.matrix_ = nullptr;
}

double S21Matrix::CalculateMinor(int m, int n, S21Matrix *tmp) {
    double res = 0;
    S21Matrix ttmp(tmp->rows_ - 1, tmp->cols_ - 1);
    for (int i = 0, i_tmp = 0; i < rows_; i++) {
        if (i != m) {
            for (int j = 0, j_tmp = 0; j < cols_; j++) {
                if (j != n) {
                    ttmp.matrix_[i_tmp][j_tmp] = tmp->matrix_[i][j];
                    j_tmp++;
                }
            }
            i_tmp++;
        }
    }
    if (ttmp.rows_ == 2) {
        res = (ttmp.matrix_[0][0] * ttmp.matrix_[1][1]) -
              (ttmp.matrix_[0][1] * ttmp.matrix_[1][0]);
    } else {
        CalculateDeterminant(&ttmp, &res);
    }
    return res;
}

void S21Matrix::CalculateDeterminant(S21Matrix *tmp, double *result) {
    if (tmp->rows_ == 1) {
        *result = tmp->matrix_[0][0];
    }
    for (int i = 0; i < tmp->rows_ && tmp->rows_ > 1; i++) {
        *result += matrix_[i][0] * pow(-1, 2 + i) * CalculateMinor(i, 0, tmp);
    }
}

double S21Matrix::Determinant() {
    if (rows_ != cols_) {
        throw MatrixSizeError("The Determinant exists only for a square matrix");
    }

    double result = 0;
    S21Matrix tmp(*this);
    if (rows_ > 1) {
        CalculateDeterminant(&tmp, &result);
    }
    return rows_ == 1 ? matrix_[0][0] : result;
}

S21Matrix S21Matrix::Transpose() {
    S21Matrix res(cols_, rows_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            res.matrix_[j][i] = matrix_[i][j];
        }
    }
    return res;
}

S21Matrix S21Matrix::CalcComplements() {
    if (rows_ != cols_) {
        throw MatrixSizeError("The Determinant exists only for a square matrix");
    }
    S21Matrix tmp(*this);
    
    for (int i = 0; i < rows_ && rows_ > 1; i++) {
        for (int j = 0; j < cols_; j++) {
            tmp.matrix_[i][j] = pow(-1, i + j) * CalculateMinor(i, j, this);
        }
    }
    return tmp;
}

S21Matrix S21Matrix::InverseMatrix() {
    if (rows_ != cols_) {
        throw MatrixSizeError("The Determinant exists only for a square matrix");
    } 
    if (rows_ == 1) {
        throw MatrixCalculationError("The number of rows must be greater than 1");
    }
    double det = 0;
    if ((det = Determinant()) == 0) {
        throw MatrixCalculationError("Determinant is equal to 0, it isn't exists");
    }

    S21Matrix tmp = CalcComplements();
    S21Matrix res = tmp.Transpose();
    res.MulNumber(1 / det);
    return res;
}

S21Matrix::S21Matrix() { S21Matrix::InitMatrix(3, 3); }

S21Matrix::S21Matrix(int rows, int cols) { S21Matrix::InitMatrix(rows, cols); }

S21Matrix::S21Matrix(const S21Matrix& other) {
    S21Matrix::InitMatrix(other.rows_, other.cols_);
    memcpy(matrix_[0], other.matrix_[0], rows_ * cols_ * sizeof(double));
}

S21Matrix::S21Matrix(S21Matrix&& other) {
    if (other.rows_ <= 0 || other.cols_ <= 0) {
        throw std::out_of_range("Values ain't be less or equal to 0");
    }
    SetRow(other.rows_);
    SetCol(other.cols_);
    matrix_ = other.matrix_;
    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
    if (matrix_) {
        delete[] matrix_[0];
        delete[] matrix_;
        matrix_ = nullptr;
        rows_ = 0;
        cols_ = 0;
    }
}

int S21Matrix::GetRow() { return rows_; }

int S21Matrix::GetCol() { return cols_; }

void S21Matrix::SetRow(int row) {
    if (row <= 0) {
        throw std::out_of_range("Row less than or equal to 0 is invalid");
    }
    rows_ = row;
}

void S21Matrix::SetCol(int col) {
    if (col <= 0) {
        throw std::out_of_range("Col less than or equal to 0 is invalid");
    }
    cols_ = col;
}

void S21Matrix::InitMatrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::out_of_range("Values ain't be less or equal to 0");
    }
    rows_ = rows;
    cols_ = cols;
    matrix_ = new double*[rows_];
    matrix_[0] = new double[rows_ * cols_];
    for (int i = 0; i < rows_; i++)
        matrix_[i] = matrix_[0] + i * cols_;
    memset(matrix_[0], 0, rows_ * cols_ * sizeof(double));
}

double S21Matrix::Fabs(double num) { return num < 0 ? num * -1 : num; }

void S21Matrix::FillMatrix(double* arr, int len) {
    if (len < rows_ * cols_) throw std::out_of_range("arr's len less than matrix's size");
    memcpy(matrix_[0], arr, rows_ * cols_ * sizeof(double));
}

bool S21Matrix::eq_size(const S21Matrix &matrix) {
    return matrix.rows_ == rows_ && matrix.cols_ == cols_;
}

void S21Matrix::PrintMatrix() {
    if (matrix_ != nullptr) {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                std::cout << matrix_[i][j] << '\t';
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}
