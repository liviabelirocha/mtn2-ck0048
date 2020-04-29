#include "NewtonCotes.hpp"

NewtonCotes::NewtonCotes()
{
    e_ = Exponencial();
    err_ = 0;
}

NewtonCotes::NewtonCotes(double a, double b, double err, int type)
{
    e_ = Exponencial(a, b, type);
    err_ = err;
}

double NewtonCotes::fechadaGrau1(double c1, double c2)
{
    double Iv, In = 0,
               delta,
               Xi, Xf, err = 1;
    int count, N = 1;

    do
    {
        Iv = In;
        In = 0;
        count = 0;

        delta = (c2 - c1) / N;

        while (count < N)
        {
            Xi = c1 + count * delta;
            Xf = Xi + delta;
            In = In + (delta / 2) * (e_.fb(Xi) + e_.fb(Xf));

            count++;
        }

        N *= 2;
        err = (double)fabs((In - Iv) / In);

    } while (err > err_);

    return In;
}

double NewtonCotes::fechadaGrau2(double c1, double c2)
{
    double Iv, In = 0,
               delta, h,
               X0, X1, X2, err = 1;
    int count, N = 1;

    do
    {
        Iv = In;
        In = 0;
        count = 0;

        delta = (c2 - c1) / N;
        h = delta / 2;

        while (count < N)
        {
            X0 = c1 + count * delta;
            X1 = X0 + h;
            X2 = X1 + h;
            In = In + (delta / 6) * (e_.fb(X0) + 4 * e_.fb(X1) + e_.fb(X2));

            count++;
        }

        N *= 2;
        err = (double)fabs((In - Iv) / In);

    } while (err > err_);

    return In;
}

double NewtonCotes::fechadaGrau3(double c1, double c2)
{
    double Iv, In = 0,
               delta, h,
               X0, X1, X2, X3, err = 1;
    int count, N = 1;

    do
    {
        Iv = In;
        In = 0;
        count = 0;

        delta = (c2 - c1) / N;
        h = delta / 3;

        while (count < N)
        {
            X0 = c1 + count * delta;
            X1 = X0 + h;
            X2 = X1 + h;
            X3 = X2 + h;
            In = In + (delta / 8) * (e_.fb(X0) + 3 * e_.fb(X1) + 3 * e_.fb(X2) + e_.fb(X3));

            count++;
        }

        N *= 2;
        err = (double)fabs((In - Iv) / In);

    } while (err > err_);

    return In;
}

double NewtonCotes::fechadaGrau4(double c1, double c2)
{
    double Iv, In = 0,
               delta, h,
               Xi, Xf, X1, X2, X3, err = 1;
    int count, N = 1;

    do
    {
        Iv = In;
        In = 0;
        count = 0;

        delta = (c2 - c1) / N;
        h = delta / 4;

        while (count < N)
        {
            Xi = c1 + count * delta;
            X1 = Xi + h;
            X2 = X1 + h;
            X3 = X2 + h;
            Xf = Xi + delta;
            In = In + (delta / 90) * (7 * e_.fb(Xi) + 32 * e_.fb(X1) + 12 * e_.fb(X2) + 32 * e_.fb(X3) + 7 * e_.fb(Xf));

            count++;
        }

        N *= 2;
        err = (double)fabs((In - Iv) / In);

    } while (err > err_);

    return In;
}

double NewtonCotes::abertaGrau1(double c1, double c2)
{
    double delta, h, Iv, In = 0, err = 1,
                         xi, x1, x2;
    int count, N = 1;
    do
    {
        Iv = In;
        In = 0;
        count = 0;

        delta = (c2 - c1) / N;
        h = delta / 3;

        while (count < N)
        {
            xi = c1 + count * delta;
            x1 = xi + h;
            x2 = x1 + h;
            In = In + ((delta) / 2) * (e_.fb(x1) + e_.fb(x2));

            count++;
        }

        N *= 2;
        err = (double)fabs((In - Iv) / In);

    } while (err > err_);

    return In;
}

double NewtonCotes::abertaGrau2(double c1, double c2)
{
    double delta, h, Iv, In = 0, err = 1,
                         xi, x1, x2, x3;
    int count, N = 1;
    do
    {
        Iv = In;
        In = 0;
        count = 0;

        delta = (c2 - c1) / N;
        h = delta / 4;

        while (count < N)
        {
            xi = c1 + count * delta;
            x1 = xi + h;
            x2 = x1 + h;
            x3 = x2 + h;
            In = In + (delta / 3) * (2 * e_.fb(x1) - e_.fb(x2) + 2 * e_.fb(x3));

            count++;
        }

        N *= 2;
        err = (double)fabs((In - Iv) / In);

    } while (err > err_);

    return In;
}

double NewtonCotes::abertaGrau3(double c1, double c2)
{
    double delta, h, Iv, In = 0, err = 1,
                         xi, x1, x2, x3, x4;
    int count, N = 1;
    do
    {
        Iv = In;
        In = 0;
        count = 0;

        delta = (c2 - c1) / N;
        h = delta / 5;

        while (count < N)
        {
            xi = c1 + count * delta;
            x1 = xi + h;
            x2 = x1 + h;
            x3 = x2 + h;
            x4 = x3 + h;
            In = In + (delta / 24) * (11 * e_.fb(x1) + e_.fb(x2) + e_.fb(x3) + 11 * e_.fb(x4));

            count++;
        }

        N *= 2;
        err = (double)fabs((In - Iv) / In);

    } while (err > err_);

    return In;
}

double NewtonCotes::abertaGrau4(double c1, double c2)
{
    double delta, h, Iv, In = 0, err = 1,
                         xi, x1, x2, x3, xf;
    int count, N = 1;
    do
    {
        Iv = In;
        In = 0;
        count = 0;

        delta = (c2 - c1) / N;
        h = delta / 6;

        while (count < N)
        {
            xi = c1 + count * delta;
            x1 = xi + h;
            x2 = x1 + h;
            x3 = x2 + h;
            xf = xi + delta;
            In = In + ((delta) / 20) * (11 * e_.fb(xi) - 14 * e_.fb(x1) + 26 * e_.fb(x2) - 14 * e_.fb(x3) + 11 * e_.fb(xf));

            count++;
        }

        N *= 2;
        err = (double)fabs((In - Iv) / In);

    } while (err > err_);

    return In;
}
