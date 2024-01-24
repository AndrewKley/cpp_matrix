#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"

using namespace std;

double MAT1[] = {1, 2.0, 3., 4, 1, 6., 7, 2, 9, -1.2, 0.0001, 0.};
double MAT2[] = {0., -3., 0.132};
double MAT3[] = {-.1213, 4545, 0.3243};
double MAT4[] = {-134.234, 0., .023, -1, 0.243, 0};
double MAT5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
double MAT6[] = {1., 2., 3., 4., 1, 4, 3, 3, 1};
double MAT7[] = {1., 0., 2., 3.};
double MAT8[] = {5, -1, 0, 2, 1, 1};
double MAT9[] = {0, 2, 3, 1, -1, -2};
double MAT10[] = {-2, 1, 1, 1, 3, -5, 2, 4, 5};
double MAT11[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
double MAT12[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};

char ERROR_MESSAGE_MUL_MATRIX[] = "The number of columns of the first matrix \
                                is not equal to the number of rows of the second matrix";

TEST(mul_matrix, mul1) {
    S21Matrix a(2, 3);
    S21Matrix b(2, 3);
    try {
        a.MulMatrix(b);
    } catch (const MatrixSizeError& size_error) {
        EXPECT_STREQ(ERROR_MESSAGE_MUL_MATRIX, size_error.what());
    }
}

TEST(mul_matrix, mul2) {
    S21Matrix a(4, 4);
    S21Matrix b(3, 3);
    try {
        a.MulMatrix(b);
    } catch (const MatrixSizeError& size_error) {
        EXPECT_STREQ(ERROR_MESSAGE_MUL_MATRIX, size_error.what());
    }
}

TEST(mul_matrix, mul3) {
    S21Matrix a(3,3), b(3,3);
    a.FillMatrix(MAT10, 9);
    b.FillMatrix(MAT11, 9);
    try {
        a.MulMatrix(b);
        EXPECT_DOUBLE_EQ(a(0, 0), 3);
        EXPECT_DOUBLE_EQ(a(0, 1), 2);
        EXPECT_DOUBLE_EQ(a(0, 2), -3);
        EXPECT_DOUBLE_EQ(a(1, 0), -24);
        EXPECT_DOUBLE_EQ(a(1, 1), 4);
        EXPECT_DOUBLE_EQ(a(1, 2), 4);
        EXPECT_DOUBLE_EQ(a(2, 0), 27);
        EXPECT_DOUBLE_EQ(a(2, 1), 30);
        EXPECT_DOUBLE_EQ(a(2, 2), 19);
    } catch (const char* error_message) {
        cout << error_message << endl; 
    }
}

TEST(mul_matrix, mul4) {
    S21Matrix a(2,3), b(3,2);
    a.FillMatrix(MAT5, 6);
    b.FillMatrix(MAT6, 6);
    try {
        a.MulMatrix(b);
        EXPECT_DOUBLE_EQ(a(0, 0), 0);
        EXPECT_DOUBLE_EQ(a(0, 1), 0);
        EXPECT_DOUBLE_EQ(a(1, 0), 0);
        EXPECT_DOUBLE_EQ(a(1, 1), 0);
    } catch (const char* error_message) {
        cout << error_message << endl; 
    }
}

TEST(mul_matrix, mul5) {
    S21Matrix a(1,1), b(1,1);
    double num1[] {3}, num2[] {4};
    a.FillMatrix(num1, 1);
    b.FillMatrix(num2, 1);
    try {
        a.MulMatrix(b);
        EXPECT_DOUBLE_EQ(a(0, 0), 12);
    } catch (const char* error_message) {
        cout << error_message << endl; 
    }
}

TEST(mul_number, mul_num_1) {
    S21Matrix a(2, 3);
    a.FillMatrix(MAT8, 6);
    a.MulNumber(2);
    EXPECT_DOUBLE_EQ(a(0,0), 10);
    EXPECT_DOUBLE_EQ(a(0,1), -2);
    EXPECT_DOUBLE_EQ(a(0,2), 0);
    EXPECT_DOUBLE_EQ(a(1,0), 4);
    EXPECT_DOUBLE_EQ(a(1,1), 2);
    EXPECT_DOUBLE_EQ(a(1,2), 2);
}

TEST(mul_number, mul_num_2) {
    S21Matrix a(3, 3);
    a.FillMatrix(MAT12, 9);
    a.MulNumber(0);
    EXPECT_DOUBLE_EQ(a(0,0), 0);
    EXPECT_DOUBLE_EQ(a(0,1), 0);
    EXPECT_DOUBLE_EQ(a(0,2), 0);
    EXPECT_DOUBLE_EQ(a(1,0), 0);
    EXPECT_DOUBLE_EQ(a(1,1), 0);
    EXPECT_DOUBLE_EQ(a(1,2), 0);
    EXPECT_DOUBLE_EQ(a(2,0), 0);
    EXPECT_DOUBLE_EQ(a(2,1), 0);
    EXPECT_DOUBLE_EQ(a(2,2), 0);
}

TEST(mul_number, mul_num_3) {
    S21Matrix a(1, 1);
    a.FillMatrix(MAT4, 1);
    a.MulNumber(2.5);
    EXPECT_DOUBLE_EQ(a(0,0), -134.234 * 2.5);
}

TEST(sub_matrix, sub1) {
    S21Matrix a(2, 3);
    S21Matrix b(3, 3);
    try {
        a.SubMatrix(b);
    } catch (const MatrixSizeError& size_error) {
        EXPECT_STREQ("The size of the matrices is different", size_error.what());
    }
}

TEST(sub_matrix, sub2) {
    S21Matrix a(4, 4);
    S21Matrix b(3, 3);
    try {
        a.SubMatrix(b);
    } catch (const MatrixSizeError& size_error) {
        EXPECT_STREQ("The size of the matrices is different", size_error.what());
    }
}

TEST(sub_matrix, sub3) {
    S21Matrix a(3,3), b(3,3);
    a.FillMatrix(MAT10, 9);
    b.FillMatrix(MAT11, 9);
    try {
        a.SubMatrix(b);
        EXPECT_DOUBLE_EQ(a(0, 0), -3);
        EXPECT_DOUBLE_EQ(a(0, 1), -1);
        EXPECT_DOUBLE_EQ(a(0, 2), -2);
        EXPECT_DOUBLE_EQ(a(1, 0), 1);
        EXPECT_DOUBLE_EQ(a(1, 1), -1);
        EXPECT_DOUBLE_EQ(a(1, 2), -7);
        EXPECT_DOUBLE_EQ(a(2, 0), -3);
        EXPECT_DOUBLE_EQ(a(2, 1), 2);
        EXPECT_DOUBLE_EQ(a(2, 2), 4);
    } catch (const exception& err) {
        cout << err.what() << endl;
    }
}

TEST(sub_matrix, sub4) {
    S21Matrix a(2,3), b(2,3);
    a.FillMatrix(MAT5, 6);
    b.FillMatrix(MAT6, 6);
    try {
        a.SubMatrix(b);
        EXPECT_DOUBLE_EQ(a(0, 0), -1);
        EXPECT_DOUBLE_EQ(a(0, 1), -2);
        EXPECT_DOUBLE_EQ(a(0, 2), -3);
        EXPECT_DOUBLE_EQ(a(1, 0), -4);
        EXPECT_DOUBLE_EQ(a(1, 1), -1);
        EXPECT_DOUBLE_EQ(a(1, 2), -4);
    } catch (const exception& err) {
        cout << err.what() << endl;
    }
}

TEST(sub_matrix, sub5) {
    S21Matrix a(1,1), b(1,1);
    double num1[] {3}, num2[] {4};
    a.FillMatrix(num1, 1);
    b.FillMatrix(num2, 1);
    try {
        a.SubMatrix(b);
        EXPECT_DOUBLE_EQ(a(0, 0), -1);
    } catch (const char * error_message) {
        cout << error_message << endl;
    }
}

TEST(sum_matrix, sum1) {
    S21Matrix a(2, 3);
    S21Matrix b(3, 3);
    try {
        a.SumMatrix(b);
    } catch (const MatrixSizeError& size_error) {
        EXPECT_STREQ("The size of the matrices is different", size_error.what());
    }
}

TEST(sum_matrix, sum2) {
    S21Matrix a(4, 4);
    S21Matrix b(3, 3);
    try {
        a.SumMatrix(b);
    } catch (const MatrixSizeError& size_error) {
        EXPECT_STREQ("The size of the matrices is different", size_error.what());
    }
}

TEST(sum_matrix, sum3) {
    S21Matrix a(3,3), b(3,3);
    a.FillMatrix(MAT10, 9);
    b.FillMatrix(MAT11, 9);
    try {
        a.SumMatrix(b);
        EXPECT_DOUBLE_EQ(a(0, 0), -1);
        EXPECT_DOUBLE_EQ(a(0, 1), 3);
        EXPECT_DOUBLE_EQ(a(0, 2), 4);
        EXPECT_DOUBLE_EQ(a(1, 0), 1);
        EXPECT_DOUBLE_EQ(a(1, 1), 7);
        EXPECT_DOUBLE_EQ(a(1, 2), -3);
        EXPECT_DOUBLE_EQ(a(2, 0), 7);
        EXPECT_DOUBLE_EQ(a(2, 1), 6);
        EXPECT_DOUBLE_EQ(a(2, 2), 6);
    } catch (const exception& err) {
        cout << err.what() << endl;
    }
}

TEST(sum_matrix, sum4) {
    S21Matrix a(2,3), b(2,3);
    a.FillMatrix(MAT5, 6);
    b.FillMatrix(MAT6, 6);
    try {
        a.SumMatrix(b);
        EXPECT_DOUBLE_EQ(a(0, 0), 1);
        EXPECT_DOUBLE_EQ(a(0, 1), 2);
        EXPECT_DOUBLE_EQ(a(0, 2), 3);
        EXPECT_DOUBLE_EQ(a(1, 0), 4);
        EXPECT_DOUBLE_EQ(a(1, 1), 1);
        EXPECT_DOUBLE_EQ(a(1, 2), 4);
    } catch (const exception& err) {
        cout << err.what() << endl;
    }
}

TEST(sum_matrix, sum5) {
    S21Matrix a(1,1), b(1,1);
    double num1[] {3}, num2[] {4};
    a.FillMatrix(num1, 1);
    b.FillMatrix(num2, 1);
    try {
        a.SumMatrix(b);
        EXPECT_DOUBLE_EQ(a(0, 0), 7);
    } catch (const char * error_message) {
        cout << error_message << endl;
    }
}

TEST(equals, eq1) {
    S21Matrix a;
    a.FillMatrix(MAT12, 9);
    S21Matrix b(a);
    EXPECT_EQ(true, a.EqMatrix(b));
}

TEST(equals, eq2) {
    S21Matrix a, b;
    a.FillMatrix(MAT12, 9);
    b.FillMatrix(MAT11, 9);
    EXPECT_EQ(false, a.EqMatrix(b));
}

TEST(equals, eq3) {
    S21Matrix a(2, 3), b(3, 2);
    a.FillMatrix(MAT12, 6);
    b.FillMatrix(MAT12, 6);
    EXPECT_EQ(false, a.EqMatrix(b));
}

TEST(constructor, con1) {
    try {
        S21Matrix p(-1, 1);
    } catch (const std::exception& ex) {
        EXPECT_STREQ(ex.what(), "Values ain't be less or equal to 0");
    }
}

TEST(constructor, con2) {
    try {
        S21Matrix p(1, -1);
    } catch (const std::exception& ex) {
        EXPECT_STREQ(ex.what(), "Values ain't be less or equal to 0");
    }
}

TEST(constructor, con3) {
    S21Matrix p(2,3);
    p.FillMatrix(MAT1, 6);
    S21Matrix res(p);
    EXPECT_EQ(true, p.EqMatrix(res));
}

TEST(constructor, con4) {
    try {
        S21Matrix p(2,3);
        p.SetCol(0);
        S21Matrix res(p);
    } catch (const std::exception& ex) {
        EXPECT_STREQ(ex.what(), "Col less than or equal to 0 is invalid");
    }
}

TEST(constructor, con5) {
    try {
        S21Matrix p(2,3);
        p.SetRow(0);
        S21Matrix res(p);
    } catch (const std::exception& ex) {
        EXPECT_STREQ(ex.what(), "Row less than or equal to 0 is invalid");
    }
}

TEST(constructor, con6) {
    S21Matrix p(2,3);
    p.SetRow(4);
    EXPECT_EQ(4, p.GetRow());
    EXPECT_EQ(3, p.GetCol());
}

TEST(constructor, con7) {
    S21Matrix p(4,3);
    p.FillMatrix(MAT1, 12);
    p.SetCol(40);
    EXPECT_EQ(4, p.GetRow());
    EXPECT_EQ(40, p.GetCol());
}

TEST(Determinant, det1) {
    S21Matrix a(2,3);
    try {
        a.Determinant();
    } catch (const MatrixSizeError& error_message) {
        EXPECT_STREQ("The Determinant exists only for a square matrix", error_message.what());
    }
}

TEST(Determinant, det2) {
    S21Matrix a(1,2);
    try {
        a.Determinant();
    } catch (const MatrixSizeError& error_message) {
        EXPECT_STREQ("The Determinant exists only for a square matrix", error_message.what());
    }
}

TEST(Determinant, det3) {
    S21Matrix a(3,3);
    a.FillMatrix(MAT10, 9);
    try {
        EXPECT_EQ(-87, a.Determinant());
    } catch (const char *error_message) {
        cout << error_message << endl; 
    }
}

TEST(Determinant, det4) {
    S21Matrix a(3,3);
    a.FillMatrix(MAT1, 9);
    try {
        EXPECT_EQ(12, a.Determinant());
    } catch (const exception& error_message) {
        cout << error_message.what() << endl; 
    }
}

TEST(Determinant, det5) {
    S21Matrix a(1,1);
    a.FillMatrix(MAT6, 1);
    try {
        EXPECT_EQ(1, a.Determinant());
    } catch (const exception& error_message) {
        cout << error_message.what() << endl; 
    }
}

TEST(Determinant, det6) {
    S21Matrix a(2,2);
    a.FillMatrix(MAT6, 4);
    try {
        EXPECT_EQ(-2, a.Determinant());
    } catch (const exception& error_message) {
        cout << error_message.what() << endl; 
    }
}

TEST(Transpose, tran1) {
    S21Matrix a, c;
    c.FillMatrix(MAT12, 9);
    a = c;
    try {
        S21Matrix b = a.Transpose();
        EXPECT_DOUBLE_EQ(b(0,0), 2);
        EXPECT_DOUBLE_EQ(b(0,1), 6);
        EXPECT_DOUBLE_EQ(b(0,2), 5);
        EXPECT_DOUBLE_EQ(b(1,0), 5);
        EXPECT_DOUBLE_EQ(b(1,1), 3);
        EXPECT_DOUBLE_EQ(b(1,2), -2);
        EXPECT_DOUBLE_EQ(b(2,0), 7);
        EXPECT_DOUBLE_EQ(b(2,1), 4);
        EXPECT_DOUBLE_EQ(b(2,2), -3);
    } catch (const char *error_message) {
        cout << error_message << endl;
    }
}

TEST(Transpose, tran2) {
    S21Matrix a(1, 4);
    a.FillMatrix(MAT9, 4);
    try {
        S21Matrix b = a.Transpose();
        EXPECT_DOUBLE_EQ(b(0,0), 0);
        EXPECT_DOUBLE_EQ(b(1,0), 2);
        EXPECT_DOUBLE_EQ(b(2,0), 3);
        EXPECT_DOUBLE_EQ(b(3,0), 1);
    } catch (const char *error_message) {
        cout << error_message << endl;
    }
}

TEST(calc_complements, calc1) {
    S21Matrix a;
    a.FillMatrix(MAT11, 9);
    try {
        S21Matrix b = a.CalcComplements();
        EXPECT_DOUBLE_EQ(b(0,0), 0);
        EXPECT_DOUBLE_EQ(b(0,1), 10);
        EXPECT_DOUBLE_EQ(b(0,2), -20);
        EXPECT_DOUBLE_EQ(b(1,0), 4);
        EXPECT_DOUBLE_EQ(b(1,1), -14);
        EXPECT_DOUBLE_EQ(b(1,2), 8);
        EXPECT_DOUBLE_EQ(b(2,0), -8);
        EXPECT_DOUBLE_EQ(b(2,1), -2);
        EXPECT_DOUBLE_EQ(b(2,2), 4);
    } catch (const char *error_message) {
        cout << error_message << endl;
    }
}

TEST(calc_complements, calc2) {
    S21Matrix a(2, 2);
    a.FillMatrix(MAT1, 4);
    try {
        S21Matrix b = a.CalcComplements();
        EXPECT_DOUBLE_EQ(b(0,0), 4);
        EXPECT_DOUBLE_EQ(b(0,1), -3);
        EXPECT_DOUBLE_EQ(b(1,0), -2);
        EXPECT_DOUBLE_EQ(b(1,1), 1);
    } catch (const char *error_message) {
        cout << error_message << endl;
    }
}

TEST(calc_complements, calc3) {
    S21Matrix a(1, 1);
    a.FillMatrix(MAT7, 1);
    try {
        S21Matrix b = a.CalcComplements();
        EXPECT_DOUBLE_EQ(b(0,0), 1);
    } catch (const char *error_message) {
        cout << error_message << endl;
    }
}

TEST(inverse, in1) {
    S21Matrix a(3, 3);
    a.FillMatrix(MAT12, 9);
    try {
        S21Matrix b = a.InverseMatrix();
        EXPECT_DOUBLE_EQ(b(0,0), 1);
        EXPECT_DOUBLE_EQ(b(0,1), -1);
        EXPECT_DOUBLE_EQ(b(0,2), 1);
        EXPECT_DOUBLE_EQ(b(1,0), -38);
        EXPECT_DOUBLE_EQ(b(1,1), 41);
        EXPECT_DOUBLE_EQ(b(1,2), -34);
        EXPECT_DOUBLE_EQ(b(2,0), 27);
        EXPECT_DOUBLE_EQ(b(2,1), -29);
        EXPECT_DOUBLE_EQ(b(2,2), 24);
    } catch (const exception &error_message) {
        cout << error_message.what() << endl;
    }
}

TEST(inverse, in2) {
    S21Matrix a(2, 2);
    a.FillMatrix(MAT8, 4);
    try {
        S21Matrix b = a.InverseMatrix();
        EXPECT_DOUBLE_EQ(b(0,0), 0.2);
        EXPECT_DOUBLE_EQ(b(0,1), 0.1);
        EXPECT_DOUBLE_EQ(b(1,0), 0);
        EXPECT_DOUBLE_EQ(b(1,1), 0.5);
    } catch (const exception &error_message) {
        cout << error_message.what() << endl;
    }
}

TEST(inverse, in3) {
    S21Matrix a(1, 1);
    a.FillMatrix(MAT12, 1);
    try {
        S21Matrix b = a.InverseMatrix();
    } catch (const MatrixCalculationError &error_message) {
        EXPECT_STREQ("The number of rows must be greater than 1", error_message.what());
    }
}

TEST(inverse, in4) {
    S21Matrix a(3, 1);
    a.FillMatrix(MAT12, 3);
    try {
        S21Matrix b = a.InverseMatrix();
    } catch (const MatrixSizeError &error_message) {
        EXPECT_STREQ("The Determinant exists only for a square matrix", error_message.what());
    }
}

TEST(sum_matrix_op, sum_mat_op) {
  S21Matrix a, b;
  a.FillMatrix(MAT11, 9);
  b.FillMatrix(MAT12, 9);
  S21Matrix res = a + b;
  EXPECT_DOUBLE_EQ(res(0, 0), 3);
  EXPECT_DOUBLE_EQ(res(0, 1), 7);
  EXPECT_DOUBLE_EQ(res(0, 2), 10);
  EXPECT_DOUBLE_EQ(res(1, 0), 6);
  EXPECT_DOUBLE_EQ(res(1, 1), 7);
  EXPECT_DOUBLE_EQ(res(1, 2), 6);
  EXPECT_DOUBLE_EQ(res(2, 0), 10);
  EXPECT_DOUBLE_EQ(res(2, 1), 0);
  EXPECT_DOUBLE_EQ(res(2, 2), -2);
}

TEST(sub_matrix_op, sub_mat_op) {
  S21Matrix a, b;
  a.FillMatrix(MAT11, 9);
  b.FillMatrix(MAT12, 9);
  S21Matrix res = a - b;
  EXPECT_DOUBLE_EQ(res(0, 0), -1);
  EXPECT_DOUBLE_EQ(res(0, 1), -3);
  EXPECT_DOUBLE_EQ(res(0, 2), -4);
  EXPECT_DOUBLE_EQ(res(1, 0), -6);
  EXPECT_DOUBLE_EQ(res(1, 1), 1);
  EXPECT_DOUBLE_EQ(res(1, 2), -2);
  EXPECT_DOUBLE_EQ(res(2, 0), 0);
  EXPECT_DOUBLE_EQ(res(2, 1), 4);
  EXPECT_DOUBLE_EQ(res(2, 2), 4);
}

TEST(eq_matrix_op, eq_mat_op) {
  S21Matrix a, b;
  a.FillMatrix(MAT12, 9);
  b.FillMatrix(MAT12, 9);
  a(1, 1) = 1.22233129;
  b(1, 1) = 1.22233128;
  EXPECT_TRUE(a == b);
  b(1, 1) = 1.2223314;
  EXPECT_FALSE(a == b);
  b(1, 1) = 1.22233128;
  EXPECT_TRUE(a == b);
  a.SetRow(4);
  a.SetCol(3);
  EXPECT_FALSE(a == b);
}

TEST(mul_number_op, mul_num_op) {
  S21Matrix a;
  a.FillMatrix(MAT11, 9);
  S21Matrix b = a * 2.00;
  EXPECT_DOUBLE_EQ(b(0, 0), 2);
  EXPECT_DOUBLE_EQ(b(0, 1), 4);
  EXPECT_DOUBLE_EQ(b(0, 2), 6);
  EXPECT_DOUBLE_EQ(b(1, 0), 0);
  EXPECT_DOUBLE_EQ(b(1, 1), 8);
  EXPECT_DOUBLE_EQ(b(1, 2), 4);
  EXPECT_DOUBLE_EQ(b(2, 0), 10);
  EXPECT_DOUBLE_EQ(b(2, 1), 4);
  EXPECT_DOUBLE_EQ(b(2, 2), 2);
  S21Matrix res = 0.5 * b;
  EXPECT_DOUBLE_EQ(res(0, 0), 1);
  EXPECT_DOUBLE_EQ(res(0, 1), 2);
  EXPECT_DOUBLE_EQ(res(0, 2), 3);
  EXPECT_DOUBLE_EQ(res(1, 0), 0);
  EXPECT_DOUBLE_EQ(res(1, 1), 4);
  EXPECT_DOUBLE_EQ(res(1, 2), 2);
  EXPECT_DOUBLE_EQ(res(2, 0), 5);
  EXPECT_DOUBLE_EQ(res(2, 1), 2);
  EXPECT_DOUBLE_EQ(res(2, 2), 1);
}

TEST(mul_matrix_op, mul_mat_op) {
  S21Matrix a, b;
  a.FillMatrix(MAT11, 9);
  b.FillMatrix(MAT12, 9);
  S21Matrix res = a * b;
  EXPECT_DOUBLE_EQ(res(0, 0), 29);
  EXPECT_DOUBLE_EQ(res(0, 1), 5);
  EXPECT_DOUBLE_EQ(res(0, 2), 6);
  EXPECT_DOUBLE_EQ(res(1, 0), 34);
  EXPECT_DOUBLE_EQ(res(1, 1), 8);
  EXPECT_DOUBLE_EQ(res(1, 2), 10);
  EXPECT_DOUBLE_EQ(res(2, 0), 27);
  EXPECT_DOUBLE_EQ(res(2, 1), 29);
  EXPECT_DOUBLE_EQ(res(2, 2), 40);
}

TEST(sum_eq_op, sum_eq_op) {
  S21Matrix a, b;
  a.FillMatrix(MAT11, 9);
  b.FillMatrix(MAT12, 9);
  a += b;
  EXPECT_DOUBLE_EQ(a(0, 0), 3);
  EXPECT_DOUBLE_EQ(a(0, 1), 7);
  EXPECT_DOUBLE_EQ(a(0, 2), 10);
  EXPECT_DOUBLE_EQ(a(1, 0), 6);
  EXPECT_DOUBLE_EQ(a(1, 1), 7);
  EXPECT_DOUBLE_EQ(a(1, 2), 6);
  EXPECT_DOUBLE_EQ(a(2, 0), 10);
  EXPECT_DOUBLE_EQ(a(2, 1), 0);
  EXPECT_DOUBLE_EQ(a(2, 2), -2);
}

TEST(sum_eq_op, sum_eq_op_err) {
  S21Matrix a(2, 3), b;
  a.FillMatrix(MAT11, 6);
  b.FillMatrix(MAT12, 9);
  try {
        a += b;
  } catch (exception &e) {
        EXPECT_STREQ("The size of the matrices is different", e.what());
  }
}

TEST(sub_eq_op, sub_eq_op) {
  S21Matrix a, b;
  a.FillMatrix(MAT11, 9);
  b.FillMatrix(MAT12, 9);
  a -= b;
  EXPECT_DOUBLE_EQ(a(0, 0), -1);
  EXPECT_DOUBLE_EQ(a(0, 1), -3);
  EXPECT_DOUBLE_EQ(a(0, 2), -4);
  EXPECT_DOUBLE_EQ(a(1, 0), -6);
  EXPECT_DOUBLE_EQ(a(1, 1), 1);
  EXPECT_DOUBLE_EQ(a(1, 2), -2);
  EXPECT_DOUBLE_EQ(a(2, 0), 0);
  EXPECT_DOUBLE_EQ(a(2, 1), 4);
  EXPECT_DOUBLE_EQ(a(2, 2), 4);
}

TEST(sub_eq_op, sub_eq_op_err) {
  S21Matrix a(2, 3), b;
  a.FillMatrix(MAT11, 6);
  b.FillMatrix(MAT12, 9);
  try {
        a -= b;
  } catch (exception &e) {
        EXPECT_STREQ("The size of the matrices is different", e.what());
  }
}

TEST(mul_num_eq_op, mul_num_eq_op) {
  S21Matrix a;
  a.FillMatrix(MAT11, 9);
  a *= 2.00;
  EXPECT_DOUBLE_EQ(a(0, 0), 2);
  EXPECT_DOUBLE_EQ(a(0, 1), 4);
  EXPECT_DOUBLE_EQ(a(0, 2), 6);
  EXPECT_DOUBLE_EQ(a(1, 0), 0);
  EXPECT_DOUBLE_EQ(a(1, 1), 8);
  EXPECT_DOUBLE_EQ(a(1, 2), 4);
  EXPECT_DOUBLE_EQ(a(2, 0), 10);
  EXPECT_DOUBLE_EQ(a(2, 1), 4);
  EXPECT_DOUBLE_EQ(a(2, 2), 2);
}

TEST(mul_mat_eq_op, mul_mat_eq_op) {
  S21Matrix a, b;
  a.FillMatrix(MAT11, 9);
  b.FillMatrix(MAT12, 9);
  a *= b;
  EXPECT_DOUBLE_EQ(a(0, 0), 29);
  EXPECT_DOUBLE_EQ(a(0, 1), 5);
  EXPECT_DOUBLE_EQ(a(0, 2), 6);
  EXPECT_DOUBLE_EQ(a(1, 0), 34);
  EXPECT_DOUBLE_EQ(a(1, 1), 8);
  EXPECT_DOUBLE_EQ(a(1, 2), 10);
  EXPECT_DOUBLE_EQ(a(2, 0), 27);
  EXPECT_DOUBLE_EQ(a(2, 1), 29);
  EXPECT_DOUBLE_EQ(a(2, 2), 40);
}
