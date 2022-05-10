#include <iostream>
#include <vector>
#include <memory>
#include "utils.hpp"


int main(){

ft::vector<int> v(10,2);
std::vector<int> sv(10,2);

for(size_t i= 0; i < v.size() + 1; i++)
    std::cout << sv.at(i) << " ";
std::cout << std::endl;
}