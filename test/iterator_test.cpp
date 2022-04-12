#include "../sources/vector.hpp"
#include <iostream>
#include <vector>

int main()
{
    ft::vector<int>     ctmp(8, 32);
    std::vector<int>    stmp(8, 32);
    ft::vector<int>::iterator jt;
    ft::vector<int>::const_iterator cit;
    std::vector<int>::const_iterator sit;
    std::vector<int>::iterator sit2;

    int diff;

    for (ft::vector<int>::iterator it = ctmp.begin(); it < ctmp.end(); it++)
        std::cout << "Il valore dell'iteratore: " << *it << std::endl;
    jt = ctmp.begin() + 3;
    std::cout << std::boolalpha;
    std::cout << "Il valore di tmp.begin + 3: " << *jt << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) - tmp.begin: " << jt - ctmp.begin() << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) - tmp.end: " << jt - ctmp.end() << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) == (tmp.begin + 3): " << (jt == ctmp.begin() + 3) << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) == (tmp.begin + 2): " << (jt == ctmp.begin() + 2) << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) != (tmp.begin + 3): " << (jt != ctmp.begin() + 3) << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) != (tmp.begin + 2): " << (jt != ctmp.begin() + 2) << std::endl;
    ft::vector<int>::iterator ut(jt);
    std::cout << "Il valore di ut(jt): " << *ut << std::endl;
    sit = cit;
    sit = stmp.begin();
    cit = stmp.begin();
    //sit = ctmp.begin();
   
   
    return (0);
}