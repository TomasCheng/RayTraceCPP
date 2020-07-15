#pragma once

namespace util
{
    template <class T>
    T clamp(const T v, const T v1, const T v2)
    {
        T res = v;
        if (v < v1)
        {
            res = v1;
        }
        else if (v > v2)
        {
            res = v2;
        }
        return res;
    }

} // namespace util