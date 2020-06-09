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