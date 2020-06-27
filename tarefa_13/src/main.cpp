#include <iostream>

#include "Matrix.hpp"
#include "VectorN.hpp"
#include "Householder.hpp"

using namespace std;

int main()
{
     Matrix A = Matrix(5);
     A.setElement(0, 0, 40);
     A.setElement(0, 1, 8);
     A.setElement(0, 2, 4);
     A.setElement(0, 3, 2);
     A.setElement(0, 4, 1);
     A.setElement(1, 0, 8);
     A.setElement(1, 1, 30);
     A.setElement(1, 2, 12);
     A.setElement(1, 3, 6);
     A.setElement(1, 4, 2);
     A.setElement(2, 0, 4);
     A.setElement(2, 1, 12);
     A.setElement(2, 2, 20);
     A.setElement(2, 3, 1);
     A.setElement(2, 4, 2);
     A.setElement(3, 0, 2);
     A.setElement(3, 1, 6);
     A.setElement(3, 2, 1);
     A.setElement(3, 3, 25);
     A.setElement(3, 4, 4);
     A.setElement(4, 0, 1);
     A.setElement(4, 1, 2);
     A.setElement(4, 2, 2);
     A.setElement(4, 3, 4);
     A.setElement(4, 4, 5);

     Householder PA = Householder(A);
     cout << "TAREFA 13 - MÉTODO DE HOUSEHOLDER" << endl
          << endl;
     PA.houseHolder();
}