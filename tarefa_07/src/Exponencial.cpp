#include "Exponencial.hpp"

Exponencial::Exponencial()
{
    a_ = 0;
    b_ = 0;
}

Exponencial::Exponencial(double a, double b, int type)
{
    a_ = a;
    b_ = b;
    type_ = type;
}

double Exponencial::f(double x)
{
    return 1 / pow(x, 1 / 2);
    //return 1 / pow(pow(x, 2.0), 1 / 2);
    //return 1 / pow(4 - (x * x), 1 / 2);
}

double Exponencial::xs(double s)
{
    switch (type_)
    {
    case 1:
        return ((a_ + b_) / 2.0 + (b_ - a_) * tanh(s) / 2.0);
    case 2:
        return (((a_ + b_) / 2.0) + (((b_ - a_) / 2.0) * tanh((M_PI / 2.0) * sinh(s))));
    default:
        return 0;
    }
}

double Exponencial::dxs(double s)
{
    switch (type_)
    {
    case 1:
        return (b_ - a_) / (2 * (pow(cosh(s), 2)));
    case 2:
        return ((b_ - a_) / 2.0) * ((M_PI / 2.0) * (cosh(s) / pow(cosh((M_PI / 2.0) * sinh(s)), 2.0)));
    default:
        return 0;
    }
}

double Exponencial::fb(double s) { return f(xs(s)) * dxs(s); }