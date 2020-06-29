#ifndef EIGENVECTORS_HPP
#define EIGENVECTORS_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

#include "Matrix.hpp"
#include "VectorN.hpp"

using namespace std;

class EigenVectors
{
private:
    Matrix matrix_;
    VectorN arbitratyVector_;
    double tol_;

public:
    EigenVectors(Matrix matrix, VectorN arbitraryVector, double tol);

    VectorN solveLU(VectorN x, int n, Matrix matrix);
    VectorN retroativeIteractions(vector<vector<double>> m, VectorN v);
    VectorN sucessiveIteractions(vector<vector<double>> m, VectorN v);

    Matrix constructHouseHolder(Matrix A, int i);
    void houseHolder();

    tuple<double, VectorN, VectorN> regularPower(Matrix m, Matrix H);
    tuple<double, VectorN, VectorN> InversePower(Matrix m, Matrix H);
    tuple<double, VectorN, VectorN> DisplacementPower(double mi, Matrix A, Matrix H);

    void showResults(Matrix A_barra, Matrix H);
    void printResults(VectorN autovector, double autovalue, VectorN autovectorA);
};

#endif