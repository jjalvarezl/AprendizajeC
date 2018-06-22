#include "StdBind.h"
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

string InverseString (string& parameter) {
    reverse(parameter.begin(), parameter.end());
    return parameter;
}

int main()
{
    StdBind instance;
    string string1 = "My string 1";
    string string2 = "My string 2";
    string string3 = "My string 3";
    string response = "";



    // StdBind::PrintString function creation

    typedef function<void(const string&)> exampleFunctionTemplate1;

    // StdBind::PrintString function binding

    exampleFunctionTemplate1 exampleFunctionInstance1 =
            bind (&StdBind::PrintString, &instance, placeholders::_1);

    // StdBind::PrintString function execution

    exampleFunctionInstance1(string1);




    // StdBind::ConcatString function creation

    typedef function<string(const string&, const string&)> exampleFunctionTemplate2;

    //StdBind::ConcatString function binding

    exampleFunctionTemplate2 exampleFunctionInstance2 =
            bind (&StdBind::ConcatString, &instance, placeholders::_1, placeholders::_2);

    // StdBind::ConcatString function execution and retrieving

    response = exampleFunctionInstance2 (string1, string2);

    // StdBind::ConcatString return printingreturn printing

    cout << "StdBind::ConcatString return: " << response << endl;




    // InverseString function creation by using type deduction.

    auto exampleFunctionInstance3 = bind (&InverseString, placeholders::_1);

    // InverseString fuction execution and retrieving

    response = exampleFunctionInstance3 (string1);

    // InverseString function return printing

    cout << "InverseString: " << response;


    return 0;
}
