#include "../sources/vector.hpp"
#include <iostream>

int main()
{
    ft::vector<int> tmp(8, 32);
    ft::vector<int>::iterator jt;

    int diff;

    for (ft::vector<int>::iterator it = tmp.begin(); it < tmp.end(); it++)
        std::cout << "Il valore dell'iteratore: " << *it << std::endl;
    jt = tmp.begin() + 3;
    std::cout << std::boolalpha;
    std::cout << "Il valore di tmp.begin + 3: " << *jt << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) - tmp.begin: " << jt - tmp.begin() << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) - tmp.end: " << jt - tmp.end() << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) == (tmp.begin + 3): " << (jt == tmp.begin() + 3) << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) == (tmp.begin + 2): " << (jt == tmp.begin() + 2) << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) != (tmp.begin + 3): " << (jt != tmp.begin() + 3) << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) != (tmp.begin + 2): " << (jt != tmp.begin() + 2) << std::endl;
    ft::vector<int>::iterator ut(jt);
     std::cout << "Il valore di ut(jt): " << *ut << std::endl;
    return (0);
}