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
    double tol_;

public:
    Power(Matrix matrix, VectorN arbitratyVector, double tol);
    void RegularPower();
};

#endif