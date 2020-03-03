#include <iostream>

#include "Derivative.hpp"
#include "Taylor.hpp"

using namespace std;

int main() {
    Derivative d = Derivative(5, 0.1);
    cout << "Forward: " << d.Forward() << endl
         << "Backward: " << d.Backward() << endl
         << "Central: " << d.Central() << endl;
    Taylor t = Taylor(4);
    cout << "Fatorial: " << t.factorial() << endl;
}