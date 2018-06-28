#include "Functors.h"
#include "LambdaCall.h"
#include "StdBind.h"
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;
using namespace std::placeholders;

string InverseString(string& parameter)
{
    reverse(parameter.begin(), parameter.end());
    return parameter;
}

int main()
{

    //! EXAMPLE 0: ELEMENTAL FUNCTOR EXECUTION

    Functors f;
    f.FunctorsExample();

    StdBind instance;
    string string1 = "My string 1";
    string string2 = "My string 2";
    string string3 = "My string 3";
    string response = "";

    //! EXAMPLE 1: A FIRST APPROACH TO BIND CALLING A FUNCTION WITH.
    //! ONE SINGLE PARAMETER OF A CLASS

    // StdBind::PrintString function creation

    typedef function<void(const string&)> exampleFunctionTemplate1;

    // StdBind::PrintString function binding

    exampleFunctionTemplate1 exampleFunctionInstance1 = bind(&StdBind::PrintString, &instance, _1);

    // StdBind::PrintString function execution

    exampleFunctionInstance1(string1);

    //! EXAMPLE 2: CALLING A FUNCTION OF A CLASS WITH TWO PARAMETERS WITH BIND

    // StdBind::ConcatString function creation

    typedef function<string(const string&, const string&)> exampleFunctionTemplate2;

    //StdBind::ConcatString function binding

    exampleFunctionTemplate2 exampleFunctionInstance2 = bind(&StdBind::ConcatString, &instance, _1, _2);

    // StdBind::ConcatString function execution and retrieving

    response = exampleFunctionInstance2(string1, string2);

    // StdBind::ConcatString return printingreturn printing

    cout << "StdBind::ConcatString return: " << response << endl;

    //! EXAMPLE 3: CALLING A FUNCTION DEFINED IN THIS CPP WITH BIND

    // InverseString function creation by using type deduction.

    auto exampleFunctionInstance3 = bind(&InverseString, _1);

    // InverseString fuction execution and retrieving

    response = exampleFunctionInstance3(string1);

    // InverseString function return printing

    cout << "InverseString: " << response << endl;

    //! EXAMPLE 4: CALLING A FUNCTION WITH NESTED BIND EXECUTIONS

    // nested bind functions can be called

    auto exampleFunctionInstance4 = bind(&StdBind::ConcatString, &instance, _1, bind(&InverseString, _2));

    response = exampleFunctionInstance4(string1, string2);

    cout << "ConcatString with InverseString on second parameter: " << response << endl;

    //! EXAMPLE 5: CALLING A FUNCTION WITHOUT PLACEHOLDERS

    auto exampleFunctionInstance5 = bind(&StdBind::PrintString, &instance, "My string passed in bind function and no placeholder");

    exampleFunctionInstance5();



    //! LAMBDA EXPRESIONS

    // Lambda form: [capture](parameters) -> return_type { function_body }

    //! EXAMPLE 6: SIMPLEST LAMBDA DEFINITION AND INVOCATION.

    auto lambda = []() { cout << "Code within a lambda expression" << endl; };
    lambda();

    //! EXAMPLE 7: LAMBDA WITH PARAMETERS.

    // Alone ampersand means that all kind of pareter is passed by reference.
    auto sum = [&](int x, int y) -> int { return x + y; };
    cout << "Simple lambda 5 plus 8 is: " << sum(5, 8) << endl;

    //! EXAMPLE 8: LAMBDA WITH PARAMETERS INSIDE A CLASS.

    LambdaCall l;
    auto classSum = l.sum();
    cout << "Class lambda sum, 8 plus 5 is: " << classSum(5, 8) << endl;

    return 0;
}
