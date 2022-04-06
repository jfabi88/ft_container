#include <iostream>

namespace ft
{
    template <bool Cond, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> {typedef T type;};

    template <class = void, class = void, class = void, class = void, class = void>
    struct void_t {typedef void value;};

    template <class T, class = void>
    struct iterator_traits {};

    template <class T>
    struct iterator_traits<T, typename void_t<
                            typename T::value_type,
                            typename T::difference_type,
                            typename T::iterator_category,
                            typename T::pointer,
                            typename T::reference>::value
                        > {
        typedef typename T::value_type            value_type;
        typedef typename T::difference_type       difference_type;
        typedef typename T::iterator_category     iterator_category;
        typedef typename T::pointer               pointer;
        typedef typename T::reference             reference;
    };

    template<class T, typename v = void>
    struct has_iterator_traits
    {
        const static bool value = false;
    };

    template<typename T>
    struct has_iterator_traits<typename T::value_type, T>
    {
        const static bool value = true;
    };

    template<typename T, typename = void>
    struct is_iterator
    {
        const static bool value = false;
    };

    template<typename T>
    struct is_iterator<T, typename std::enable_if<has_iterator_traits<typename ft::iterator_traits<T>::value_type, T>::value, void>::type>
    {
        const static bool value = true;
    };
}