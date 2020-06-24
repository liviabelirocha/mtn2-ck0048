#include "Power.hpp"

Power::Power(Matrix matrix, VectorN arbitratyVector, double tol, double mi)
{
    matrix_ = matrix;
    arbitratyVector_ = arbitratyVector;
    tol_ = tol;
    mi_ = mi;
}

VectorN Power::sucessiveIteractions(vector<vector<double>> m, VectorN v)
{
    VectorN x = VectorN(v.getSize());
    x.setElement(0, v.getElement(0) / m[0][0]);
    for (int i = 1; i < v.getSize(); i++)
    {
        double sum = 0;
        for (int j = 0; j < i; j++)
            sum += m[i][j] * x.getElement(j);
        x.setElement(i, (v.getElement(i) - sum) / m[i][i]);
    }
    return x;
}

VectorN Power::retroativeIteractions(vector<vector<double>> m, VectorN v)
{
    VectorN x = VectorN(v.getSize());
    x.setElement(v.getSize() - 1, v.getElement(v.getSize() - 1) / m[v.getSize() - 1][v.getSize() - 1]);
    for (int i = v.getSize() - 2; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j <= v.getSize() - 1; j++)
            sum += m[i][j] * x.getElement(j);
        x.setElement(i, (v.getElement(i) - sum) / m[i][i]);
    }
    return x;
}

VectorN Power::solveLU(VectorN x, int n)
{
    VectorN y = VectorN(n);
    y = sucessiveIteractions(matrix_.L_, x);
    return retroativeIteractions(matrix_.U_, y);
}

void Power::InversePower()
{
    matrix_.decompLU();

    double newAutovalue = 0, oldAutovalue = 0, currentError = 0;

    VectorN newVector = VectorN(arbitratyVector_.getSize());
    newVector.copyVector(arbitratyVector_);

    VectorN oldVector = VectorN(arbitratyVector_.getSize());

    do
    {
        oldAutovalue = newAutovalue;
        oldVector.copyVector(newVector);
        oldVector.normalize();

        newVector = solveLU(oldVector, matrix_.getSize());

        newAutovalue = oldVector * newVector;
        currentError = abs((newAutovalue - oldAutovalue) / newAutovalue);

    } while (currentError > tol_);

    newAutovalue = 1 / newAutovalue;

    std::cout << "O menor autovalor do autovetor ";
    oldVector.print();
    std::cout << " é " << newAutovalue << endl;
}

void Power::DisplacementPower()
{
}