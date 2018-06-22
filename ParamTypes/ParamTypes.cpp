#include "ParamTypes.h"

template <typename T>
T ParamTypes<T>::GetMinimumValue(const T& lhs, const T& rhs) const
{
    return lhs < rhs ? lhs : rhs;
}
