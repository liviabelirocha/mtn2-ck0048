#ifndef JACOBI_HPP
#define JACOBI_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

#include "Matrix.hpp"
#include "VectorN.hpp"

using namespace std;

class Jacobi
{
private:
    Matrix matrix_;
    double err_;

public:
    Jacobi(Matrix matrix, double err);

    Matrix matrixOldMatrix(Matrix A, int i, int j);
    tuple<Matrix, Matrix> jacobiSweep(Matrix A);
    tuple<Matrix, Matrix, VectorN> jacobiMethod();
    void showResults();
};

#endif