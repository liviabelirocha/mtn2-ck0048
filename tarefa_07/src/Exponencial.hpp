#ifndef EXPONENCIAL_HPP
#define EXPONENCIAL_HPP

#include <cmath>
#include <iostream>

using namespace std;

class Exponencial
{
private:
    double a_, b_;
    int type_;
    double f(double x);
    double xs(double s);
    double dxs(double s);

public:
    Exponencial();
    Exponencial(double a, double b, int type);
    double fb(double x);
};

#endif