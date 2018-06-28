#pragma once
#include <iostream>

/**
 * @brief The StdBind class
 *
 * The execution of this class can be undestood
 * on Main.cpp/main function
 *
 * Before to unterstand what bind functions are,
 * the functions can be treated as objects
 *
 * As objects, functions can be defined as pointers
 *
 * As a pointer, that is a variable that contains
 * the address of another variable, the pointers
 * to functions are similar, but instead of pointing
 * to a variable they point to a function, the last
 * are known as "functors"
 *
 * A function declared as typedef can be used to
 * contain a function declaration, but does not
 * have a function definition. A function declared
 * as typedef is used as a function template. So
 * the template function object at the end is a
 * callable object.
 *
 * A callable object is something that can be called
 * like a function, with the syntax object() or
 * object(args); that is, a function pointer, or an
 * object of a class type that overloads operator().
 * The overload of operator() in a class makes it
 * callable.
 *
 * The function std :: bind joins the declaration
 * of a function with a function already defined
 * elsewhere in our code. It serves to join the
 * definition of a function with its declaration at
 * runtime. std::bind is a kind of lambda
 *
 * There are also nested bind functions to define
 * the execution of a function inside the parameter
 * of another bind. (Main.cpp/main example 4)
 *
 * To avoid indicating in the function pointer
 * the type of function that is going to receive,
 * the deduction of the return type and the variables
 * of the function is simply delegated to the compiler
 * with the "auto" reserved word (Main.cpp/main
 * examples 3 and 4).
 *
 * Placeholders are parameters of a declared function
 * that act as position markers, these markers will be
 * defined later replacing them with their final values
 * ​​in the function invocation. They are implemented
 * with "_1", "_2", ... , "_N" in std::bind function
 *
 */

class StdBind
{
public:
    void PrintString (const std::string &parameter) const;
    std::string ConcatString(const std::string &parameter1, const std::string &parameter2);
};
