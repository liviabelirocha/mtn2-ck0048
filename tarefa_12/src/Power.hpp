#ifndef POWER_HPP
#define POWER_HPP

#include <iostream>
#include <cmath>
#include <vector>

#include "Matrix.hpp"
#include "VectorN.hpp"

using namespace std;

class Power
{
private:
    Matrix matrix_;
    VectorN arbitratyVector_;
    double tol_, mi_;

public:
    Power(Matrix matrix, VectorN arbitratyVector, double tol, double mi);
    VectorN solveLU(VectorN x, int n);
    VectorN retroativeIteractions(vector<vector<double>> m, VectorN v);
    VectorN sucessiveIteractions(vector<vector<double>> m, VectorN v);
    void InversePower();
    void DisplacementPower();
};

#endif