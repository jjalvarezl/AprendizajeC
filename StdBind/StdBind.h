#pragma once
#include <cstring>
#include <iostream>

class StdBind
{
public:
    void PrintString (const std::string &parameter) const;
    std::string ConcatString(const std::string &parameter1, const std::string &parameter2);
};
