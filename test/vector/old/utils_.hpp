#include <iostream>
#include <vector>
#include "../../../sources/vector.hpp"
#define KGRN  "\x1B[32m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m" 


template <class T>
void    print_sz_cp(std::vector<T> &vector)
{
    std::cout << "std::vector size: " << vector.size() << std::endl;
    std::cout << "std::vector capacity: " << vector.capacity() << std::endl;
}

template <class T>
void    print_sz_cp(ft::vector<T> &vector)
{
    std::cout << "ft::vector size: " << vector.size() << std::endl;
    std::cout << "ft::vector capacity: " << vector.capacity() << std::endl;
}

template <class T>
void print_vector(std::string title, std::vector<T> &vector, size_t n = 0, bool extra = false)
{
    typedef typename std::vector<T>::iterator iterator;
    iterator it;
   /*  if (title != ""){ */
        std::cout << title;
        if (extra){
            std::cout << " (size = " << vector.size() <<  ", capacity = " << vector.capacity() << ")";
        }
        std::cout << std::endl;
/*     } */
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
void print_vector(std::string title, ft::vector<T> &vector, size_t n = 0, bool extra = false)
{
    typedef typename ft::vector<T>::iterator iterator;
    iterator it;
    //if (title != ""){
        std::cout << title;
        if (extra){
            std::cout << " (size = " << vector.size() <<  ", capacity = " << vector.capacity() << ")";
        }
        std::cout << std::endl;
    //}
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

//ft::b_iterator

/* template <class T>
void prIterator(typename ft::b_iterator<typename ft::vector<T>::pointer> &fit)
{
    std::cout << "  (" << *fit << " == "<< *sit << ")? " << (*fit == *sit) << std::endl;
    std::cout << "]" << std::endl;
}

template <class T>
void prIterator(typename ft::vector<T>::iterator &fit)
{
    if (title != "")
        std::cout << title << " ";
    std::cout << "  (" << *fit << " == "<< *sit << ")? " << (*fit == *sit) << std::endl;
    std::cout << "]" << std::endl;
} */

template <class T>
void eqiterator(std::string title, typename ft::b_iterator<typename ft::vector<T>::pointer> &fit, typename std::vector<T>::iterator &sit)
{
    if (title != "")
        std::cout << title << " ";
    std::cout << "  (" << *fit << " == "<< *sit << ")? " << (*fit == *sit) << std::endl;
    std::cout << "]" << std::endl;
}

template <class T>
void eqiterator(std::string title, typename ft::vector<T>::iterator &fit, typename std::vector<T>::iterator &sit)
{
    if (title != "")
        std::cout << title << " ";
    std::cout << "  (" << *fit << " == "<< *sit << ")? " << (*fit == *sit) << std::endl;
    std::cout << "]" << std::endl;
}