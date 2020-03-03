#ifndef TAYLOR_HPP
#define TAYLOR_HPP

#include <iostream>
#include <cmath>

class Taylor {
    private:
        int order_;

    public:
        Taylor(int order);
        double factorial();
};

#endif