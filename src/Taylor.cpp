#include "Taylor.hpp"

Taylor::Taylor(int order) { order_ = order; }

double Taylor::factorial() {
    int factorial = 1;
    for (int i=1; i<= order_; i++) factorial *= i;
    return factorial;
}

//https://www.codepoc.io/blog/cpp/3213/program-to-estimate-the-value-of-third-derivative-of-the-function-at-the-given-points-from-the-given-data-using-central-difference-formula-of-order-4