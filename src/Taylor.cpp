#include "Taylor.hpp"

Taylor::Taylor(int order) { order_ = order; }

double Taylor::factorial() {
    int factorial = 1;
    for (int i=1; i<= order_; i++) factorial *= i;
    return factorial;
}