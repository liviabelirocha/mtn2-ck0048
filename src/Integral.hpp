#ifndef INTEGRAL_HPP
#define INTEGRAL_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Integral {
    private:
        double a_, b_, N_, Xin_, Xfin_, epsilon_;
        double f(double arg);

    public:
        Integral(double a, double b, int N);
        double integralN();
        double integralNewtonCotesFechada();
        double integralNewtonCotesFechadaGrau4();
        double integralNewtonCotesAberta();
        double integralNewtonCotesAbertaGrau4();

        Integral(double Xin, double Xfin, double epsilon);
        double integralEpsilon();
};

#endif