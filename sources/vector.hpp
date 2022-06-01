#pragma once
#include <iostream>
#include "structs.hpp"
#include "iterator.hpp"
#include <filesystem>
#include <cstdint>
#include <sstream>
#include "utils.hpp"

namespace ft
{   
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T                           				value_type;
			typedef Alloc  										allocator_type;
			typedef typename allocator_type::reference  		reference;			// equivalente a T& (Jacopo non cambiare)
			typedef typename allocator_type::const_reference	const_reference;	// equivalente a const T& (Jacopo non cambiare)
			typedef typename allocator_type::pointer  			pointer;			//T*
			typedef typename allocator_type::const_pointer  	const_pointer;		//const T*
			typedef b_iterator<pointer>   						iterator;
			typedef b_iterator<const_pointer>   				const_iterator;
			typedef b_reverse_iterator<iterator>             	reverse_iterator;
            typedef b_reverse_iterator<const_iterator>          const_reverse_iterator;
			typedef size_t                      				size_type;
			typedef std::ptrdiff_t              				difference_type;


		private:
			allocator_type  _allocator;
			pointer     	_container;
			size_type       _size;
			size_type       _capacity;

		public:
			vector(const allocator_type& alloc = allocator_type())
			{
				_allocator = alloc;
				_size = 0;
				_capacity = 0;
				_container = nullptr;
				//std::cout << "Default constructor called" << std::endl;
			}
			vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				if (n > this->max_size()){
					throw std::length_error("vector");
				}
					
				_allocator = alloc;
				_size = n;
				_capacity = _size;
				_container = _capacity ? _allocator.allocate(_capacity + 1) : nullptr;

				for (size_t i = 0; i < _size; i++)
					_allocator.construct(_container + i, val);
				//std::cout << "Vector Fill constructor called" << std::endl;
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator second, const allocator_type& alloc = allocator_type(),  typename enable_if<!is_integral<InputIterator>::value && is_iterator<InputIterator>::value, InputIterator>::type* = 0)
			{
				int dist;
				typename InputIterator::difference_type next;

				if ( (dist = second - first) < 0)
					throw (std::length_error("vector"));
				_allocator = alloc;
				_size = dist;
				_capacity = _size;
				_container = _capacity ? _allocator.allocate(_capacity + 1) : nullptr;
				next = 0;
				for (InputIterator i = first; i != second; i++){
					_allocator.construct(_container + next, *i);
					next++;
				} 
				//std::cout << "Vector Range constructor called" << std::endl;
			}
			vector (const vector &x)
			{
				typename vector::difference_type next;

				_allocator = x._allocator;
				_size = x._size;
				_capacity = x._size;
				_container = _capacity ? _allocator.allocate(_capacity + 1) : nullptr;
				next = 0;
				for (vector::const_iterator it = x.begin(); it < x.end(); it++)
				{
					_allocator.construct(_container + next, *it);
					next++;
				}
				//std::cout << "Vector Copy constructor called(" << _capacity << ")"<< std::endl;
			}

			vector& operator= (const vector& x)
            {
                allocator_ref   ref = copy_allocator(x.size(), x.capacity(), x);
				updateStatus(ref, x.size(), x.capacity());
                return (*this);
            }

			~vector() {
				destroy_allocator();
			}

			iterator begin()    { return iterator(_container); }
			iterator end()      
			//{ return (iterator(&_container[_size])); }
			{ return iterator(_container + _size); }

			const_iterator begin() const    { return (const_iterator(&_container[0])); }
			const_iterator end() const      { return (const_iterator(&_container[_size])); }

			reverse_iterator rbegin()    { return reverse_iterator(end()); }
            reverse_iterator rend()     { return reverse_iterator(begin()); }
            const_reverse_iterator rbegin() const   { return const_reverse_iterator(end()); }
            const_reverse_iterator rend() const     { return const_reverse_iterator(begin()); }

