#include "Integral.hpp"

Integral::Integral(double a, double b, int N) { a_ = a; b_ = b; N_ = N; }
Integral::Integral(double Xin, double Xfin, double epsilon) { Xin_ = Xin; Xfin_ = Xfin; epsilon_ = epsilon; }

double Integral::f(double arg) {
    //(x) = (sen(2x) + 4x^2+ 3x)^2
    double var = sin(2*arg) + 4*pow(arg, 2) + 3*arg;
    return pow(var, 2);
}

double Integral::integralN() {
    double delta = (b_ - a_)/N_, 
           I = 0, x;
    
    for (int i=0; i<N_; i++) {
        x = a_ + delta/2 + i*delta;
        I = I + f(x) + delta;
    }

    return I;
}

double Integral::integralEpsilon() {
    double Iv = 0, In, err;
    int N = 1;
    do {
        N = N*2;
        Integral *i = new Integral(Xin_, Xfin_, N);
        In = (*i).integralN();
        err = fabs((In-Iv)/In);
        Iv = In;
        delete i;
    } while( err > epsilon_);

    return In;
}

double Integral::integralNewtonCotesFechada() {
    double delta = (b_-a_)/N_,
           I = 0, Xi, Xf;
    
    for (int i=0; i<N_; i++) {
        Xi = a_ + i*delta;
        Xf = Xi + delta;
        I = I + (delta/2)*(f(Xi) + f(Xf));
    }

    return I;
}

double Integral::integralNewtonCotesFechadaGrau4() {
    double delta = (b_-a_)/N_,
           I = 0, X0, X1, X2, X3, X4;
    
    for (int i=0; i<N_; i++) {
        X0 = a_ + i*delta;
        X1 = X0 + delta;
        X2 = X1 + delta;
        X3 = X2 + delta;
        X4 = X3 + delta;
        I = I + (delta/90)*(7*f(X0) + 32*f(X1) + 12*f(X2) + 32*f(X3) + 7*f(X4));
    }

    return I;
}

double Integral::integralNewtonCotesAberta() {
    double delta = (b_-a_)/N_,
           h = delta/3, I = 0,
           Xi, x1, x2;
    
    for (int i=0; i<N_; i++) {
        Xi = a_ + i*delta;
        x1 = Xi + h;
        x2 = x1 + h;
        I = I + ((delta)/2)*(f(x1) + f(x2));
    }

    return I;
}

double Integral::integralNewtonCotesAbertaGrau4() {
    double delta = (b_-a_)/N_,
           h = delta/6, I = 0,
           Xi, x1, x2, x3, x4, x5;
    
    for (int i=0; i<N_; i++) {
        Xi = a_ + i*delta;
        x1 = Xi + h;
        x2 = x1 + h;
        x3 = x2 + h;
        x4 = x3 + h;
        x5 = x4 + h;
        I = I + ((delta)/20)*(11*f(x1) - 14*f(x2) + 26*f(x3) - 14*f(x4) + 11*f(x5));
    }

    return I;
}