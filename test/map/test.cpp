#include <iostream>
#include <map>
#include "../../sources/map.hpp"

int main(){

    std::map<float, int> a;
    ft::map<float, int> aa;
    std::map<std::string, std::string> b;
    ft::map<std::string, std::string> bb;
    std::map<bool, int> c;
    ft::map<bool, int> cc;

    std::cout << "int: " << sizeof(int) << std::endl;
    std::cout << "float: " << sizeof(float) << std::endl;
    std::cout << "double: " << sizeof(double) << std::endl;
    std::cout << "chzr: " << sizeof(char) << std::endl;
    std::cout << "string: " << sizeof(std::string) << std::endl;
    std::cout << "bool: " << sizeof(bool) << std::endl;


    std::cout << "std: " <<  a.max_size() << std::endl;
    std::cout << "ft: " << aa.max_size() << std::endl;

    std::cout <<  "std: " << b.max_size() << std::endl;
    std::cout <<  "ft: " << bb.max_size() << std::endl;

    std::cout <<  "std: " << c.max_size() << std::endl;
    std::cout <<  "ft: " << cc.max_size() << std::endl;


    
}