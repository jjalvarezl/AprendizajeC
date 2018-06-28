#include "Vector.h"

using namespace std;

Vector::Vector(const int id)
{
    cout << "Vector::Vector, id: " << id <<endl;
    m_Id = id;
}

Vector::~Vector()
{
    cout << "Vector::~Vector, id: " << m_Id <<endl;
}

void Vector::print()
{
    cout << "Vector id: " << m_Id <<endl;
    cout << "X: " << m_X <<endl;
    cout << "Y: " << m_Y <<endl;
}
