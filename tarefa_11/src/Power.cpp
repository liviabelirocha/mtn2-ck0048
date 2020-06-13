#include "Power.hpp"

Power::Power(Matrix matrix, VectorN arbitratyVector, double tol)
{
    matrix_ = matrix;
    arbitratyVector_ = arbitratyVector;
    tol_ = tol;
}

void Power::RegularPower()
{
    double newAutovalue = 0, oldAutovalue = 0, currentError = 0;

    VectorN newVector = VectorN(arbitratyVector_.getSize());
    newVector.copyVector(arbitratyVector_);

    VectorN oldVector = VectorN(arbitratyVector_.getSize());

    do
    {
        oldAutovalue = newAutovalue;
        oldVector.copyVector(newVector);
        oldVector.normalize();

        newVector = matrix_ * oldVector;

        newAutovalue = oldVector * newVector;
        currentError = abs((newAutovalue - oldAutovalue) / newAutovalue);

    } while (currentError > tol_);

    std::cout << "O autovalor dominante do autovetor ";
    oldVector.print();
    std::cout << " é " << newAutovalue << endl;
}