#include <iostream>

#include "Matrix.hpp"
#include "VectorN.hpp"
#include "Power.hpp"

using namespace std;

int main()
{
     VectorN arbitrary1 = VectorN();
     VectorN arbitrary2 = VectorN(5);

     Matrix A1 = Matrix();
     A1.setElement(0, 0, 5);
     A1.setElement(0, 1, 2);
     A1.setElement(0, 2, 1);
     A1.setElement(1, 0, 2);
     A1.setElement(1, 1, 3);
     A1.setElement(1, 2, 1);
     A1.setElement(2, 0, 1);
     A1.setElement(2, 1, 1);
     A1.setElement(2, 2, 2);

     Matrix A2 = Matrix();
     A2.setElement(0, 0, -14);
     A2.setElement(0, 1, 1);
     A2.setElement(0, 2, -2);
     A2.setElement(1, 0, 1);
     A2.setElement(1, 1, -1);
     A2.setElement(1, 2, 1);
     A2.setElement(2, 0, -2);
     A2.setElement(2, 1, 1);
     A2.setElement(2, 2, -11);

     Matrix A3 = Matrix(5);
     A3.setElement(0, 0, 40);
     A3.setElement(0, 1, 8);
     A3.setElement(0, 2, 4);
     A3.setElement(0, 3, 2);
     A3.setElement(0, 4, 1);
     A3.setElement(1, 0, 8);
     A3.setElement(1, 1, 30);
     A3.setElement(1, 2, 12);
     A3.setElement(1, 3, 6);
     A3.setElement(1, 4, 2);
     A3.setElement(2, 0, 4);
     A3.setElement(2, 1, 12);
     A3.setElement(2, 2, 20);
     A3.setElement(2, 3, 1);
     A3.setElement(2, 4, 2);
     A3.setElement(3, 0, 2);
     A3.setElement(3, 1, 6);
     A3.setElement(3, 2, 1);
     A3.setElement(3, 3, 25);
     A3.setElement(3, 4, 4);
     A3.setElement(4, 0, 1);
     A3.setElement(4, 1, 2);
     A3.setElement(4, 2, 2);
     A3.setElement(4, 3, 4);
     A3.setElement(4, 4, 5);

     Power PA1 = Power(A1, arbitrary1, 0.0000001, 1);
     Power PA2 = Power(A2, arbitrary1, 0.0000001, 1);
     Power PA3 = Power(A3, arbitrary2, 0.0000001, 1);
     Power PA4 = Power(A1, arbitrary1, 0.0000001, 1);
     Power PA5 = Power(A2, arbitrary1, 0.0000001, 1);
     Power PA6 = Power(A3, arbitrary2, 0.0000001, 1);

     cout << "POTÊNCIA INVERSA" << endl
          << endl
          << "EXEMPLO 1" << endl;
     PA1.InversePower(0);
     cout << endl
          << "EXEMPLO 2" << endl;
     PA2.InversePower(0);
     cout << endl
          << "EXEMPLO 3" << endl;
     PA3.InversePower(0);

     cout << endl
          << "POTÊNCIA COM DESLOCAMENTO" << endl
          << endl
          << "EXEMPLO 1" << endl;
     PA1.DisplacementPower();
     cout << endl
          << "EXEMPLO 2" << endl;
     PA2.DisplacementPower();
     cout << endl
          << "EXEMPLO 3" << endl;
     PA3.DisplacementPower();
}