#include "RValueReferences.h"

RValueReferences::RValueReferences()
{
    // All lvalues declarations
    int i, j, *p;

    // Correct usage: the variable i is an lvalue.
    i = 7;

    // Incorrect usage: The left operand must be an lvalue (C2106).
    // Uncomment the following lines to see compiler errors
    //7 = i; // C2106
    //j * 4 = 7; // C2106

    // Correct usage: the dereferenced pointer is an lvalue.
    *p = i;

    //Correct const lvalue initialization of ci.
    const int ci = 7;
    // Incorrect usage: the variable is a non-modifiable lvalue (C3892).
    // Uncomment the following line to see compiler errors
    //ci = 9; // C3892

    // Correct usage: the conditional operator returns an lvalue.
    ((i < 3) ? i : j) = 7;
}
