#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/* Protótipo das funções */
double f(double x);
double x(int k, int n);
double integral(int iter, double *w, double *x);
double hermite2();
double hermite3();
double laguerre2();
double laguerre3();
double chebychev(int n);

/* Main */
int main()
{
    cout << "Tarefa 6: Quadraturas de Gauss-Hermite, Gauss-Laguerre e Gauss-Chebyshev" << endl
         << "FUNÇÃO : f(x) = (sen(2x) + 4x^2+ 3x)^2" << endl
         << endl;

    cout << setprecision(10)
         << "GAUSS-HERMITE" << endl
         << "GRAU 2 = " << hermite2() << endl
         << "GRAU 3 = " << hermite3() << endl
         << endl
         << "GAUSS-LAGUERRE" << endl
         << "GRAU 2 = " << laguerre2() << endl
         << "GRAU 3 = " << laguerre3() << endl
         << endl
         << "GAUSS-CHEBYSHEV" << endl
         << "GRAU 2 = " << chebychev(2) << endl
         << "GRAU 3 = " << chebychev(3) << endl;
    return 0;
}

double f(double x)
{ //f(x) = (sen(2x) + 4x^2+ 3x)^2
    double var = sin(2 * x) + 4 * pow(x, 2) + 3 * x;
    return pow(var, 2);
}

double x(int k, int n)
{
    return cos((2 * k - 1) * M_PI / (2 * n));
}

double integral(int iter, double *w, double *x)
{
    double I = 0;
    for (int i = 0; i < iter; i++)
        I += w[i] * f(x[i]);
    return I;
}

double hermite2()
{
    double w[2], x[2];

    w[0] = w[1] = 0.8862269254;

    x[0] = -0.7071067811;
    x[1] = -x[0];

    return integral(2, w, x);
}

double hermite3()
{
    double w[3], x[3];

    w[0] = w[2] = 0.2954089751;
    w[1] = 1.1816359;

    x[0] = -1.224744871;
    x[1] = 0;
    x[2] = -x[0];

    return integral(3, w, x);
}

double laguerre2()
{
    double w[2], x[2];

    w[0] = 0.8535533905;
    w[1] = 0.1464466094;

    x[0] = 0.5857864376;
    x[1] = 3.414213562;

    return integral(2, w, x);
}

double laguerre3()
{
    double w[3], x[3];

    w[0] = 0.7110930099;
    w[1] = 0.2785177336;
    w[2] = 0.0103892565;

    x[0] = 0.4157745568;
    x[1] = 2.2942803603;
    x[2] = 6.2899450829;

    return integral(3, w, x);
}

double chebychev(int n)
{
    double I = 0, w = M_PI / n;

    for (int i = 1; i <= n; i++)
        I += w * (f(x(i, n)));

    return I;
}