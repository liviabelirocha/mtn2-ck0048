#ifndef INTEGRAL_HPP
#define INTEGRAL_HPP

#include <iostream>
#include <cmath>

class Integral {
    private:
        double a_, b_, N_, Xin_, Xfin_, epsilon_;
        double f(double arg);

    public:
        Integral(double a, double b, int N);
        double integralN();
        double integralNewtonCotesFechada();
        double integralNewtonCotesAberta();

        Integral(double Xin, double Xfin, double epsilon);
        double integralEpsilon();
};

#endif