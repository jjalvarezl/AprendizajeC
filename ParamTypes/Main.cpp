#include "ParamTypes.cpp"
#include <iostream>

using namespace std;

int main()
{
    ParamTypes <int32_t> myParamTypesIntegerObject;
    ParamTypes <double> myParamTypesDoubleObject;

    cout << "Minimum value for integers is: " << myParamTypesIntegerObject.GetMinimumValue(70,60) << endl;
    cout << "Minimum value for doubles is: " << myParamTypesDoubleObject.GetMinimumValue(2.5,3.8) << endl;
    return 0;
}
