#pragma once
#include "Vector.h"

class AddVectors
{
public:
    Vector operator() (const Vector& a, const Vector& b) const;
};
