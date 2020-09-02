#ifndef QR_HPP
#define QR_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

#include "Matrix.hpp"
#include "VectorN.hpp"

using namespace std;

class QR
{
private:
    Matrix matrix_;
    double err_;

public:
    QR(Matrix matrix, double err);

    Matrix matrixOldMatrix(Matrix A, int i, int j);
    tuple<Matrix, Matrix> decompQR(Matrix A);
    tuple<Matrix, Matrix, VectorN> QRMethod();
    void showResults();
};

#endif