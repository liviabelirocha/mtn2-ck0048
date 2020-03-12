#include "Derivative.hpp"

Derivative::Derivative(double x, double delta) { x_ = x; delta_ = delta; }

double Derivative::f(double arg) {
    //f(x) = x^2
    return pow(arg, 2);
}

double Derivative::Forward() { return (f(x_+delta_) - f(x_)) / delta_; }

double Derivative::Backward() { return (f(x_) - f(x_ - delta_)) / delta_; }

double Derivative::Central() { return (f(x_+delta_) - f(x_-delta_)) / (2*delta_); }