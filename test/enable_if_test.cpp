#include <iostream>

template <bool Cond, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> {typedef T type;};

//Jfabi: Caso 1 int --- Caso 2 std::string
//Caso 1:   enable_if<true, int> richiama il secondo costruttore di enable_if in cui é
//          definito type. Di conseguenza il codice compila senza problemi.
//Casi 2:   enable_if<false, int> richiama il primo costruttore di enable_if in cui non
//          é definito type. Di conseguenza il codice non compila.

template <class T>
bool is_even(T n)
{
    typename enable_if<std::is_integral<T>::value, int>::type pollo;
    std::cout << std::is_integral<T>::value << std::endl;
    return ((n % 2) != 0);
}

//Jfabi: Caso 1 int --- Caso 2 std::string
//Caso 1:   Inizialmente il compilatore prova a compilare la seconda funzione bool is_odd(typename enable_if<..>::type var).
//          L'enable_if é enable_if<true, int> quindi chiama il secondo costruttore di enable if in cui é definito l'argomento
//          type. Di conseguenza enable_if::type esiste e il codice compila.
//Caso 2:   Inizialmente il compilatore prova a compilare la seconda funzione bool is_odd(typename enable_if<..>::type var).
//          Nel caso 2 l'enable if é enable_if<false, int> quindi chiama il primo costruttore di enable_if
//          in cui l'argomento type non é definito. Di conseguenza enable_if::type non esiste e il codice quindi non puó 
//          compilare con questa funzione. Richiama quindi bool is_odd(T var) che compila. 

bool is_odd(int var)
{
    //std::cout << std::is_integral<T>::value << std::endl;
    return (true);
}

template <class T>
bool is_odd(T var, typename enable_if<!std::is_integral<T>::value, T>::type* = 0)
{
    return (false);
}

int main()
{
    //int i = 1;
    std::string i = "sale";

    std::cout << std::boolalpha;
    //std::cout << "i is even: " << is_even(i) << std::endl;
    std::cout << "i is odd: " << is_odd(i) << std::endl;

    return (0);
}