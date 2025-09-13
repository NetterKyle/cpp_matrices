#include <iostream>
#include "matrices.h"

void test_norm(void)
{
    Matrix<double> mat(2, 2, 0);

    mat(0,0) = 1;
    mat(0,1) = 2;
    mat(1,0) = 3;
    mat(1,1) = 4;

    double norm = mat.calc_norm();

    std::cout << "Norm: " << norm  << "\n";
}

void test_matrix_multiply(void)
{
    Matrix<double> mat1(2, 2, 0);
    Matrix<double> mat2(2, 2, 0);

    mat1(0,0) = 1;
    mat1(0,1) = 2;
    mat1(1,0) = 3;
    mat1(1,1) = 4;


    mat2(0,0) = 5;
    mat2(0,1) = 6;
    mat2(1,0) = 7;
    mat2(1,1) = 8;

    std::cout << "Multiplied Matrices: ";
    Matrix<double> matrices_multiplied(2, 2, 0);

    matrices_multiplied = mat1 * mat2;

    matrices_multiplied.print_data();
}

void test_add_matrices(void)
{
    Matrix<double> mat1(2, 2, 0);
    Matrix<double> mat2(2, 2, 0);

    mat1(0,0) = 1;
    mat1(0,1) = 2;
    mat1(1,0) = 3;
    mat1(1,1) = 4;

    mat2(0,0) = 5;
    mat2(0,1) = 6;
    mat2(1,0) = 7;
    mat2(1,1) = 8;

    Matrix<double> sum_matrix(2, 2, 0);

    sum_matrix = mat1 + mat2;

    std::cout << "Summed Matrices: ";
    sum_matrix.print_data();
}

void test_subtract_matrices(void)
{    
    Matrix<double> mat1(2, 2, 0);
    Matrix<double> mat2(2, 2, 0);

    mat1(0,0) = 1;
    mat1(0,1) = 2;
    mat1(1,0) = 3;
    mat1(1,1) = 4;

    mat2(0,0) = 5;
    mat2(0,1) = 6;
    mat2(1,0) = 7;
    mat2(1,1) = 8;

    Matrix<double> sum_matrix(2, 2, 0);

    sum_matrix = mat1 - mat2;

    std::cout << "Subtracted Matrices: ";
    sum_matrix.print_data();
}

int main()
{
    test_norm();
    test_matrix_multiply();
    test_add_matrices();
    test_subtract_matrices();

    return 0;
}