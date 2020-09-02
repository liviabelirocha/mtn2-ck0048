#include "Jacobi.hpp"

Jacobi::Jacobi(Matrix matrix, double err)
{
    matrix_ = matrix;
    err_ = err;
}

Matrix Jacobi::matrixOldMatrix(Matrix A, int i, int j)
{
    Matrix Jij = Matrix(A.getSize());
    Jij.identity();

    double theta = 0;

    if (abs(A.getElement(i, j)) <= err_)
        return Jij;

    if (abs(A.getElement(i, i) - A.getElement(j, j)) <= err_)
        theta = M_PI / 4.0;
    else
        theta = atan((-2 * A.getElement(i, j)) / (A.getElement(i, i) - A.getElement(j, j))) / 2.0;

    Jij.setElement(i, i, cos(theta));
    Jij.setElement(j, j, cos(theta));
    Jij.setElement(i, j, sin(theta));
    Jij.setElement(j, i, -sin(theta));

    Jij.truncate();

    return Jij;
}

tuple<Matrix, Matrix> Jacobi::jacobiSweep(Matrix A)
{
    Matrix J = Matrix(A.getSize());
    Matrix Jij = Matrix(A.getSize());
    Matrix An = Matrix(A.getSize());
    Matrix Av = Matrix(A.getSize());

    J.identity();
    Av = A;

    for (int j = 0; j < A.getSize() - 1; j++)
    {
        for (int i = j + 1; i < A.getSize(); i++)
        {
            Jij = matrixOldMatrix(Av, i, j);
            An = Jij.transpose() * (Av * Jij);
            Av = An;
            J = J * Jij;
        }
    }

    cout << endl
         << "MATRIZ SAINDO DA VARREDURA DE JACOBI" << endl
         << endl;
    An.print();

    return {An, J};
}

tuple<Matrix, Matrix, VectorN> Jacobi::jacobiMethod()
{
    Matrix P = Matrix(matrix_.getSize());
    Matrix J = Matrix(matrix_.getSize());
    Matrix An = Matrix(matrix_.getSize());
    Matrix Av = Matrix(matrix_.getSize());

    VectorN Lamb = VectorN(matrix_.getSize());

    double val = 100;

    P.identity();
    Av = matrix_;

    while (val > err_)
    {
        tie(An, J) = jacobiSweep(Av);
        Av = An;
        P = P * J;
        val = An.sumSquareUnderDiag();
    }

    for (int i = 0; i < matrix_.getSize(); i++)
        Lamb.setElement(i, An.getElement(i, i));

    P.truncate();

    return {P, An, Lamb};
}

void Jacobi::showResults()
{
    Matrix P = Matrix(matrix_.getSize());
    Matrix A = Matrix(matrix_.getSize());
    VectorN Lamb = VectorN(matrix_.getSize());

    tie(P, A, Lamb) = jacobiMethod();

    cout << endl
         << "MATRIZ P ACUMULADA" << endl
         << endl;
    P.print();
    cout << endl
         << "MATRIZ A" << endl
         << endl;
    A.print();
    cout << endl
         << "LAMB" << endl
         << endl;
    Lamb.print();
    cout << endl
         << endl
         << "PARES DE AUTOVALORES E AUTOVETORES" << endl
         << endl;
    for (int i = 0; i < P.getSize(); i++)
    {
        cout << "( " << Lamb.getElement(i) << ", [ ";
        for (int j = 0; j < P.getSize(); j++)
        {
            cout << P.getElement(j, i);
            if (j != P.getSize() - 1)
                cout << ", ";
        }
        cout << " ])" << endl;
    }
}