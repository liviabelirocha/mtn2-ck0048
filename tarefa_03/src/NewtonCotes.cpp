#include "NewtonCotes.hpp"

NewtonCotes::NewtonCotes(double a, double b, double N, double err) { a_ = a; b_ = b; N_ = N; err_ = err; }

double NewtonCotes::fechadaParticaoGrau1() {
    double delta = (b_-a_)/N_,
        I = 0, Xi, Xf;
    
    for (int i=0; i<N_; i++) {
        Xi = a_ + i*delta;
        Xf = Xi + delta;
        I = I + (delta/2)*(f(Xi) + f(Xf));
    }

    cout << endl << "GRAU 1"  << endl << "Integral = ";
    return I;
}

double NewtonCotes::fechadaParticaoGrau2() {
    double delta = (b_-a_)/N_, h = delta/2,
        I = 0, X0, X1, X2;
    
    for (int i=0; i<N_; i++) {
        X0 = a_ + i*delta;
        X1 = X0 + h;
        X2 = X1 + h;
        I = I + (delta/6)*(f(X0) + 4*f(X1) + f(X2));
    }

    cout << endl << "GRAU 2"  << endl << "Integral = ";
    return I;
}

double NewtonCotes::fechadaParticaoGrau3() {
    double delta = (b_-a_)/N_, h = delta/3,
        I = 0, X0, X1, X2, X3;
    
    for (int i=0; i<N_; i++) {
        X0 = a_ + i*delta;
        X1 = X0 + h;
        X2 = X1 + h;
        X3 = X2 + h;
        I = I + (delta/8)*(f(X0) + 3*f(X1) + 3*f(X2) + f(X3));
    }

    cout << endl << "GRAU 3"  << endl << "Integral = ";
    return I;
}

double NewtonCotes::fechadaParticaoGrau4() {
    double delta = (b_-a_)/N_, h = delta/4,
        I = 0, X0, X1, X2, X3, X4;
    
    for (int i=0; i<N_; i++) {
        X0 = a_ + i*delta;
        X1 = X0 + h;
        X2 = X1 + h;
        X3 = X2 + h;
        X4 = X3 + h;
        I = I + (delta/90)*(7*f(X0) + 32*f(X1) + 12*f(X2) + 32*f(X3) + 7*f(X4));
    }

    cout << endl << "GRAU 4"  << endl << "Integral = ";
    return I;
}

double NewtonCotes::fechadaToleranciaGrau1() {
    double  Iv, In = 0,
            delta,
            Xi, Xf, err = 1;
    int count, N = 1;
    
    do {
        Iv = In;
        In = 0;
        count = 0;

        delta = (b_-a_)/N;

        while(count < N) {
            Xi = a_ + count*delta;
            Xf = Xi + delta;
            In = In + (delta/2)*(f(Xi) + f(Xf));

            count++;
        }
        
        N *= 2;
        err = (double)fabs((In-Iv)/In);

    } while (err > err_);

    cout << endl << "GRAU 1" << endl <<"Número de Iterações = " << count << endl << "Integral = ";
    return In;
}

double NewtonCotes::fechadaToleranciaGrau2() {
    double  Iv, In = 0,
            delta, h,
            X0, X1, X2, err = 1;
    int count, N = 1;
    
    do {
        Iv = In;
        In = 0;
        count = 0;

        delta = (b_-a_)/N;
        h = delta/2;

        while(count < N) {
            X0 = a_ + count*delta;
            X1 = X0 + h;
            X2 = X1 + h;
            In = In + (delta/6)*(f(X0) + 4*f(X1) + f(X2));

            count++;
        }
        
        N *= 2;
        err = (double)fabs((In-Iv)/In);

    } while (err > err_);

    cout << endl << "GRAU 2" << endl <<"Número de Iterações = " << count << endl << "Integral = ";
    return In;
}

double NewtonCotes::fechadaToleranciaGrau3() {
    double  Iv, In = 0,
            delta, h,
            X0, X1, X2, X3, err = 1;
    int count, N = 1;
    
    do {
        Iv = In;
        In = 0;
        count = 0;

        delta = (b_-a_)/N;
        h = delta/3;

        while(count < N) {
            X0 = a_ + count*delta;
            X1 = X0 + h;
            X2 = X1 + h;
            X3 = X2 + h;
            In = In + (delta/8)*(f(X0) + 3*f(X1) + 3*f(X2) + f(X3));

            count++;
        }
        
        N *= 2;
        err = (double)fabs((In-Iv)/In);

    } while (err > err_);

    cout << endl << "GRAU 3" << endl <<"Número de Iterações = " << count << endl << "Integral = ";
    return In;
}

double NewtonCotes::fechadaToleranciaGrau4() {
    double  Iv, In = 0,
            delta, h,
            Xi, Xf, X1, X2, X3, err = 1;
    int count, N = 1;
    
    do {
        Iv = In;
        In = 0;
        count = 0;

        delta = (b_-a_)/N;
        h = delta/4;

        while(count < N) {
            Xi = a_ + count*delta;
            X1 = Xi + h;
            X2 = X1 + h;
            X3 = X2 + h;
            Xf = Xi + delta;
            In = In + (delta/90)*(7*f(Xi) + 32*f(X1) + 12*f(X2) + 32*f(X3) + 7*f(Xf));

            count++;
        }
        
        N *= 2;
        err = (double)fabs((In-Iv)/In);

    } while (err > err_);

    cout << endl << "GRAU 4" << endl <<"Número de Iterações = " << count << endl << "Integral = ";
    return In;
}

