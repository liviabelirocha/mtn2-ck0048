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
    vector<vector<double>> L_, U_;
    Matrix();
    Matrix(int size);
    Matrix(vector<vector<double>> matrix);
    void setElement(int i, int j, double element);
    VectorN operator*(VectorN v);
    Matrix operator-(double n);
    int getSize();
    int getElement(int i, int j);
    void print();
    void print(Matrix m);
    void identity();
    void decompLU();
};

#endif