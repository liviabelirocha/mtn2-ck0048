#ifndef EXPONENCIAL_HPP
#define EXPONENCIAL_HPP

#include <cmath>
#include <iostream>

using namespace std;

class Exponencial
{
private:
    double a_, b_, err_;
    int type_;
    double f(double x);
    double x(double s);
    double dx(double s);
    double fb(double x);
    double NewtonCotes(double c1, double c2, int n);

public:
    Exponencial(double a, double b, double err, int type);
    double integrar();
};

#endif