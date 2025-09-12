#include <iostream>
#include "matrices.h"

int main()
{
    Matrix<double> mat(2, 2, 0);

    mat(0,0) = 1;
    mat(0,1) = 2;
    mat(1,0) = 3;
    mat(1,1) = 4;

    auto norm = mat.calc_norm();

    std::cout << "Norm: " << norm  << "\n";

    Matrix<double> mat2(2, 2, 0);

    mat2(0,0) = 5;
    mat2(0,1) = 6;
    mat2(1,0) = 7;
    mat2(1,1) = 8;

    Matrix<double> matrices_multiplied(2, 2, 0);

    matrices_multiplied = mat * mat2;

    mat.print_data();
    matrices_multiplied.print_data();
}