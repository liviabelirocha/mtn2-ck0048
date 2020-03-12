#include "Integral.hpp"

Integral::Integral(double a, double b, int N) { a_ = a; b_ = b; N_ = N; }
Integral::Integral(double Xin, double Xfin, double epsilon) { Xin_ = Xin; Xfin_ = Xfin; epsilon_ = epsilon; }

double Integral::f(double arg) {
    //f(x) = x^2
    return pow(arg, 2);
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
    double Iv = 0, N = 1, In, err;
    do {
        N = N*2;
        Integral *i = new Integral(Xin_, Xfin_, N);
        In = (*i).integralN();
        err = abs((In-Iv)/In);
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

double Integral::integralNewtonCotesAberta() {
    double delta = (b_-a_)/N_,
           h = delta/3, I = 0,
           Xi, x1, x2; //Xf
    
    for (int i=0; i<N_; i++) {
        Xi = a_ + i*delta;
        //Xf = Xi + delta;
        x1 = Xi + h;
        x2 = x1 + h;
        I = (delta/2)*(f(x1) + f(x2));
    }

    return I;
}