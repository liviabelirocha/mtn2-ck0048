#include <iostream>

#include "Derivative.hpp"

using namespace std;

int main() {
    Derivative d = Derivative(3, 0.1);
    cout << d.Forward() << endl
         << d.Backward() << endl
         << d.Central() << endl;
}