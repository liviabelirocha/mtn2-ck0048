#include <iostream>

#include "Derivative.hpp"
#include "Taylor.hpp"
#include "Integral.hpp"

using namespace std;

int main() {
    Derivative d = Derivative(5, 0.1);
    cout << "Derivadas: " << endl
         << "Forward: " << d.Forward() << endl
         << "Backward: " << d.Backward() << endl
         << "Central: " << d.Central() << endl;
    
    Integral I = Integral(0, 1, 10000);
    cout << I.integralNewtonCotesAberta() << endl
         << I.integralNewtonCotesAbertaGrau4() << endl;
}