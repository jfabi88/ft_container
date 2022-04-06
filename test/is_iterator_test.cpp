#include <iostream>
#include <vector>
#include "../sources/structs.hpp"

class my_class
{
    public:
        typedef int value_type;
        typedef int difference_type;
        typedef int iterator_category;
        typedef int pointer;
        typedef int reference;
};

int main()
{
    std::cout << std::boolalpha;
    std::cout << "   Is an iterator?" << std::endl;
    std::cout << "char:                          " <<ft::is_iterator<char>::value << std::endl;
    std::cout << "std::string:                   " <<ft::is_iterator<std::string>::value << std::endl;
    std::cout << "int:                           " <<ft::is_iterator<int>::value << std::endl;
    std::cout << "float:                         " <<ft::is_iterator<float>::value << std::endl;
    std::cout << "int *:                         " <<ft::is_iterator<int*>::value << std::endl;
    std::cout << "char*:                         " <<ft::is_iterator<char*>::value << std::endl;
    std::cout << "vector<int>::iterator:         " <<ft::is_iterator<std::vector<int>::iterator>::value << std::endl;
    std::cout << "vector<char>::iterator:        " <<ft::is_iterator<std::vector<char>::iterator>::value << std::endl;
    std::cout << "vector<std::string>::iterator: " <<ft::is_iterator<std::vector<std::string>::iterator>::value << std::endl;
    std::cout << "vector<int*>::iterator:        " <<ft::is_iterator<std::vector<int*>::iterator>::value << std::endl;
    std::cout << "vector<float>::iterator:       " <<ft::is_iterator<std::vector<float>::iterator>::value << std::endl;
    std::cout << "vector<float>:                 " <<ft::is_iterator<std::vector<float> >::value << std::endl;
    std::cout << "my_class:                      " <<ft::is_iterator<my_class>::value << std::endl;
    return (0);
}