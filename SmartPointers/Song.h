#pragma once
#include <iostream>

struct Song
{
    std::string m_Name;
    std::string m_Author;
    int m_Id;
    Song(const int id);
    ~Song();
    void Function();
};
