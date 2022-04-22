#include <iostream>
#include <vector>
#include "../sources/vector.hpp"

template <class T>
void print_vector(std::string title, std::vector<T> vector)
{
    if (title != "")
        std::cout << title << std::endl;
    std::cout << "  [";
    for (size_t i = 0; i < vector.size() - 1; i++)
        std::cout << vector.at(i) << ", ";
    std::cout << vector.at(vector.size() - 1) << "]" << std::endl;
}

template <class T>
void print_vector(std::string title, ft::vector<T> vector)
{
    if (title != "")
        std::cout << title << std::endl;
    std::cout << "  [";
    for (size_t i = 0; i < vector.size() - 1; i++)
        std::cout << vector.at(i) << ", ";
    std::cout << vector.at(vector.size() - 1) << "]" << std::endl;
}