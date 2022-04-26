#include <iostream>
#include "structs.hpp"

namespace ft
{   
/*   ///  Marking input iterators.
  struct input_iterator_tag {};
  ///  Marking output iterators.
  struct output_iterator_tag {};
  /// Forward iterators support a superset of input iterator operations.
  struct forward_iterator_tag : public input_iterator_tag {};
  /// Bidirectional iterators support a superset of forward iterator
  /// operations.
  struct bidirectional_iterator_tag : public forward_iterator_tag {};
  /// Random-access iterators support a superset of bidirectional iterator
  /// operations.
  struct random_access_iterator_tag : public bidirectional_iterator_tag {}; */


template <class T>
struct iterator_traits {
	typedef typename T::value_type            value_type;
	typedef typename T::difference_type       difference_type;
	typedef typename T::iterator_category     iterator_category;
	typedef typename T::pointer               pointer;
	typedef typename T::reference             reference;
};

// Specialization
template <class T>
struct iterator_traits<T*> {
	typedef T                         	 		value_type;
	typedef ptrdiff_t                 	 		difference_type;
	typedef std::random_access_iterator_tag		iterator_category;
	typedef T*                        		 	pointer;
	typedef T&									reference;
};


template< class, class = void >
struct is_iterator : public false_type{};

template< class T >
struct is_iterator <T, typename void_t<
					typename T::value_type,
					typename T::difference_type,
					typename T::iterator_category,
					typename T::pointer,
					typename T::reference>::value> : public true_type{};

/* template<class, class = void>
struct has_iterator_traits
{
	const static bool value = false;
};

template< class T >
struct has_iterator_traits <T, iterator_traits<T> > : public true_type{}; */

/* template< class T >
struct is_iterator <T, void_t<
					typename T::value_type,
					typename T::difference_type,
					typename T::iterator_category,
					typename T::pointer,
					typename T::reference>>
{ 
	static const bool value = true;
}; */

/* template< class T >
struct is_iterator <T, typename void_t<iterator_traits<T>>::value>
{ 
	static const bool value = true;
}; */



/* template< class T >
struct is_iterator <T, typename void_t<
					typename iterator_traits<T>::value_type,
					typename iterator_traits<T>::difference_type,
					typename iterator_traits<T>::iterator_category,
					typename iterator_traits<T>::pointer,
					typename iterator_traits<T>::reference>::value>
{ 
	static const bool value = true;
}; */


template <class T>
class iterator {
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T               				value_type;
		typedef std::ptrdiff_t  				difference_type;
		typedef T*              				pointer;
		typedef T&              				reference;

		iterator()  { _ptr = NULL; };
		iterator(pointer p) {_ptr = p; }
		iterator(const iterator &s) { _ptr = s._ptr; }
		~iterator(){};

		reference   operator*() const   { return *_ptr; }
		pointer     operator->()        { return _ptr; }

		//prefix increment operator
		iterator&   operator++()        { _ptr++; return *this; }
		//postfix increment operator
		iterator    operator++(int)     { iterator tmp = *this; _ptr++; return tmp; }

		iterator&   operator--()        { _ptr--; return *this; }
		iterator    operator--(int)     { iterator tmp = *this; _ptr--; return tmp; }

		friend bool    operator== (const iterator &f, const iterator &s) { return (f._ptr == s._ptr); }
		friend bool    operator!= (const iterator &f, const iterator &s) { return (f._ptr != s._ptr); }
		bool    operator<(const iterator &s)    { return (_ptr < s._ptr); }
		bool    operator>(const iterator &s)    { return (_ptr > s._ptr); }
		bool    operator<=(const iterator &s)    { return (_ptr <= s._ptr); }
		bool    operator>=(const iterator &s)    { return (_ptr >= s._ptr); }

		iterator    operator+(difference_type n)    { return iterator(_ptr + n); }
		iterator    operator-(difference_type n)    { return iterator(_ptr - n); }
		difference_type operator+(const iterator &s)    { return (_ptr + s._ptr); }
		difference_type operator-(const iterator &s)    { return (_ptr - s._ptr); }

		iterator    operator+=(difference_type n)   { _ptr += n; return (*this); }
		iterator    operator-=(difference_type n)   { _ptr -= n; return (*this); }

		value_type  operator[](difference_type n)  { return (_ptr + n); }

		iterator<T>    &operator=(const iterator<T> &s) { _ptr = s._ptr;  return (*this);}
		operator const_iterator() { return const_iterator(_ptr); }
	private:
		pointer _ptr;
};

template <class T>
class const_iterator {
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T               				value_type;
		typedef std::ptrdiff_t  				difference_type;
		typedef const T*              			pointer;
		typedef const T&              			reference;

		const_iterator()  { _ptr = NULL; };
		const_iterator(pointer p) {_ptr = p; }
		const_iterator(const const_iterator &s) { _ptr = s._ptr; }
		~const_iterator(){};

		reference   operator*() const   { return *_ptr; }
		pointer     operator->()        { return _ptr; }

