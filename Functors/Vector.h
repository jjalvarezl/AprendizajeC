#pragma once
#include <iostream>

struct Vector
{
    int m_Id;
    float m_X;
    float m_Y;
    Vector(const int id);
    ~Vector();
    void print();
};
