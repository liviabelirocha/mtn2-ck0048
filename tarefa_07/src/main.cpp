#include <iostream>
#include <iomanip>

#include "Integral.hpp"

using namespace std;

int main()
{
     cout << "Tarefa 7: Estratégias de partiçao com exponencial simples e dupla" << endl
          << endl;

     Integral simples = Integral(-1, 1, pow(10, -6), 9, 1);
     Integral dupla = Integral(-1, 1, pow(10, -6), 3, 2);

     cout << setprecision(20)
          << "EXPONENCIAL SIMPLES" << endl
          << endl;
     simples.showResults();
     cout << "EXPONENCIAL DUPLA" << endl;

     dupla.showResults();
}