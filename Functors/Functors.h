#pragma once
#include "AddVectors.h"
#include "Vector.h"

/**
 * @brief The Functors class
 *
 * Functors are any kind of object that are
 * called as a funtion. It does not aims to an
 * object, it aims to a behaviour / function
 *
 *                               <<Functor>>
 *  Functors  ------------------> AddVectors
 *             FunctorsExample()       |
 *                                     |
 *                                     V
 *                                 Vector
 *
 */
class Functors
{
public:
    void FunctorsExample ();
};
