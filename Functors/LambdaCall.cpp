#include "LambdaCall.h"

using namespace std;

function<int(const int&, const int&)> LambdaCall::sum()
{
    return [&](const int a, const int b){ return a + b; };
}
