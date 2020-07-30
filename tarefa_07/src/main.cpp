#include <iostream>
#include <iomanip>

#include "Exponencial.hpp"

using namespace std;

int main()
{
     cout << "Tarefa 7: Estratégias de partiçao com exponencial simples e dupla" << endl
          << endl;

     Exponencial simples = Exponencial(-2, 0, pow(10, -6), 1);
     Exponencial dupla = Exponencial(-2, 0, pow(10, -6), 2);

     cout << setprecision(20) << "EXPONENCIAL SIMPLES" << endl;
     simples.integrar();
     cout << endl
          << "EXPONENCIAL DUPLA" << endl;
     dupla.integrar();
}