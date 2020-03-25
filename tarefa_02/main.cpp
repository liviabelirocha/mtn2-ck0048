#include <iostream>
#include <cmath>

using namespace std;

class Integral {
    private:
        double a_, b_, N_;
        double f(double arg) {
            //f(x) = (sen(2x) + 4x^2+ 3x)^2
            double var = sin(2*arg) + 4*pow(arg, 2) + 3*arg;
            return pow(var, 2);
        }

    public:
        Integral(double a, double b, int N) { a_ = a; b_ = b; N_ = N; }

        double integralNewtonCotesFechadaGrau4() {
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

        double integralNewtonCotesAbertaGrau4() {
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

};

int main() {
    cout << "Trabalho 2: Integral Newton Cotes GRAU 4" << endl
         << "FUNÇÃO : f(x) = (sen(2x) + 4x^2+ 3x)^2" << endl << endl;

    Integral I = Integral(0, 1, 10000);
    cout << "Newton Cotes Fechada: " << I.integralNewtonCotesFechadaGrau4() << endl
         << "Newton Cotes Aberta: " << I.integralNewtonCotesAbertaGrau4() << endl;
    
}