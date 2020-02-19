#include "Derivative.hpp"

Derivative::Derivative(double x, double deltha) { x_ = x; deltha_ = deltha; }

double Derivative::f(double arg) {
    //f(x) = 3x^6
    return 3*pow(arg, 6);
}

double Derivative::Forward() { return (f(x_+deltha_) - f(x_)) / f(deltha_); }

double Derivative::Backward() { return (f(x_) - f(x_ - deltha_)) / f(deltha_); }

double Derivative::Central() { return (f(x_+deltha_) - f(x_ - deltha_)) / f(deltha_); }