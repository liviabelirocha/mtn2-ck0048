#include "GaussLegendre.hpp"

GaussLegendre::GaussLegendre(double a, double b, double N, double tol)
{
    a_ = a;
    b_ = b;
    N_ = N;
    tol_ = tol;

    cout << "Integral de " << a << " até " << b << "." << endl
         << "Com " << N << " partições e tolerância de " << tol_ << "." << endl
         << endl;
}

double GaussLegendre::f(double x)
{ //f(x) = (sen(2x) + 4x^2+ 3x)^2
    double var = sin(2 * x) + 4 * pow(x, 2) + 3 * x;
    return pow(var, 2);
}

double GaussLegendre::x(double ak, double xi, double xf)
{
    return (xi + xf) / 2 + ((xf - xi) / 2) * ak;
}

double GaussLegendre::integralParticao(int pontosInterpolacao, const double *w, const double *a)
{
    double I = 0, delta = (b_ - a_) / N_,
           xi, xf, sum;

    for (int i = 0; i < N_; i++)
    {
        xi = a_ + i * delta;
        xf = xi + delta;
        sum = 0;
        for (int k = 0; k < pontosInterpolacao; k++)
        {
            //cout << k << " : " << w[k] << endl;
            sum += w[k] * f(x(a[k], xi, xf));
        }
        I += ((xf - xi) / 2) * sum;
    }

    return I;
}

double GaussLegendre::integralTolerancia(int pontosInterpolacao, const double *w, const double *a)
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

        delta = (b_ - a_) / N;

        while (count < N)
        {
            xi = a_ + count * delta;
            xf = xi + delta;
            sum = 0;

            for (int k = 0; k < pontosInterpolacao; k++)
            {
                sum += (w[k] * f(x(a[k], xi, xf)));
            }

            In += ((xf - xi) / 2) * sum;
            count++;
        }

        N *= 2;
        tol = (double)fabs((In - Iv) / In);

    } while (tol > tol_);

    return In;
}

double GaussLegendre::pontosInterpolacao2(int t)
{
    double a[2], w[2];

    a[0] = -0.57735;
    a[1] = 0.57735;

    w[0] = w[1] = 1;

    switch (t)
    {
    case 1:
        return integralParticao(2, w, a);
        break;
    case 2:
        return integralTolerancia(2, w, a);
        break;
    default:
        return 0;
    }
}

double GaussLegendre::pontosInterpolacao3(int t)
{
    double a[3], w[3];

    a[0] = -0.7746;
    a[1] = 0;
    a[2] = 0.7746;

    w[0] = 0.5555;
    w[1] = 0.8888;
    w[2] = 0.5555;

    switch (t)
    {
    case 1:
        return integralParticao(3, w, a);
        break;
    case 2:
        return integralTolerancia(3, w, a);
        break;
    default:
        return 0;
    }
}