#ifndef NEWTONCOTES_HPP
#define NEWTONCOTES_HPP

#include <iostream>
#include <cmath>

using namespace std;

class NewtonCotes {
    private:
        double a_, b_, err_, N_;
        double f(double arg) {
            //f(x) = (sen(2x) + 4x^2+ 3x)^2
            double var = sin(2*arg) + 4*pow(arg, 2) + 3*arg;
            return pow(var, 2);
        }

    public:
        NewtonCotes(double a, double b, double N, double err);

        double fechadaParticaoGrau1();
        double fechadaParticaoGrau2();
        double fechadaParticaoGrau3();
        double fechadaParticaoGrau4();

        double fechadaToleranciaGrau1();
        double fechadaToleranciaGrau2();
        double fechadaToleranciaGrau3();
        double fechadaToleranciaGrau4();

        double abertaParticaoGrau1();
        double abertaParticaoGrau2();
        double abertaParticaoGrau3();
        double abertaParticaoGrau4();

        double abertaToleranciaGrau1();
        double abertaToleranciaGrau2();
        double abertaToleranciaGrau3();
        double abertaToleranciaGrau4();

};

#endif