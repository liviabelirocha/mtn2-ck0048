#include <iostream>
#include <iomanip>
#include "NewtonCotes.hpp"
using namespace std;

int main()
{
     cout << "Tarefa 3: Integrais Newton Cotes" << endl
          << "FUNÇÃO : f(x) = (sen(2x) + 4x^2+ 3x)^2" << endl
          << endl;

     NewtonCotes I = NewtonCotes(0, 1, 4, pow(10, -6));
     cout << setprecision(20)
          << "NEWTON COTES FECHADA - PARTIÇÃO: " << endl
          << I.fechadaParticaoGrau1() << endl
          << I.fechadaParticaoGrau2() << endl
          << I.fechadaParticaoGrau3() << endl
          << I.fechadaParticaoGrau4() << endl
          << endl
          << "NEWTON COTES FECHADA - TOLERÂNCIA: " << endl
          << I.fechadaToleranciaGrau1() << endl
          << I.fechadaToleranciaGrau2() << endl
          << I.fechadaToleranciaGrau3() << endl
          << I.fechadaToleranciaGrau4() << endl
          << endl
          << "NEWTON COTES ABERTA - PARTIÇÃO: " << endl
          << I.abertaParticaoGrau1() << endl
          << I.abertaParticaoGrau2() << endl
          << I.abertaParticaoGrau3() << endl
          << I.abertaParticaoGrau4() << endl
          << endl
          << "NETWON COTES ABERTA - TOLERÂNCIA: " << endl
          << I.abertaToleranciaGrau1() << endl
          << I.abertaToleranciaGrau2() << endl
          << I.abertaToleranciaGrau3() << endl
          << I.abertaToleranciaGrau4() << endl;

     return 0;
}