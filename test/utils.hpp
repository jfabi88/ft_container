#include <iostream>
#include <vector>
#include "../sources/vector.hpp"
#define KGRN  "\x1B[32m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m" 

/* template <class T>
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
} */

template <class T>
void print_vector(std::string title, std::vector<T> vector, size_t n = 0)
{
    typedef typename std::vector<T>::iterator iterator;
    iterator it;
    if (title != "")
        std::cout << title << std::endl;
    std::cout << "  [";
    for (it = (vector.begin() - n); it != vector.end() + n; it++){
        if (it == vector.begin() || it == vector.end() -1)
            std::cout << GREEN;
        std::cout << *(it) << RESET;
        if (it != vector.end() + n - 1) 
            std::cout <<  ", ";
    }
    std::cout << "]" << std::endl;
}

template <class T>
void print_vector(std::string title, ft::vector<T> vector, size_t n = 0)
{
    typedef typename ft::vector<T>::iterator iterator;
    iterator it;
    if (title != "")
        std::cout << title << std::endl;
    std::cout << "  [";
    for (it = (vector.begin() - n); it != vector.end() + n; it++){
        if (it == vector.begin() || it == vector.end() -1)
            std::cout << GREEN;
        std::cout << *(it) << RESET;
        if (it != vector.end() + n - 1) 
            std::cout <<  ", ";
    }
    std::cout << "]" << std::endl;
}
