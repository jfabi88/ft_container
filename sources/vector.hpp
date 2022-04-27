#include <iostream>
#include "structs.hpp"
#include "iterator.hpp"
#include <filesystem>
#include <cstdint>
#include <sstream>

namespace ft
{   
	template <class T>
	class vector
	{
		public:
			typedef T                           				value_type;
			typedef std::allocator<value_type>  				allocator_type;
			typedef typename allocator_type::reference  		reference;			// equivalente a T& (Jacopo non cambiare)
			typedef typename allocator_type::const_reference	const_reference;	// equivalente a const T& (Jacopo non cambiare)
			typedef typename allocator_type::pointer  			pointer;			//T*
			typedef typename allocator_type::const_pointer  	const_pointer;		//const T*
			typedef b_iterator<pointer>   						iterator;
			typedef b_iterator<const_pointer>   				const_iterator;
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
				//std::cout << "Default constructor called" << std::endl;
			}
			vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_allocator = alloc;
				_container = _allocator.allocate(n + 1);
				_size = n;
				_capacity = _size;
				for (size_t i = 0; i < _size; i++)
					_allocator.construct(_container + i, val);
				//std::cout << "Fill constructor called" << std::endl;
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator second, const allocator_type& alloc = allocator_type(),  typename enable_if<!is_integral<InputIterator>::value && is_iterator<InputIterator>::value, InputIterator>::type* = 0)
			{
				int dist;
				typename InputIterator::difference_type next;

				if ( (dist = second - first) < 0)
					throw (std::length_error("vector"));
				_allocator = alloc;
				_container = _allocator.allocate(dist + 1);
				_size = dist;
				next = 0;
				for (InputIterator i = first; i != second; i++){
					_allocator.construct(_container + next, *i);
					next++;
				} 
				//std::cout << "Range constructor called" << std::endl;
			}
			vector (const vector &x)
			{
				typename vector::difference_type next;

				_allocator = x._allocator;
				_size = x._size;
				_container = _allocator.allocate(_size);
				next = 0;
				for (vector::const_iterator it = x.begin(); it < x.end(); it++)
				{
					_allocator.construct(_container + next, *it);
					next++;
				}
				//std::cout << "Copy constructor called" << std::endl;
			}
			~vector()
			{
			   /*  for (int i = 0; i < _size; i++)
					std::cout << _container[i] << std::endl;  */
				//std::cout << "Default destructor called" << std::endl;
			}

/* 			iterator begin()    { return (iterator(&_container[0])); } */
			iterator begin()    { return iterator(_container); }
			iterator end()      { return (iterator(&_container[_size])); }
			const_iterator begin() const    { return (const_iterator(&_container[0])); }
			const_iterator end() const      { return (const_iterator(&_container[_size])); }

/* ------------------------------- PRIVATE UTILS FUNCTIONS ------------------------------- */
		private:
			void	destroy_allocator(allocator_type alloc, size_type sz, size_type capacity, value_type * addr)
			{
				for (size_type i = 0; i < sz; i++)
					alloc.destroy(addr + i);
				if (capacity)
					alloc.deallocate(addr, capacity + 1);
			}

			struct allocator_ref
			{
				allocator_type  all;
				value_type*     ptr;
			};

			allocator_ref	copy_allocator(size_type sz, size_type capacity, vector vec)
			{
				allocator_ref   ret;
				allocator_type  newalloc = allocator_type();
				value_type*     newptr = newalloc.allocate(capacity + 1);

				for (size_type i = 0; i < sz; i++)
					newalloc.construct(newptr + i, vec.at(i));
				ret.all = newalloc;
				ret.ptr = newptr;
				return (ret);
			}

			void copy_allocator(iterator position, size_type NewCapacity, vector vec)
			{
				allocator_ref   ret;
				allocator_type  newalloc = allocator_type();
				value_type*     newptr;

				if (NewCapacity > capacity())
				{
					newptr = newalloc.allocate(NewCapacity + 1);
					size_type i = 0;
					for (iterator pt = begin(); pt < position; pt++){
						newalloc.construct(newptr + i, *pt);
						i++;
					}
					this->destroy_allocator(_allocator, _size, _capacity, _container);
					_container = newptr;
					_allocator = newalloc;
					_capacity = NewCapacity;
				}
			}

			std::string myOutOfRange(size_type n) const
			{
				std::stringstream sstm;
				sstm << "vector::_M_range_check: __n (which is " << n << ") this->size() (which is " << _size << ")" << std::endl;
				return sstm.str();
			}

			size_type _Calculate_growth(const size_type _Newsize) const
			{
				// given _Oldcapacity and _Newsize, calculate geometric growth
				const size_type _Oldcapacity = capacity();
				

				//if (_Oldcapacity > max_size() - _Oldcapacity / 2)
				if (_Oldcapacity + (_Oldcapacity / 2) > max_size() )
				{
					return (_Newsize);	// geometric growth would overflow
				}

				const size_type _Geometric = _Oldcapacity + _Oldcapacity / 2;

				if (_Geometric < _Newsize)
				{
					return (_Newsize);	// geometric growth would be insufficient
				}

				return (_Geometric);	// geometric growth is sufficient
/* 				if (_Oldcapacity * 2 > max_size() )
				{
					return (_Newsize);	// geometric growth would overflow
				}

				return _Oldcapacity * 2; */
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
					for (size_type i = _size; i < n; i++)
						this->push_back(val);
				}
			}

			size_type capacity() const { return (this->_capacity); }

			bool empty() const { return (this->_size == 0); }

			void reserve (size_type n) //rialloca capacity contenere n elementi
			{
				if (n > this->max_size())
					throw (std::length_error("vector max_size"));
				if (n > _capacity)
				{
					allocator_ref   tmp = copy_allocator(_size, n, *this);
					this->destroy_allocator(_allocator, _size, _capacity, _container);
					_container = tmp.ptr;
					_allocator = tmp.all;
					_capacity = n;
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

			void push_back(const value_type& val)
			{
				if (_size == _capacity)
				{
					//size_type newCapacity = _capacity ? _capacity * 2 : 1;
					size_type newCapacity = _Calculate_growth(_size+1);
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

			void insert(iterator position, size_type n, const value_type& val)
			{
				size_type newSize = _size + n;
				size_type rightN = end() - position;
				int pIndex = position - begin();

				//alloco capacity e ricopio i valori a sinistra di position
				if (newSize > _capacity)
				{
					//size_type newCapacity = _capacity ? _capacity * 2 : 1;
					size_type newCapacity = _Calculate_growth(newSize);
					copy_allocator(position, newCapacity, *this);
				}

				//copio position e i valori alla sua destra traslandoli di n posizioni 
				for ( size_type i = 0 ; i <= rightN; i++){
					_allocator.construct(_container + newSize -i, *(position +rightN -i));
				}

				//inerisco i nuovo valori
				for (size_type i = 0 ; i < n; i++){
					_allocator.construct(_container + pIndex + i, val);
				}

				_size = newSize;
			}

			iterator insert(iterator position, const value_type& val)
			{
				insert(position, 1, val);
				return position;
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,  typename enable_if<!is_integral<InputIterator>::value && is_iterator<InputIterator>::value, InputIterator>::type* = 0){
				while (first != last){
					insert(position++, 1, *first);
					first++;
				}
			}

			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_container + i);
				_size = 0;
			}
	};
}
