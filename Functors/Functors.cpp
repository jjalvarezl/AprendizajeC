#include "Functors.h"

void Functors::FunctorsExample()
{
    Vector v1 (1);
    v1.m_X = 2;
    v1.m_Y = 3;
    Vector v2 (2);
    v2.m_X = 2;
    v2.m_Y = 3;
    AddVectors addVectors;
    addVectors(v1, v2).print();
}
