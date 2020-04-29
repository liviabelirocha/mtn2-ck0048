#include "Integral.hpp"

Integral::Integral(double a, double b, double tol, double c, int type)
{
    nc = NewtonCotes(a, b, tol, type);
    gl = GaussLegendre(a, b, tol, type);
    a_ = a;
    b_ = b;
    c_ = c;
    tol_ = tol;

    char *tipo;
    type == 1 ? tipo = (char *)"SIMPLES" : tipo = (char *)"DUPLA";

    cout
        << "Integral " << tipo << " indo de " << a << " até " << b << "." << endl
        << "C escolhido: +-" << c << "." << endl
        << "Com tolerância de " << tol << "." << endl
        << endl;
}

double Integral::method(int m, double c1, double c2)
{
    switch (m)
    {
    case 1:
        return nc.abertaGrau1(c1, c2);
    case 2:
        return nc.abertaGrau2(c1, c2);
    case 3:
        return nc.abertaGrau3(c1, c2);
    case 4:
        return nc.abertaGrau4(c1, c2);
    case 5:
        return nc.fechadaGrau1(c1, c2);
    case 6:
        return nc.fechadaGrau2(c1, c2);
    case 7:
        return nc.fechadaGrau3(c1, c2);
    case 8:
        return nc.fechadaGrau4(c1, c2);
    case 9:
        return gl.pontosInterpolacao2(c1, c2);
    case 10:
        return gl.pontosInterpolacao3(c1, c2);
    case 11:
        return gl.pontosInterpolacao4(c1, c2);
    default:
        return 0;
    }
}

double Integral::integrar(int m)
{
    double I, I0, err, c1, c2;

    c1 = -c_;
    c2 = c_;

    I = 0;
    do
    {
        I0 = I;
        I = method(m, c1, c2);

        c1--;
        c2++;

        err = fabs((I - I0) / I);

    } while (err > tol_);

    return I;
}

void Integral::showResults()
{
    cout << "NEWTON COTES ABERTA: " << endl
         << "GRAU 1 = " << integrar(1) << endl
         << "GRAU 2 = " << integrar(2) << endl
         << "GRAU 3 = " << integrar(3) << endl
         << "GRAU 4 = " << integrar(4) << endl
         << endl
         << "NEWTON COTES FECHADA: " << endl
         << "GRAU 1 = " << integrar(5) << endl
         << "GRAU 2 = " << integrar(6) << endl
         << "GRAU 3 = " << integrar(7) << endl
         << "GRAU 4 = " << integrar(8) << endl
         << endl
         << "GAUSS LEGENDRE: " << endl
         << endl
         << "2 PONTOS DE INTERPOLAÇÃO = " << integrar(9) << endl
         << endl
         << "3 PONTOS DE INTERPOLAÇÃO = " << integrar(10) << endl
         << endl
         << "4 PONTOS DE INTERPOLAÇÃO = " << integrar(11) << endl
         << endl;
}