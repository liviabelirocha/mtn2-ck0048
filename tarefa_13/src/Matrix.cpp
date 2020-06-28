#include "Matrix.hpp"

Matrix::Matrix()
{
    size_ = 3;

    for (int i = 0; i < 3; i++)
    {
        vector<double> row(3);
        for (int j = 0; j < 3; j++)
            row.push_back(0);
        matrix_.push_back(row);
        L_.push_back(row);
        U_.push_back(row);
    }
}

Matrix::Matrix(int size)
{
    size_ = size;

    for (int i = 0; i < size; i++)
    {
        vector<double> row(3);
        for (int j = 0; j < size; j++)
            row.push_back(0);
        matrix_.push_back(row);
        L_.push_back(row);
        U_.push_back(row);
    }
}

void Matrix::truncate()
{
    for (int i = 0; i < size_; i++)
        for (int j = 0; j < size_; j++)
            if (abs(matrix_[i][j]) < 0.00000000001)
                matrix_[i][j] = 0;
}

void Matrix::setElement(int i, int j, double element)
{
    if (i >= size_ || j >= size_ || i < 0 || j < 0)
    {
        cout << "ERROR!!! INVALID MATRIX POSITION!" << endl;
        return;
    }
    matrix_[i][j] = element;
}

int Matrix::getSize()
{
    return size_;
}

VectorN Matrix::operator*(VectorN v)
{
    if (size_ != v.getSize())
    {
        cout << "ERROR!!! MATRIX AND VECTOR MUST HAVE SAME SIZES!" << endl;
        return v;
    }

    double sum = 0;
    VectorN res = VectorN(size_);

    for (int i = 0; i < size_; i++)
    {
        for (int j = 0; j < size_; j++)
            sum += matrix_[i][j] * v.getElement(j);
        res.setElement(i, sum);
        sum = 0;
    }

    return res;
}

Matrix Matrix::operator-(Matrix m)
{
    Matrix res = Matrix(size_);
    for (int i = 0; i < size_; i++)
    {
        for (int j = 0; j < size_; j++)
        {
            res.setElement(i, j, matrix_[i][j] - m.getElement(i, j));
        }
    }
    return res;
}

Matrix Matrix::operator*(double n)
{
    Matrix m = Matrix(size_);
    for (int i = 0; i < size_; i++)
    {
        for (int j = 0; j < size_; j++)
            m.setElement(i, j, matrix_[i][j] * n);
    }
    return m;
}

Matrix Matrix::operator*(Matrix m)
{
    Matrix res = Matrix(size_);
    for (int i = 0; i < size_; i++)
    {
        for (int j = 0; j < size_; j++)
        {
            double sum = 0;
            for (int k = 0; k < size_; k++)
                sum += matrix_[i][k] * m.getElement(k, j);
            res.setElement(i, j, sum);
        }
    }
    return res;
}

void Matrix::print()
{
    for (int i = 0; i < size_; i++)
    {
        for (int j = 0; j < size_; j++)
        {
            cout << matrix_[i][j] << " , ";
        }
        cout << "\n";
    }
}

void Matrix::print(Matrix m)
{
    for (int i = 0; i < size_; i++)
    {
        for (int j = 0; j < size_; j++)
        {
            cout << m.getElement(i, j) << " ";
        }
        cout << "\n";
    }
}

void Matrix::identity()
{
    for (int i = 0; i < size_; i++)
    {
        for (int j = 0; j < size_; j++)
        {
            if (i == j)
                matrix_[i][j] = 1.0;
            else
                matrix_[i][j] = 0.0;
        }
    }
}

double Matrix::getElement(int i, int j)
{
    return matrix_[i][j];
}

void Matrix::decompLU()
{
    Matrix identity = Matrix(size_);
    identity.identity();

    for (int i = 0; i < size_; i++)
    {
        for (int j = 0; j < size_; j++)
        {
            L_[i][j] = identity.getElement(i, j);

            if (i <= j)
            {
                U_[i][j] = matrix_[i][j];
                for (int k = 0; k < i; k++)
                    U_[i][j] -= L_[i][k] * U_[k][j];
            }

            else
            {
                L_[i][j] = matrix_[i][j];
                for (int k = 0; k < j; k++)
                    L_[i][j] -= L_[i][k] * U_[k][j];
                L_[i][j] /= U_[j][j];
                U_[i][j] = 0.0;
            }
        }
    }
}

void Matrix::transposeVectorMultiplication(VectorN v1, VectorN v2)
{
    for (int i = 0; i < v1.getSize(); i++)
    {
        for (int j = 0; j < v1.getSize(); j++)
            matrix_[i][j] = v1.getElement(j) * v2.getElement(i);
    }
}

Matrix Matrix::transpose()
{
    Matrix res = Matrix(size_);
    for (int i = 0; i < size_; ++i)
        for (int j = 0; j < size_; ++j)
            res.setElement(j, i, matrix_[i][j]);
    return res;
}