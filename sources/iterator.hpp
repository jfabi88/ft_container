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

template<class  T>
struct iterator_traits<const T*>{
	typedef T 									value_type;
  	typedef ptrdiff_t 							difference_type;
	typedef std::random_access_iterator_tag 	iterator_category;
  	typedef const T* 							pointer;
  	typedef const T& 							reference;
  	
};

// iterator
template<class Category, class T, class Distance = ptrdiff_t,class Pointer = T*, class Reference = T&>
struct iterator
{
	typedef T         value_type;
	typedef Distance  difference_type;
	typedef Category  iterator_category;
	typedef Pointer   pointer;
	typedef Reference reference;
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

template <class T>
class vector;

template <class Iter>
class b_iterator 
{
	public:
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iter>::value_type			value_type;
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::pointer				pointer;
		typedef typename iterator_traits<Iter>::reference			reference;

	private:
		pointer _ptr;
		b_iterator(pointer p) : _ptr(p){}
	public:
		pointer base() const	{return _ptr;}
		b_iterator() : _ptr(nullptr){};
		~b_iterator(){};

		template <class _Up>  
		b_iterator(const b_iterator<_Up>& __u) : _ptr(__u.base()){}

		reference   operator*() const   { return *_ptr; }
		pointer     operator->()        { return _ptr; }

		//prefix increment operator
		b_iterator&   operator++()        { ++_ptr; return *this; }
		//postfix increment operator
		b_iterator    operator++(int)     { b_iterator tmp = *this; ++_ptr; return tmp; }

		b_iterator&   operator--()        { --_ptr; return *this; }
		b_iterator    operator--(int)     { b_iterator tmp = *this; --_ptr; return tmp; }

		friend bool    operator== (const b_iterator &f, const b_iterator &s) { return (f._ptr == s._ptr); }
		friend bool    operator!= (const b_iterator &f, const b_iterator &s) { return (f._ptr != s._ptr); }
		bool    operator<(const b_iterator &s)    { return (_ptr < s._ptr); }
		bool    operator>(const b_iterator &s)    { return (_ptr > s._ptr); }
		bool    operator<=(const b_iterator &s)    { return (_ptr <= s._ptr); }
		bool    operator>=(const b_iterator &s)    { return (_ptr >= s._ptr); }

		b_iterator    operator+(difference_type n)    { b_iterator _w(*this); _w += n; return _w;}
		//{ return b_iterator(_ptr + n); } 
		
		b_iterator    operator-(difference_type n)   { return *this + (-n); }; 
		//{ return b_iterator(_ptr - n); }

		difference_type operator+(const b_iterator &s) const   { return (_ptr + s._ptr); }
		difference_type operator-(const b_iterator &s) const  { return (_ptr - s._ptr); }

		b_iterator    operator+=(difference_type n)   { _ptr += n; return (*this); }
		b_iterator    operator-=(difference_type n)   { _ptr -= n; return (*this); }

		value_type  operator[](difference_type n)  { return (_ptr + n); }

		b_iterator   &operator=(const b_iterator &s) { _ptr = s._ptr;  return (*this);}

		template <class T> friend class vector;
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