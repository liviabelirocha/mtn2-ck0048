#include <iostream>
#include <iomanip>
#include "GaussLegendre.hpp"
using namespace std;

int main()
{
    cout << "Tarefa 5: Integrais Gauss Legendre" << endl
         << "FUNÇÃO : f(x) = (sen(2x) + 4x^2+ 3x)^2" << endl
         << endl;

    GaussLegendre I = GaussLegendre(0, 1, 1000, pow(10, -6));
    cout << setprecision(20)
         << "GAUSS LEGENDRE - PARTIÇÃO: " << endl
         << endl
         << "2 PONTOS DE INTERPOLAÇÃO: " << I.pontosInterpolacao2(1) << endl
         << "3 PONTOS DE INTERPOLAÇÃO: " << I.pontosInterpolacao3(1) << endl
         << endl
         << "GAUSS LEGENDRE - TOLERÂNCIA: " << endl
         << endl
         << "2 PONTOS DE INTERPOLAÇÃO: " << I.pontosInterpolacao2(2) << endl
         << "3 PONTOS DE INTERPOLAÇÃO: " << I.pontosInterpolacao3(2) << endl;

    return 0;
}