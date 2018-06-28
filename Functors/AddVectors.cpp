#include "AddVectors.h"


Vector AddVectors::operator ()(const Vector& a, const Vector& b) const
{
    Vector result (3);
    result.m_X = a.m_X + b.m_X;
    result.m_Y = a.m_Y + b.m_Y;
    return result;
}

