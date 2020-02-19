#ifndef DERIVATIVE_HPP
#define DERIVATIVE_HPP

#include <iostream>
#include <cmath>

class Derivative {
    private:
        double x_, deltha_;

    public:
        Derivative(double x, double deltha);
        double f(double arg);
        double Forward();
        double Backward();
        double Central();
};

#endif