double NewtonCotes::abertaParticaoGrau1() {
    double delta = (b_-a_)/N_,
        h = delta/3, I = 0,
        Xi, x1, x2;
    
    for (int i=0; i<N_; i++) {
        Xi = a_ + i*delta;
        x1 = Xi + h;
        x2 = x1 + h;
        I = I + ((delta)/2)*(f(x1) + f(x2));
    }

    cout << endl << "GRAU 1"  << endl << "Integral = ";
    return I;
}

double NewtonCotes::abertaParticaoGrau2() {
    double delta = (b_-a_)/N_,
        h = delta/4, I = 0,
        Xi, x1, x2, x3;
    
    for (int i=0; i<N_; i++) {
        Xi = a_ + i*delta;
        x1 = Xi + h;
        x2 = x1 + h;
        x3 = x2 + h;
        I = I + (delta/3)*(2*f(x1) - f(x2) + 2*f(x3));
    }   

    cout << endl << "GRAU 2"  << endl << "Integral = ";
    return I;
}

double NewtonCotes::abertaParticaoGrau3() {
    double delta = (b_-a_)/N_,
        h = delta/5, I = 0,
        Xi, x1, x2, x3, x4;
    
    for (int i=0; i<N_; i++) {
        Xi = a_ + i*delta;
        x1 = Xi + h;
        x2 = x1 + h;
        x3 = x2 + h;
        x4 = x3 + h;
        I = I + (delta/24)*(11*f(x1) + f(x2) + f(x3) + 11*f(x4));
    }   

    cout << endl << "GRAU 3"  << endl << "Integral = ";
    return I;
}

double NewtonCotes::abertaParticaoGrau4() {
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

    cout << endl << "GRAU 4"  << endl << "Integral = ";
    return I;
}

double NewtonCotes::abertaToleranciaGrau1() {
    double delta, h, Iv, In = 0, err = 1,
            xi, x1, x2;
    int count, N = 1;
    do {
        Iv = In;
        In = 0;
        count = 0;

        delta = (b_-a_)/N;
        h = delta/3;

        while(count < N) {
            xi = a_ + count*delta;
            x1 = xi + h;
            x2 = x1 + h;
            In = In + ((delta)/2)*(f(x1) + f(x2));

            count++;
        }

        N *= 2;
        err = (double)fabs((In-Iv)/In);

    } while (err > err_);

    cout << endl << "GRAU 1" << endl << "Número de Iterações = " << count << endl << "Integral = ";
    return In;
}

double NewtonCotes::abertaToleranciaGrau2() {
    double delta, h, Iv, In = 0, err = 1,
            xi, x1, x2, x3;
    int count, N = 1;
    do {
        Iv = In;
        In = 0;
        count = 0;

        delta = (b_-a_)/N;
        h = delta/4;

        while(count < N) {
            xi = a_ + count*delta;
            x1 = xi + h;
            x2 = x1 + h;
            x3 = x2 + h;
            In = In + (delta/3)*(2*f(x1) - f(x2) + 2*f(x3));

            count++;
        }

        N *= 2;
        err = (double)fabs((In-Iv)/In);

    } while (err > err_);

    cout << endl << "GRAU 2" << endl << "Número de Iterações = " << count << endl << "Integral = ";
    return In;
}

double NewtonCotes::abertaToleranciaGrau3() {
    double delta, h, Iv, In = 0, err = 1,
            xi, x1, x2, x3, x4;
    int count, N = 1;
    do {
        Iv = In;
        In = 0;
        count = 0;

        delta = (b_-a_)/N;
        h = delta/5;

        while(count < N) {
            xi = a_ + count*delta;
            x1 = xi + h;
            x2 = x1 + h;
            x3 = x2 + h;
            x4 = x3 + h;
            In = In + (delta/24)*(11*f(x1) + f(x2) + f(x3) + 11*f(x4));

            count++;
        }

        N *= 2;
        err = (double)fabs((In-Iv)/In);

    } while (err > err_);

    cout << endl << "GRAU 3" << endl << "Número de Iterações = " << count << endl << "Integral = ";
    return In;
}

double NewtonCotes::abertaToleranciaGrau4() {
    double delta, h, Iv, In = 0, err = 1,
            xi, x1, x2, x3, xf;
    int count, N = 1;
    do {
        Iv = In;
        In = 0;
        count = 0;

        delta = (b_-a_)/N;
        h = delta/6;

        while(count < N) {
            xi = a_ + count*delta;
            x1 = xi + h;
            x2 = x1 + h;
            x3 = x2 + h;
            xf = xi + delta;
            In = In + ((delta)/20)*(11*f(xi) - 14*f(x1) + 26*f(x2) - 14*f(x3) + 11*f(xf));

            count++;
        }

        N *= 2;
        err = (double)fabs((In-Iv)/In);

    } while (err > err_);

    cout << endl << "GRAU 4" << endl << "Número de Iterações = " << count << endl << "Integral = ";
    return In;
}