/* ------------------------------- PRIVATE UTILS FUNCTIONS ------------------------------- */
		private:
			struct allocator_ref
			{
				allocator_type  newAlloc;
				value_type*     newPtr;
				allocator_ref(){
					newPtr = nullptr;
				}
			};

			allocator_ref __reserve(size_type capacity){
				allocator_ref   ret;
				ret.newAlloc = allocator_type();
				ret.newPtr = ret.newAlloc.allocate(capacity + 1);
				return (ret);
			}

			void	destroy_allocator(allocator_type alloc, size_type sz, size_type capacity, value_type * addr)
			{
				for (size_type i = 0; i < sz; i++)
					alloc.destroy(addr + i);
				if (capacity > 0)
					alloc.deallocate(addr, capacity + 1);
			}

			void	destroy_allocator()
			{
				destroy_allocator(_allocator, _size, _capacity, _container);
			}

			void updateStatus(allocator_ref &ref, size_type newSize, size_type newCapacity, bool _mDelete = true)
			{
				if(_mDelete)
					this->destroy_allocator();
				_size = newSize;
				_container = ref.newPtr;
				_allocator = ref.newAlloc;
				_capacity = newCapacity;
			}
	
			allocator_ref	copy_allocator(size_type sz, size_type NewCapacity, const vector &vec)
			{
				allocator_ref   ret;

				ret.newAlloc = allocator_type();
				ret.newPtr = ret.newAlloc.allocate(NewCapacity + 1);

				for (size_type i = 0; i < sz; i++){
					ret.newAlloc.construct(ret.newPtr + i, vec.at(i));
				}

				return ret;
			}

			allocator_ref copy_allocator(iterator position, size_type NewCapacity,const vector &vec)
			{
				difference_type	d = position - begin();
				return copy_allocator(d, NewCapacity, vec);
			}


			std::string myOutOfRange(size_type n) const
			{
				std::stringstream sstm;
				sstm << "vector::_M_range_check: __n (which is " << n << ") this->size() (which is " << _size << ")" << std::endl;
				return sstm.str();
			}

			size_type _Calculate_capacity(const size_type _Newsize) const
			{
				const size_type _Oldcapacity = capacity();
				
				//size_type NewCapacity = _Oldcapacity + _Oldcapacity / 2;
				size_type NewCapacity = _Oldcapacity * 2;

				if (NewCapacity < _Newsize || NewCapacity > max_size() )
				{
					return (_Newsize);	
				}

				return (NewCapacity);	// geometric growth is sufficient
			}

/* ------------------------------- CAPACITY ------------------------------- */
	public:
			size_type size() const { return (this->_size); }

			size_type max_size() const //ritorna il numero massimo di elementi che puoi allocare
			{
				if (sizeof(value_type) == 1)
					return (_allocator.max_size() / 2);
				return (_allocator.max_size());
				//return std::numeric_limits<size_type>::max() / sizeof(value_type);
			}

			void resize(size_type n, value_type val = value_type()) //ridimensiona la size in base ad n ed incide sulla capacity
			{
				if (n < _size) //se n < size, la size deve diminuire prendendo il valore di n mentre la capacity rimane uguale
				{
					for (size_type i = n; i < _size; i++)
						_allocator.destroy(_container + i);
					_size = n;
				}
				else //se n > size dall'ultimo size fino a n riempio con lo stesso val passato
				{
					if (n > _capacity)
						reserve(_Calculate_capacity(n));
					for (size_type i = _size; i < n; i++)
						this->push_back(val);
				}
			}

			size_type capacity() const { return (this->_capacity); }

			bool empty() const { return (this->_size == 0); }

			void reserve (size_type n) //rialloca capacity contenere n elementi
			{
				allocator_ref ref;
				if (n > this->max_size())
					throw (std::length_error("vector max_size"));
				if (n > _capacity){
					ref = copy_allocator(_size, n, *this);
					updateStatus(ref, _size, n);
				}
			}

