#include <iostream>

template <class T>
class b_iterator {
    public:
        typedef std::random_access_iterator_tag iterator_category;
        typedef T               value_type;
        typedef std::ptrdiff_t  difference_type;
        typedef T*              pointer;
        typedef T&              reference;

        b_iterator()  { _ptr = NULL; };
        b_iterator(pointer p) {_ptr = p; }
        b_iterator(const b_iterator &s) { _ptr = s._ptr; }
        ~b_iterator(){};

        reference   operator*() const   { return *_ptr; }
        pointer     operator->()        { return _ptr; }

        b_iterator&   operator++()        { _ptr++; return *this; }
        b_iterator    operator++(int)     { b_iterator tmp = *this; _ptr++; return *this; }

        b_iterator&   operator--()        { _ptr--; return *this; }
        b_iterator    operator--(int)     { b_iterator tmp = *this; _ptr--; return *this; }

        friend bool    operator== (const b_iterator &f, const b_iterator &s) { return (f._ptr == s._ptr); }
        friend bool    operator!= (const b_iterator &f, const b_iterator &s) { return (f._ptr != s._ptr); }
        bool    operator<(const b_iterator &s)    { return (_ptr < s._ptr); }
        bool    operator>(const b_iterator &s)    { return (_ptr > s._ptr); }
        bool    operator<=(const b_iterator &s)    { return (_ptr <= s._ptr); }
        bool    operator>=(const b_iterator &s)    { return (_ptr >= s._ptr); }

        b_iterator    operator+(difference_type n)    { return b_iterator(_ptr + n); }
        b_iterator    operator-(difference_type n)    { return b_iterator(_ptr - n); }
        difference_type operator+(const b_iterator &s)    { return (_ptr + s._ptr); }
        difference_type operator-(const b_iterator &s)    { return (_ptr - s._ptr); }

        b_iterator    operator+=(difference_type n)   { _ptr += n; return (*this); }
        b_iterator    operator-=(difference_type n)   { _ptr -= n; return (*this); }

        value_type  operator[](difference_type n)  { return (_ptr + n); }
        b_iterator    &operator=(const b_iterator &s) { _ptr = s._ptr;  return (*this);}
    private:
        pointer _ptr;
};