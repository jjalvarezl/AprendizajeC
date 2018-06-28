#include "StdBind.h"

using namespace std;

void StdBind::PrintString(const string &parameter) const
{
    cout << "PrintString function says: " << parameter << endl;
}

string StdBind::ConcatString(const string &parameter1, const string &parameter2)
{
    string concat = parameter1 +  parameter2;
    return concat;
}