/* ------------------------------- ELEMENT ACCESS ------------------------------- */


			reference operator[] (size_type n)  // Returns a reference to the element at position n in the vector container.
			{
				reference ref = *(_container + n);
				return (ref);
			}

			const_reference operator[] (size_type n) const
			{
				const_reference const_ref = *(_container + n);
				return (const_ref);
			}

			reference at(size_type n)
			{
				if (n >= _size)
					throw std::out_of_range(myOutOfRange(n));
				reference ref = *(_container + n);
				return (ref);
			}
			
			const_reference at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range(myOutOfRange(n));
				const_reference const_ref = *(_container + n);
				return (const_ref);
			}

			reference front()
			{
				reference ref = _container[0];
				return ref;
			}
			
			const_reference front() const
			{
				const_reference ref = _container[0];
				return ref;
			}

			reference back()
			{
				reference ref = _container[_size - 1];
				return ref;
			}
			
			const_reference back() const
			{
				const_reference ref = _container[_size - 1];
				return ref;
			}

			/* Modifiers */

			void assign (size_type n, const value_type& val) //fill assign
			{
				clear();
				insert(begin(), n, val);
			}

			template <class InputIterator> //riassegna da first a last - 1, quindi last non viene considerato
  			void assign(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value && is_iterator<InputIterator>::value, InputIterator>::type* = 0)
			{
				clear();
				iterator it = begin();
				insert(it, first, last);
			}

			void push_back(const value_type& val)
			{
				if (_size == _capacity)
				{
					//size_type newCapacity = _capacity ? _capacity * 2 : 1;
					size_type newCapacity = _Calculate_capacity(_size + 1);
					reserve(newCapacity);
					_capacity = newCapacity;
				}
				_allocator.construct(_container + _size, val);
				_size++;
			}

			void pop_back()
			{
				//if (_size){
					_allocator.destroy(_container + _size-- - 1);
				//}
			}

			//insert fill
			void insert(iterator position, size_type n, const value_type& val)
			{
				if (n){
					allocator_ref 	ref;
					size_type		newSize = _size + n;
					size_type 		newCapacity = _capacity;
					bool			_mDelete = false;
					//numero di elementi da traslare verso destra di n posizioni
					size_type	toRight = end() - position;
					int 		pIndex = position - begin();
					ref.newAlloc = _allocator;
					ref.newPtr = _container;

					//alloco capacity e aggiorno position
					if (newSize > _capacity)
					{
						newCapacity = _Calculate_capacity(newSize);
						ref = copy_allocator(_size, newCapacity, *this);
						_mDelete = true;
					//  position = begin() + pIndex;
					}

					iterator newPosition(ref.newPtr + pIndex);
					newPosition += toRight;
					//copio position e i valori alla sua destra traslandoli di n posizioni 
					for (size_type i = 0 ; i < toRight; i++){
						--newPosition;
						_allocator.construct(ref.newPtr + newSize -i -1, *(newPosition));
					}

					//inerisco i nuovo valori
					for (size_type i = 0 ; i < n; i++){
						_allocator.construct(ref.newPtr + pIndex + i, val);
					}
					updateStatus(ref, newSize, newCapacity, _mDelete);
				}
			}

			// insert single element
			iterator insert(iterator position, const value_type& val)
			{
				difference_type	d = position - begin();
				insert(position, 1, val);
				return (begin() + d);
			}

			//insert range
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,  typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0){
				size_type	n = last - first;
				if (n){
					bool 			_mDelete = false;
					allocator_ref 	ref;
					size_type		newSize = _size + n;
					size_type 		newCapacity = _capacity;
					
					//numero di elementi da traslare verso destra di n posizioni
					size_type	toRight = end() - position;
					int 		pIndex = position - begin();
					ref.newAlloc = _allocator;
					ref.newPtr = _container;

					//alloco capacity e aggiorno position
					if (newSize > _capacity)
					{
						newCapacity = _Calculate_capacity(newSize);
						ref = copy_allocator(_size, newCapacity, *this);
						_mDelete = true;
					}

					iterator newPosition(ref.newPtr + pIndex);
					newPosition += toRight;
					//copio position e i valori alla sua destra traslandoli di n posizioni
					try {
						for (size_type i = 0 ; i < toRight; i++){
							--newPosition;
							_allocator.construct(ref.newPtr + newSize -i -1, *(newPosition));
						}

						//inerisco i nuovo valori
						for (size_type i = 0 ; i < n; i++){
							_allocator.construct(ref.newPtr + pIndex + i, *(first));
							first++;
						}
						updateStatus(ref, newSize, newCapacity, _mDelete);
					}
					catch (const char *e) { destroy_allocator(ref.newAlloc, newSize, newCapacity, ref.newPtr); throw e;}
				}				
			}

			iterator erase(iterator first, iterator last)
			{
				//numero elementi da eliminare
				size_type n = last - first;
				//left = indice primo elemento da eliminare
				size_type left = first - begin();
				//right = indice ultimo elemento da eliminare
				size_type	right = left + n - 1;

				size_type  i = right;
				while (i >= left && i != 0){
					_allocator.destroy(_container + i--);
				}
				if (left == 0)
					_allocator.destroy(_container + i--);
				_size -= n;
				for (i = i+1; i < _size; i++){
					_container[i] = _container[i + n];
				}
				_size = i;
				return (first);
			}

			iterator erase (iterator position)
			{
				//return erase(position, position + 1);
				//indice elemento da eliminare
				size_type i = position - begin();

				_allocator.destroy(_container + i);
				_size -= 1;
				for (; i < _size; i++){
					_container[i] = _container[i + 1];
				}
				return (position);
			}

			void swap (vector& x)
			{
				ft::swap(this->_allocator, x._allocator);
				ft::swap(this->_capacity, x._capacity);
				ft::swap(this->_size, x._size);
				ft::swap(this->_container, x._container);
			}

			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_container + i);
				_size = 0;
			}

/* ------------------------------- OPERATORS------------------------------- */

			bool operator==( const vector& rhs) const
			{
				if (this->size() != rhs.size())
					return (false);
				const_iterator lit = this->begin();
				const_iterator rit = rhs.begin();
				for (; lit < this->end(); lit++)
				{
					if (*lit != *rit)
						return (false);
					rit++;
				}
				return (true);
			}

			bool operator!=( const vector& rhs) const
			{
				if (this->size() != rhs.size())
					return (true);
				const_iterator lit = this->begin();
				const_iterator rit = rhs.begin();
				for (; lit < this->end(); lit++)
				{
					if (*lit == *rit)
						return (false);
					rit++;
				}
				return (true);
			}

			bool operator<( const vector& rhs) const
			{
				return (ft::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end()));
			}

			bool operator<=( const vector& rhs) const
			{
				return (!ft::lexicographical_compare(rhs.begin(), rhs.end(), this->begin(), this->end()));
			}

			bool operator>( const vector& rhs) const
			{
				return (ft::lexicographical_compare(rhs.begin(), rhs.end(), this->begin(), this->end()));
			}

			bool operator>=( const vector& rhs) const
			{
				return (!ft::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end()));
			}
	};
}

namespace std
{
	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	};
}