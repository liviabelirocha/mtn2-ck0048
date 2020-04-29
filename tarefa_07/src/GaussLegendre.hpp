#ifndef GAUSSLEGENDRE_HPP
#define GAUSSLEGENDRE_HPP

#include <iostream>
#include <cmath>

#include "Exponencial.hpp"

using namespace std;

class GaussLegendre
{
private:
    double tol_;
    Exponencial e_;
    double x(double ak, double xi, double xf);

public:
    GaussLegendre();
    GaussLegendre(double a, double b, double tol, int type);

    double integral(int pontosInterpolacao, double *w, double *a, double c1, double c2);

    double pontosInterpolacao2(double c1, double c2);
    double pontosInterpolacao3(double c1, double c2);
    double pontosInterpolacao4(double c1, double c2);
};

#endif