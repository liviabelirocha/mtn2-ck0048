#include "Householder.hpp"

Householder::Householder(Matrix matrix)
{
    matrix_ = matrix;
}

Matrix Householder::constructHouseHolder(Matrix A, int i)
{
    VectorN w = VectorN(A.getSize());
    VectorN wl = VectorN(A.getSize());
    VectorN N = VectorN(A.getSize());

    Matrix NNt = Matrix(A.getSize());
    Matrix H = Matrix(A.getSize());
    Matrix identity = Matrix(A.getSize());
    identity.identity();

    for (int x = i + 1; x < A.getSize(); x++)
        w.setElement(x, A.getElement(x, i));

    double Lw = w.norm();

    wl.setElement(i + 1, Lw);

    N = w - wl;

    N.normalize();

    NNt.transposeVectorMultiplication(N, N);

    H = identity - NNt * 2;

    return H;
}

void Householder::houseHolder()
{
    Matrix H = Matrix(matrix_.getSize());
    H.identity();

    Matrix Ai = Matrix(matrix_.getSize());
    Matrix Aim1 = Matrix(matrix_.getSize());
    Aim1 = matrix_;

    Matrix Hi = Matrix(matrix_.getSize());
    Matrix HiT = Matrix(matrix_.getSize());

    for (int i = 0; i < matrix_.getSize() - 2; i++)
    {
        Hi = constructHouseHolder(Aim1, i);

        HiT = Hi.transpose();

        Ai = (HiT * Aim1) * Hi;

        Aim1 = Ai;

        H = H * Hi;
    }

    cout << "MATRIZ A" << endl
         << endl;
    Ai.print();
    cout << endl
         << endl
         << "MATRIZ H" << endl
         << endl;
    H.print();
}