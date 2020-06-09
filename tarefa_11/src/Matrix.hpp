#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <cmath>
#include <vector>

#include "VectorN.hpp"

using namespace std;

class Matrix
{
private:
    int size_;
    vector<vector<double>> matrix_;

public:
    Matrix();
    Matrix(int size);
    void setElement(int i, int j, double element);
    VectorN operator*(VectorN v);
    int getSize();
    void print();
};

#endif