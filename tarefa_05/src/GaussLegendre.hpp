#ifndef GAUSSLEGENDRE_HPP
#define GAUSSLEGENDRE_HPP

#include <iostream>
#include <cmath>

using namespace std;

class GaussLegendre
{
private:
    double a_, b_, tol_, N_;
    double f(double x);
    double x(double ak, double xi, double xf);

public:
    GaussLegendre(double a, double b, double N, double tol);

    double integralParticao(int pontosInterpolacao, const double *w, const double *a);
    double integralTolerancia(int pontosInterpolacao, const double *w, const double *a);

    double pontosInterpolacao2(int t);
    double pontosInterpolacao3(int t);
    double pontosInterpolacao4(int t);
};

#endif