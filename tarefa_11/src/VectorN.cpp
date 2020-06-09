#include "VectorN.hpp"

VectorN::VectorN()
{
    size_ = 3;

    for (int i = 0; i < 3; i++)
        vector_.push_back(1);
}

VectorN::VectorN(int size)
{
    size_ = size;

    for (int i = 0; i < size; i++)
        vector_.push_back(1);
}

void VectorN::setElement(int i, double element)
{
    if (i < 0 || i >= size_)
    {
        cout << "ERROR!!! INVALID VECTOR POSITION!" << endl;
        return;
    }

    vector_[i] = element;
}

double VectorN::norm()
{
    double res = 0;
    for (int i = 0; i < size_; i++)
        res += vector_[i] * vector_[i];
    return sqrt(res);
}

void VectorN::normalize()
{
    double norm = this->norm();
    for (int i = 0; i < size_; i++)
        vector_[i] = vector_[i] / norm;
}

int VectorN::getSize()
{
    return size_;
}

double VectorN::getElement(int i)
{
    return vector_[i];
}

void VectorN::copyVector(VectorN v)
{
    if (v.getSize() != size_)
    {
        cout << "ERROR!!! VECTORS WITH DIFFERENT SIZES!" << endl;
        return;
    }

    for (int i = 0; i < size_; i++)
    {
        vector_[i] = v.getElement(i);
    }
}

double VectorN::operator*(VectorN v)
{
    double res = 0;
    for (int i = 0; i < size_; i++)
        res += vector_[i] * v.getElement(i);
    return res;
}

void VectorN::print()
{
    cout << "( ";
    for (int i = 0; i < size_; i++)
    {
        cout << vector_[i] << " ";
    }
    cout << ")";
}