#include <iostream>

template <bool Cond, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> {typedef T type;};

template <class T>
bool is_odd(T n)
{
    typename enable_if<std::is_integral<T>::value, bool>::type pollo;
    return ((n % 2) == 0);
}

int main()
{
    int i = 1;
    //std::string i = "sale";
    //float i = 43.2;

    std::cout << std::boolalpha;
    std::cout << "i is odd: " << is_odd(i) << std::endl;

    return (0);
}