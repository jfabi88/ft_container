#include <iostream>
#include <map>
#include "../../sources/tree.hpp"

int main(){

    ft::Tree<std::string, int> tree;
    ft::Node<std::string, int> a("a", 11);
    ft::Node<std::string, int> b("b", 12);

    //std::boolalpha;
    std::cout << a.value.first << "/" << a.value.first << std::endl;
    std::cout << b.value.first << "/" << b.value.first << std::endl;
    std::cout << (a < b) << std::endl;

}