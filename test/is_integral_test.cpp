#include <iostream>
#include <vector>

template <bool Cond, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> {typedef T type;};

template<class T, typename v = void>
struct has_iterator_traits
{
    const static bool value = false;
};

template<typename T>
struct has_iterator_traits<typename T::difference_type, T>
{
    const static bool value = true;
};

template<typename T>
struct has_iterator_traits<typename T::value_type, T>
{
    const static bool value = true;
};


template <class T>
struct iterator_traits {
    const   static bool value = false;
};

template <class T>
struct iterator_traits<T> {
    typedef typename T::value_type            value_type;
    typedef typename T::difference_type       difference_type;
    typedef typename T::iterator_category     iterator_category;
    typedef typename T::pointer               pointer;
    typedef typename T::reference             reference;
    const   static bool value = true;
};

template<typename T, typename = void>
struct is_iterator
{
    const static bool value = true;
};

template<typename T>
struct is_iterator<T, typename std::enable_if<!has_iterator_traits<typename T::difference_type, T>::value, void>::type>
{
    const static bool value = false;
};

template<typename T>
struct is_iterator<T, typename std::enable_if<!has_iterator_traits<typename T::value_type, T>::value, void>::type>
{
    const static bool value = false;
};

/* template<typename T, typename = void>
struct is_iterator
{
    const static bool value = false;
};

template<typename T>
struct is_iterator<T, typename std::enable_if<has_iterator_traits<typename T::difference_type, T>::value && has_iterator_traits<typename T::value_type, T>::value, void>::type>
{
    const static bool value = true;
}; */

int main()
{
    std::cout << std::boolalpha;
    //std::cout << "int * is integral: " << std::is_integral<int *>::value << std::endl;
    //std::cout << "std::string is integral: " << std::is_integral<std::string>::value << std::endl;
    //std::cout << "int * is iterator: " << is_iterator<int *>::value << std::endl;
    //std::cout << "std::string is iterator: " <<is_iterator<std::string>::value << std::endl;
    //std::cout << "int is iterator: " << is_iterator<int>::value << std::endl;
    std::cout << "char is iterator: " <<is_iterator<char>::value << std::endl;
    std::cout << "vector.begin() is iterator: " <<is_iterator<std::vector<int>::iterator>::value << std::endl;
    typedef std::vector<int>::iterator::difference_type c;
    std::iterator_traits<std::vector<int>::iterator>::difference_type pollo;
    return (0);
}