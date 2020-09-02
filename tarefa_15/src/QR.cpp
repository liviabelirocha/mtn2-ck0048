#include "QR.hpp"

QR::QR(Matrix matrix, double err)
{
    matrix_ = matrix;
    err_ = err;
}

Matrix QR::matrixOldMatrix(Matrix A, int i, int j)
{
    Matrix Jij = Matrix(A.getSize());
    Jij.identity();

    double theta = 0;

    if (abs(A.getElement(i, j)) <= err_)
        return Jij;

    if (abs(A.getElement(j, j)) <= err_)
        if (A.getElement(i, j) < 0)
            theta = M_PI / 2.0;
        else
            theta = -M_PI / 2.0;
    else
        theta = atan(-A.getElement(i, j) / A.getElement(j, j));

    Jij.setElement(i, i, cos(theta));
    Jij.setElement(j, j, cos(theta));
    Jij.setElement(i, j, sin(theta));
    Jij.setElement(j, i, -sin(theta));

    return Jij;
}

tuple<Matrix, Matrix> QR::decompQR(Matrix A)
{
    Matrix QT = Matrix(matrix_.getSize());
    Matrix Jij = Matrix(matrix_.getSize());
    Matrix Rn = Matrix(matrix_.getSize());
    Matrix Rv = Matrix(matrix_.getSize());

    QT.identity();

    Rv = A;

    for (int j = 0; j < matrix_.getSize() - 1; j++)
        for (int i = j + 1; i < matrix_.getSize(); i++)
        {
            Jij = matrixOldMatrix(Rv, i, j);
            Rn = Jij * Rv;
            Rv = Rn;
            QT = Jij * QT;
        }

    cout << endl
         << "MATRIZ EM CADA ITERAÇÃO QR" << endl
         << endl;
    QT.print();

    Matrix QTtranspose = QT.transpose();
    return {QTtranspose, Rn};
}

tuple<Matrix, Matrix, VectorN> QR::QRMethod()
{
    Matrix P = Matrix(matrix_.getSize());
    Matrix Q = Matrix(matrix_.getSize());
    Matrix R = Matrix(matrix_.getSize());
    Matrix An = Matrix(matrix_.getSize());
    Matrix Av = Matrix(matrix_.getSize());
    Matrix Ab = Matrix(matrix_.getSize());

    VectorN Lamb = VectorN(matrix_.getSize());

    double val = 100;

    P.identity();
    Av = matrix_;

    while (val > err_)
    {
        tie(Q, R) = decompQR(Av);
        An = R * Q;
        Av = An;
        P = P * Q;
        val = An.sumSquareUnderDiag();
    }

    for (int i = 0; i < matrix_.getSize(); i++)
        Lamb.setElement(i, An.getElement(i, i));

    return {P, An, Lamb};
}

void QR::showResults()
{
    Matrix P = Matrix(matrix_.getSize());
    Matrix A = Matrix(matrix_.getSize());
    VectorN Lamb = VectorN(matrix_.getSize());

    tie(P, A, Lamb) = QRMethod();

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