#pragma once

/**
 * @brief The RValueReferences class
 *
 * RVALUES
 *
 * Every C++ expression is either an lvalue or an rvalue.
 * An lvalue refers to an object that persists beyond a
 * single expression. You can think of an lvalue as an
 * object that has a name. All variables, including
 * nonmodifiable (const) variables, are lvalues, and has
 * the hability to access to the content with & operator.
 * An rvalue is a temporary value that does not persist
 * beyond the expression that uses it. To better
 * understand the difference between lvalues and rvalues,
 * consider the following example:
 *
 * int x = 3 + 4;
 *
 * In this example, x is an lvalue because it persists
 * beyond the expression that defines it. The expression
 * 3 + 4 is an rvalue because it evaluates to a temporary
 * value that does not persist beyond the expression that
 * defines it. Another examples:
 *
 * // Correct usage: the variable i is an lvalue.
 * i = 7;
 *
 * // Incorrect usage: The left operand must be an lvalue (C2106).
 * 7 = i; // C2106
 * j * 4 = 7; // C2106
 *
 * // Correct usage: the dereferenced pointer is an lvalue.
 * *p = i;
 *
 * //Correct const lvalue initialization of ci.
 * const int ci = 7;
 * // Incorrect usage: the variable is a non-modifiable lvalue (C3892).
 * ci = 9; // C3892
 *
 * // Correct usage: the conditional operator returns an lvalue.
 * ((i < 3) ? i : j) = 7;
 *
 * The previous code is in this class constructor. The correct
 * and incorrect occurs when there are no overloaded operators.
 * Expresions such as j * 4 could me correct if there is the
 * operator * is overloaded.
 *
 * RVALUE REFERENCES:
 *
 * Al parameters on a function are lvalues because inside the
 * function you can take it's adress, even though its type is an
 * rvalue reference, i.e:
 *
 * MyFunction(MyType&& rhs)
 *
 * here, the parameter rhs is an lvalue but its type
 * is an rvalue reference to MyType.
 *
 */
class RValueReferences
{
public:
    RValueReferences();
};
