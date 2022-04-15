#include <iostream>
#include <vector>
#include "../sources/vector.hpp"

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
/*     std::cout << std::boolalpha;
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
    std::cout << "my_class:                      " <<ft::is_iterator<my_class>::value << std::endl; */


    std::vector<int> v;
    ft::vector<int>  cv;
  for (int i=1; i<11; i++) {
        v.push_back(i);
        cv.push_back(i);
    }

    std::cout << "begin/end/it++:\n";
    for( std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << *it << " ";
    }
    std::cout<< std::endl;

    for( ft::vector<int>::iterator fit = cv.begin(); fit != cv.end(); fit++){
        std::cout << *fit << " ";
    }
    std::cout<< std::endl;

    std::cout << "begin/end/++it:\n";
    for( std::vector<int>::iterator it = v.begin(); it != v.end(); ){
        std::cout << *(++it) << " ";
    }
    std::cout<< std::endl;

    for( ft::vector<int>::iterator fit = cv.begin(); fit != cv.end(); ){
        std::cout << *(++fit) << " ";
    }
    std::cout<< std::endl;

    std::cout << "operator+/operator-/operator==/operator>:\n";
    std::vector<int>::iterator it = v.begin();
    ft::vector<int>::iterator cit= cv.begin();

    std::cout << *(it + 4) << " " << *(v.end() - 2) << " " << ((v.end() - 2) == (v.begin() + 8)) << " ";
    std::cout << ((v.end() - 1) > (v.begin() + 7)) << "\n";
    std::cout << *(cit + 4) << " " << *(cv.end() - 2) << " " << ((cv.end() - 2) == (cv.begin() + 8)) << " ";
    std::cout << ((cv.end() - 1) > (cv.begin() + 7)) << "\n";

    return (0);
}