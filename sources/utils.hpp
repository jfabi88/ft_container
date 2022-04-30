#include <iostream>
#include "structs.hpp"
#include <filesystem>
#include <cstdint>
#include <sstream>

namespace ft
{
    template<typename T>
    void swap(T & x, T & y)
    {
        T z = x;
        x = y;
        y = z;
    }
}