		//prefix increment operator
		const_iterator&   operator++()        { _ptr++; return *this; }
		//postfix increment operator
		const_iterator    operator++(int)     { const_iterator tmp = *this; _ptr++; return tmp; }

		const_iterator&   operator--()        { _ptr--; return *this; }
		const_iterator    operator--(int)     { const_iterator tmp = *this; _ptr--; return tmp; }

		friend bool    operator== (const const_iterator &f, const const_iterator &s) { return (f._ptr == s._ptr); }
		friend bool    operator!= (const const_iterator &f, const const_iterator &s) { return (f._ptr != s._ptr); }
		bool    operator<(const const_iterator &s)    { return (_ptr < s._ptr); }
		bool    operator>(const const_iterator &s)    { return (_ptr > s._ptr); }
		bool    operator<=(const const_iterator &s)    { return (_ptr <= s._ptr); }
		bool    operator>=(const const_iterator &s)    { return (_ptr >= s._ptr); }

		const_iterator    operator+(difference_type n)    { return const_iterator(_ptr + n); }
		const_iterator    operator-(difference_type n)    { return const_iterator(_ptr - n); }
		difference_type operator+(const const_iterator &s)    { return (_ptr + s._ptr); }
		difference_type operator-(const const_iterator &s)    { return (_ptr - s._ptr); }

		const_iterator    operator+=(difference_type n)   { _ptr += n; return (*this); }
		const_iterator    operator-=(difference_type n)   { _ptr -= n; return (*this); }

		value_type  operator[](difference_type n)  { return (_ptr + n); }


		const_iterator<T>  &operator=(const const_iterator<T> &s) { _ptr = s._ptr;  return (*this);}
		//friend const_iterator<T>    &operator=(const iterator<T> &s) { _ptr = s._ptr;  return (*this);}
		const_iterator<T>  &operator=(const iterator<T> &s) {  _ptr = s._ptr;  return (*this);}
	private:
		pointer _ptr;
};

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

		//prefix increment operator
		b_iterator&   operator++()        { _ptr++; return *this; }
		//postfix increment operator
		b_iterator    operator++(int)     { b_iterator tmp = *this; _ptr++; return tmp; }

		b_iterator&   operator--()        { _ptr--; return *this; }
		b_iterator    operator--(int)     { b_iterator tmp = *this; _ptr--; return tmp; }

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

		b_iterator<T>    &operator=(const b_iterator<T> &s) { _ptr = s._ptr;  return (*this);}
	private:
		pointer _ptr;
};

template <class T>
class b_reverse_iterator {
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T               value_type;
		typedef std::ptrdiff_t  difference_type;
		typedef T*              pointer;
		typedef T&              reference;

		b_reverse_iterator()  { _ptr = NULL; };
		b_reverse_iterator(pointer p) {_ptr = p; }
		b_reverse_iterator(const b_reverse_iterator &s) { _ptr = s._ptr; }
		~b_reverse_iterator(){};

		reference   operator*() const   { return *_ptr; }
		pointer     operator->()        { return _ptr; }

		//prefix increment operator
		b_reverse_iterator&   operator++()        { _ptr--; return *this; }
		//postfix increment operator
		b_reverse_iterator    operator++(int)     { b_reverse_iterator tmp = *this; _ptr--; return tmp; }

		b_reverse_iterator&   operator--()        { _ptr++; return *this; }
		b_reverse_iterator    operator--(int)     { b_reverse_iterator tmp = *this; _ptr++; return tmp; }

		friend bool    operator== (const b_reverse_iterator &f, const b_reverse_iterator &s) { return (f._ptr == s._ptr); }
		friend bool    operator!= (const b_reverse_iterator &f, const b_reverse_iterator &s) { return (f._ptr != s._ptr); }
		bool    operator<(const b_reverse_iterator &s)    { return (_ptr > s._ptr); }
		bool    operator>(const b_reverse_iterator &s)    { return (_ptr < s._ptr); }
		bool    operator<=(const b_reverse_iterator &s)    { return (_ptr >= s._ptr); }
		bool    operator>=(const b_reverse_iterator &s)    { return (_ptr <= s._ptr); }

		b_reverse_iterator    operator+(difference_type n)    { return b_reverse_iterator(_ptr - n); }
		b_reverse_iterator    operator-(difference_type n)    { return b_reverse_iterator(_ptr + n); }
		difference_type operator+(const b_reverse_iterator &s)    { return (_ptr - s._ptr); }
		difference_type operator-(const b_reverse_iterator &s)    { return (_ptr + s._ptr); }

		b_reverse_iterator    operator+=(difference_type n)   { _ptr -= n; return (*this); }
		b_reverse_iterator    operator-=(difference_type n)   { _ptr += n; return (*this); }

		value_type  operator[](difference_type n)  { return (_ptr - n); }

		b_reverse_iterator<T>    &operator=(const b_reverse_iterator<T> &s) { _ptr = s._ptr;  return (*this);}

	private:
		pointer _ptr;
};

}