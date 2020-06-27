#ifndef HOUSEHOLDER_HPP
#define HOUSEHOLDER_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

#include "Matrix.hpp"
#include "VectorN.hpp"

using namespace std;

class Householder
{
private:
    Matrix matrix_;
    VectorN arbitratyVector_;
    double tol_, mi_;

public:
    Householder(Matrix matrix);
    Matrix constructHouseHolder(Matrix A, int i);
    void houseHolder();
};

#endif