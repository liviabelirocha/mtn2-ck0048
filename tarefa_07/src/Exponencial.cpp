#include "Exponencial.hpp"

Exponencial::Exponencial(double a, double b, double err, int type)
{
    a_ = a;
    b_ = b;
    err_ = err;
    type_ = type;

    char *tipo;
    type == 1 ? tipo = (char *)"SIMPLES" : tipo = (char *)"DUPLA";

    cout
        << "Integral " << tipo << " indo de " << a << " até " << b << "." << endl
        << "Com tolerância de " << err << "." << endl
        << endl;
}

double Exponencial::f(double x)
{
    //return 1 / pow(pow(x, 2.0), (1 / 3.0));
    return 1 / pow(4 - (x * x), 1 / 2.0);
}

double Exponencial::x(double s)
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

double Exponencial::dx(double s)
{
    switch (type_)
    {
    case 1:
        return (b_ - a_) / (2 * (pow(cosh(s), 2)));
    case 2:
        return ((b_ - a_) / 2.0) * ((M_PI / 2.0) * (cosh(s) / (pow(cosh((M_PI / 2.0) * sinh(s)), 2.0))));
    default:
        return 0;
    }
}

double Exponencial::fb(double s) { return f(x(s)) * dx(s); }

double Exponencial::NewtonCotes(double c1, double c2, int n)
{
    double delta = (c2 - c1) / n,
           I = 0, Xi, Xf;

    for (int i = 0; i < n; i++)
    {
        Xi = c1 + i * delta;
        Xf = Xi + delta;
        I = I + (delta / 2.0) * (fb(Xi) + fb(Xf));
    }

    return I;
}

double Exponencial::integrar()
{
    double I = 0, In, err, c1 = -1, c2 = 1, i = 0, n = 1;
    int iter = type_ == 1 ? 15 : 3;

    do
    {
        n *= 2;

        In = NewtonCotes(c1, c2, n);
        err = fabs((In - I) / In);

        c1--;
        c2++;

        I = In;

        i++;

    } while (i < iter); // dupla dá infinito ao usar o erro

    cout << "INTEGRAL = " << I << endl;

    return I;
}