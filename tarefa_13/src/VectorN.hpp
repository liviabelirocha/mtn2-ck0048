#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class VectorN
{
private:
    int size_;
    vector<double> vector_;

public:
    VectorN();
    VectorN(int size);
    void setElement(int i, double element);
    int getSize();
    double getElement(int i);
    double norm();
    void normalize();
    void copyVector(VectorN v);
    double operator*(VectorN v);
    VectorN operator-(VectorN v);
    void print();
};

#endif