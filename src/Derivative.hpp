#ifndef DERIVATIVE_HPP
#define DERIVATIVE_HPP

#include <iostream>
#include <cmath>

class Derivative {
    private:
        double x_, delta_;
        double f(double arg);

    public:
        Derivative(double x, double deltha);
        double Forward();
        double Backward();
        double Central();
};

#endif