#pragma once
#include <functional>

class LambdaCall
{
public:
    std::function <int(const int&, const int&)> sum();
};
