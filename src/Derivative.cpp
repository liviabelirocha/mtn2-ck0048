#include "Derivative.hpp"

Derivative::Derivative(double x, double deltha) { x_ = x; deltha_ = deltha; }

double Derivative::f(double arg) {
    //f(x) = x^2
    return pow(arg, 2);
}

double Derivative::Forward() { return (f(x_+deltha_) - f(x_)) / deltha_; }

double Derivative::Backward() { return (f(x_) - f(x_ - deltha_)) / deltha_; }

double Derivative::Central() { return (f(x_+deltha_) - f(x_-deltha_)) / (2*deltha_); }

double Derivative::Forward(double (*function)(double)) {
    return (function(x_+deltha_) - function(x_)) / deltha_;
}