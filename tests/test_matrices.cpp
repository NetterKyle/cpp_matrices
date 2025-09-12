#include <iostream>
#include "matrices.h"

int main()
{
    Matrix<int> mat(2, 2, 0);

    mat(0,0) = 1;
    mat(0,1) = 2;
    mat(1,0) = 3;
    mat(1,1) = 4;

    auto norm = mat.calc_norm();

    std::cout << "Norm: " << norm;
}