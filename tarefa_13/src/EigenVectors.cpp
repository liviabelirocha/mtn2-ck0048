#include "EigenVectors.hpp"

EigenVectors::EigenVectors(Matrix matrix, VectorN arbitraryVector, double tol)
{
    matrix_ = matrix;
    arbitratyVector_ = arbitraryVector;
    tol_ = tol;
}

VectorN EigenVectors::sucessiveIteractions(vector<vector<double>> m, VectorN v)
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

VectorN EigenVectors::retroativeIteractions(vector<vector<double>> m, VectorN v)
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

VectorN EigenVectors::solveLU(VectorN x, int n, Matrix matrix)
{
    VectorN y = VectorN(n);
    y = sucessiveIteractions(matrix.L_, x);
    return retroativeIteractions(matrix.U_, y);
}

Matrix EigenVectors::constructHouseHolder(Matrix A, int i)
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

void EigenVectors::houseHolder()
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

        Ai.truncate();
        H.truncate();
    }

    showResults(Ai, H);
}

tuple<double, VectorN, VectorN> EigenVectors::regularPower(Matrix m, Matrix H)
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

        newVector = m * oldVector;

        newAutovalue = oldVector * newVector;

        currentError = abs((newAutovalue - oldAutovalue) / newAutovalue);

    } while (currentError > tol_);

    VectorN Aautovector = VectorN(arbitratyVector_.getSize());
    Aautovector = H * oldVector;

    return {newAutovalue, oldVector, Aautovector};
}

tuple<double, VectorN, VectorN> EigenVectors::InversePower(Matrix matrix, Matrix H)
{
    matrix.decompLU();

    double newAutovalue = 0, oldAutovalue = 0, currentError = 0;

    VectorN newVector = VectorN(arbitratyVector_.getSize());
    newVector.copyVector(arbitratyVector_);

    VectorN oldVector = VectorN(arbitratyVector_.getSize());

    do
    {
        oldAutovalue = newAutovalue;
        oldVector.copyVector(newVector);
        oldVector.normalize();

        newVector = solveLU(oldVector, oldVector.getSize(), matrix);

        newAutovalue = oldVector * newVector;
        currentError = abs((newAutovalue - oldAutovalue) / newAutovalue);

    } while (currentError > tol_);

    newAutovalue = 1 / newAutovalue;

    VectorN Aautovector = VectorN(arbitratyVector_.getSize());
    Aautovector = H * oldVector;

    return {newAutovalue, oldVector, Aautovector};
}

tuple<double, VectorN, VectorN> EigenVectors::DisplacementPower(double mi, Matrix A, Matrix H)
{
    double autoValue = 0, newAutovalue = 0;
    Matrix Ab = Matrix(A.getSize());
    VectorN autoVector = VectorN(A.getSize());
    VectorN x = VectorN(A.getSize());

    for (int i = 0; i < A.getSize(); i++)
    {
        for (int j = 0; j < A.getSize(); j++)
        {
            if (i == j)
                Ab.setElement(i, j, A.getElement(i, j) - mi);
            else
                Ab.setElement(i, j, A.getElement(i, j));
        }
    }

    tie(autoValue, autoVector, x) = InversePower(Ab, Ab);
    newAutovalue = autoValue + mi;

    VectorN Aautovector = VectorN(arbitratyVector_.getSize());
    Aautovector = H * autoVector;

    return {newAutovalue, autoVector, Aautovector};
}

void EigenVectors::showResults(Matrix A_barra, Matrix H)
{
    VectorN regularAutovector = VectorN(A_barra.getSize());
    VectorN regularAutovectorA = VectorN(A_barra.getSize());
    VectorN inverseAutovector = VectorN(A_barra.getSize());
    VectorN inverseAutovectorA = VectorN(A_barra.getSize());
    VectorN displacementAutovector = VectorN(A_barra.getSize());
    VectorN displacementAutovectorA = VectorN(A_barra.getSize());
    double regularAutovalue, inverseAutovalue, displacementAutovalue, oldDisplacementAutovalue;

    tie(regularAutovalue, regularAutovector, regularAutovectorA) = regularPower(A_barra, H);

    cout << "1) IMPLEMENTAÇÃO DO MÉTODO DE HOUSEHOLDER\n\nMATRIZ A BARRA\n\n";
    A_barra.print();
    cout << "\nMATRIZ H\n\n";
    H.print();
    cout << "\n3, 4 e 5) AUTOVALORES E AUTOVETORES DE A E A_BARRA A PARTIR DOS MÉTODOS DA POTÊNCIA\n\n";

    tie(inverseAutovalue, inverseAutovector, inverseAutovectorA) = InversePower(A_barra, H);
    printResults(inverseAutovector, inverseAutovalue, inverseAutovectorA);

    for (int i = 0; i < regularAutovalue; i++)
    {
        tie(displacementAutovalue, displacementAutovector, displacementAutovectorA) = DisplacementPower(i, A_barra, H);
        if (i == 0)
            oldDisplacementAutovalue = displacementAutovalue;

        if ((int)displacementAutovalue == (int)inverseAutovalue)
            continue;
        else if ((int)displacementAutovalue == (int)regularAutovalue)
            break;
        else if (isnan(displacementAutovalue))
            continue;
        else if ((int)displacementAutovalue != (int)oldDisplacementAutovalue)
        {
            oldDisplacementAutovalue = displacementAutovalue;
            printResults(displacementAutovector, displacementAutovalue, displacementAutovectorA);
        }
    }

    printResults(regularAutovector, regularAutovalue, regularAutovectorA);
}

void EigenVectors::printResults(VectorN autovector, double autovalue, VectorN autovectorA)
{
    cout << "Autovetor de A_barra = ";
    autovector.print();
    cout << endl
         << "Autovalor de A_barra e A =  " << autovalue << endl
         << "H * autovetor de A_barra = autovetor de A ";
    autovectorA.print();
    cout << "\n\n";
}