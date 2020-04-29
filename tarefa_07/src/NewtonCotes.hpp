#ifndef NEWTONCOTES_HPP
#define NEWTONCOTES_HPP

#include <iostream>
#include <cmath>

#include "Exponencial.hpp"

using namespace std;

class NewtonCotes
{
private:
    double err_;
    Exponencial e_;

public:
    NewtonCotes();
    NewtonCotes(double a, double b, double err, int type);

    double fechadaGrau1(double c1, double c2);
    double fechadaGrau2(double c1, double c2);
    double fechadaGrau3(double c1, double c2);
    double fechadaGrau4(double c1, double c2);

    double abertaGrau1(double c1, double c2);
    double abertaGrau2(double c1, double c2);
    double abertaGrau3(double c1, double c2);
    double abertaGrau4(double c1, double c2);
};

#endif