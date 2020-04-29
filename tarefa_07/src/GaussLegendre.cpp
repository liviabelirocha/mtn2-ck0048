#include "GaussLegendre.hpp"

GaussLegendre::GaussLegendre()
{
    e_ = Exponencial();
    tol_ = 0;
}

GaussLegendre::GaussLegendre(double a, double b, double tol, int type)
{
    e_ = Exponencial(a, b, type);
    tol_ = tol;
}

double GaussLegendre::x(double ak, double xi, double xf)
{
    return (xi + xf) / 2 + ((xf - xi) / 2) * ak;
}

double GaussLegendre::integral(int pontosInterpolacao, double *w, double *a, double c1, double c2)
{
    double Iv, In = 0,
               delta, sum,
               xi, xf, tol = 1;
    int count, N = 1;

    do
    {
        Iv = In;
        In = 0;
        count = 0;

        delta = (c2 - c1) / N;

        while (count < N)
        {
            xi = c1 + count * delta;
            xf = xi + delta;
            sum = 0;

            for (int k = 0; k < pontosInterpolacao; k++)
                sum += (w[k] * e_.fb(x(a[k], xi, xf)));

            In += ((xf - xi) / 2) * sum;
            count++;
        }

        N *= 2;
        tol = (double)fabs((In - Iv) / In);

    } while (tol > tol_);

    return In;
}

double GaussLegendre::pontosInterpolacao2(double c1, double c2)
{
    double a[2], w[2];

    a[0] = -0.5773502691;
    a[1] = -a[0];

    w[0] = w[1] = 1;

    return integral(2, w, a, c1, c2);
}

double GaussLegendre::pontosInterpolacao3(double c1, double c2)
{
    double a[3], w[3];

    a[0] = -0.7745966692;
    a[1] = 0;
    a[2] = -a[0];

    w[0] = w[2] = 0.5555555555;
    w[1] = 0.8888888888;

    return integral(3, w, a, c1, c2);
}

double GaussLegendre::pontosInterpolacao4(double c1, double c2)
{
    double a[4], w[4];

    a[0] = 0.8611363115;
    a[1] = -a[0];
    a[2] = 0.3399810435;
    a[3] = -a[2];

    w[0] = w[1] = 0.3478548451;
    w[2] = w[3] = 0.6521451548;

    return integral(4, w, a, c1, c2);
}
