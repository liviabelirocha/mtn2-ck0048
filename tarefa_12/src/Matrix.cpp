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
        {
            sum += matrix_[i][j] * v.getElement(j);
        }
        res.setElement(i, sum);
        sum = 0;
    }

    return res;
}

void Matrix::print()
{
    for (int i = 0; i < size_; i++)
    {
        for (int j = 0; j < size_; j++)
        {
            cout << matrix_[i][j] << " ";
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
                matrix_[i][j] = 1;
            else
                matrix_[i][j] = 0;
        }
    }
}

int Matrix::getElement(int i, int j)
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

Matrix Matrix::inverse()
{
    Matrix identity = Matrix(size_);
    Matrix y = Matrix(size_);
    Matrix inverse = Matrix(size_);
    identity.identity();

    for (int c = 0; c < size_; c++)
    {
        for (int i = 0; i < size_; ++i)
        {
            y.setElement(i, c, identity.getElement(i, c));
            for (int k = 0; k < i; k++)
                y.setElement(i, c, y.getElement(i, c) - L_[i][k] * y.getElement(k, c));
        }
    }

    for (int c = 0; c < size_; c++)
    {
        for (int i = size_ - 1; i >= 0; --i)
        {
            inverse.setElement(i, c, y.getElement(i, c));
            for (int k = i + 1; k < size_; k++)
                inverse.setElement(i, c, inverse.getElement(i, c) - U_[i][k] * inverse.getElement(k, c));
            inverse.setElement(i, c, inverse.getElement(i, c) / U_[i][i]);
        }
    }

    print(inverse);
    return inverse;
}