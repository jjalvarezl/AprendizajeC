#include "SmartPointers.h"
#include <iostream>

using namespace std;

int main()
{
    SmartPointers p; // Is not a raw pointer, it will delete when program ends
    p.UniquePtrExample();
    p.SharedPtrExample();
    p.WeakPtrExample();
    return 0;
}
