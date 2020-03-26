#include <iostream>
#include <cmath>

using namespace std;

class Integral {
    private:
        double a_, b_, err_, N_;
        double f(double arg) {
            //f(x) = (sen(2x) + 4x^2+ 3x)^2
            double var = sin(2*arg) + 4*pow(arg, 2) + 3*arg;
            return pow(var, 2);
        }

    public:
        Integral(double a, double b, double err) { a_ = a; b_ = b; err_ = err; }

        double integralNewtonCotesFechadaGrau4() {
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

            cout << endl << "Número de Iterações = " << count << endl << "Integral = ";
            return In;
        }

        double integralNewtonCotesAbertaGrau4() {
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

            cout << endl << "Número de Iterações = " << count << endl << "Integral = ";
            return In;
        }

};

int main() {
    cout << "Trabalho 2: Integral Newton Cotes GRAU 4" << endl
         << "FUNÇÃO : f(x) = (sen(2x) + 4x^2+ 3x)^2" << endl << endl;

    Integral I = Integral(0, 1, pow(10, -6));
    cout << "NEWTON COTES FECHADA: " << endl << I.integralNewtonCotesFechadaGrau4() << endl << endl
         << "NEWTON COTES ABERTA: " << endl << I.integralNewtonCotesAbertaGrau4() << endl;

    return 0;
}