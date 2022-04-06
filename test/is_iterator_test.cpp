#include <iostream>
#include <vector>
#include "../sources/iterator_traits.hpp"

int main()
{
    std::cout << std::boolalpha;
    std::cout << "char is iterator: " <<ft::is_iterator<char>::value << std::endl;
    std::cout << "vector.begin() is iterator: " <<ft::is_iterator<std::vector<int>::iterator>::value << std::endl;
    return (0);
}