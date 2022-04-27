#include <iostream>
#include "structs.hpp"

namespace ft
{  
	template <class V>
	class vector;
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




/* template <class T>
class b_iterator {
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T               					value_type;
		typedef std::ptrdiff_t  					difference_type;
		typedef T*              					pointer;
		typedef T&              					reference;

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
		//operator const_b_iterator() { return const_b_iterator(_ptr); }
	private:
		pointer _ptr;
}; */

template <class T>
class b_iterator {
	public:

		typedef T                                                      		iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;
		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer			pointer;
		typedef typename iterator_traits<iterator_type>::reference			reference;

	private:
		iterator_type _ptr;
		b_iterator(iterator_type p) : _ptr(p){}
		iterator_type base() const	{return _ptr;}
	
	public:
		b_iterator() : _ptr(nullptr){};
		template <class U>
			b_iterator(b_iterator<U> const & s) : _ptr(s.base()) {}
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

		b_iterator   &operator=(const b_iterator &s) { _ptr = s._ptr;  return (*this);}


		template <class V> friend class vector;
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