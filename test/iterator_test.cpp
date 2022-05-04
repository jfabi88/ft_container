#include "utils.hpp"
#include <iostream>
#include <vector>

int main()
{
    ft::vector<int>     ftv(5, 42);
    std::vector<int>    stdv(5, 42);
    ft::vector<int>::iterator jt;
    ft::vector<int>::iterator b;
    ft::vector<int>::const_iterator a;
    std::vector<int>::const_iterator sit;
    std::vector<int>::iterator sit2;
    
    ftv.at(3) = 5; stdv.at(3) = 5;
    print_vector("vector", ftv, 0, true);
    jt = ftv.begin() + 3;
    std::cout << std::boolalpha;
    std::cout << "Il valore di tmp.begin + 3: " << *jt << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) - tmp.begin: " << jt - ftv.begin() << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) - tmp.end: " << jt - ftv.end() << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) == (tmp.begin + 3): " << (jt == ftv.begin() + 3) << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) == (tmp.begin + 2): " << (jt == ftv.begin() + 2) << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) != (tmp.begin + 3): " << (jt != ftv.begin() + 3) << std::endl;
    std::cout << "Il valore di (tmp.begin + 3) != (tmp.begin + 2): " << (jt != ftv.begin() + 2) << std::endl;
    
    ft::vector<int>::iterator ut(jt);
    std::cout << "Il valore di ut(jt): " << *ut << std::endl;
    sit = stdv.begin();

    //a=const_iterator b=iterator
    b = ftv.begin();
    a = b;

    ft::vector<int>::const_iterator c(a), d(c);
    std::cout << "2) " << *c << " == " << *a << std::endl;
    std::cout << "3) " << *d << " == " << *c << std::endl;


    ft::vector<int>::iterator f(b);
    std::cout << "4) " << *f << " == " << *b << std::endl;
    //std::cout << "5) " << *g << " == " << *a << std::endl;

    std::vector<int>::const_iterator h(sit), i(sit2);
    std::vector<int>::iterator l(sit2);

    sit = sit2;
    jt = ftv.begin();
    

    
    //sit = ftv.begin();
   
   
    return (0);
}