#ifndef INTEGRAL_HPP
#define INTEGRAL_HPP

#include "NewtonCotes.hpp"
#include "GaussLegendre.hpp"

class Integral
{
private:
    double a_, b_, tol_, c_;
    NewtonCotes nc;
    GaussLegendre gl;
    double method(int m, double c1, double c2);
    double integrar(int m);

public:
    Integral(double a, double b, double tol, double c, int type);
    void showResults();
};

#endif