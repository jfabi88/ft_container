#include <iostream>
#include "structs.hpp"
#include "iterator.hpp"
#include <filesystem>
#include <cstdint>

namespace ft
{   
    template <class T>
    class vector
    {
        public:
            typedef T                           value_type;
            typedef size_t                      size_type;
            typedef std::ptrdiff_t              difference_type;
            typedef std::allocator<value_type>  allocator_type;
            typedef T*  pointer;
            typedef T&  reference;
            typedef const T&    const_reference;

            typedef b_iterator<T>   iterator;
            typedef b_iterator<T>   const_iterator;

        private:
            allocator_type  _allocator;  
            value_type*     _container;
            size_type       _size;
            size_type       _capacity;
        public:
            vector(const allocator_type& alloc = allocator_type())
            {
                _allocator = alloc;
                _size = 0;
                _capacity = 0;
                std::cout << "Default constructor called" << std::endl;
            }
            vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            {
                _allocator = alloc;
                _container = _allocator.allocate(n + 1);
                _size = n;
                _capacity = _size;
                for (size_t i = 0; i < _size; i++)
                    _allocator.construct(_container + i, val);
                std::cout << "Fill constructor called" << std::endl;
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
                std::cout << "Range constructor called" << std::endl;
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
                std::cout << "Copy constructor called" << std::endl;
            }
            ~vector()
            {
               /*  for (int i = 0; i < _size; i++)
                    std::cout << _container[i] << std::endl;  */
                std::cout << "Default destructor called" << std::endl;
            }

            iterator begin()    { return (iterator(&_container[0])); }
            iterator end()      { return (iterator(&_container[_size])); }
            const_iterator begin() const    { return (const_iterator(&_container[0])); }
            const_iterator end() const      { return (const_iterator(&_container[_size])); }

            /* CAPACITY */

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
                if (n < _size) //se n è < di size, la size deve diminuire prendendo il valore di n mentre la capacity rimane uguale
                {
                    for (size_type i = 0; i + n < _size; i++)
                        _allocator.destroy(_container + (i + n));
                    _size = n;
                }
                else //se n > size dall'ultimo size fino a n riempio con lo stesso val passato
                {
                    if (n > _capacity) //se n > capacity bisogna riallocare capacity in base ad n e ricostruire
                    {
                        allocator_ref   tmp = copy_allocator(_size, n, *this, val);
                        this->destroy_allocator(_allocator, _size, _capacity, _container);
                        _container = tmp.ptr;
                        _allocator = tmp.all;
                        _size = n;
                        _capacity = n;
                    }
                    else // se n > size ma c'è capacity, aggiungo size e val e basta
                    {
                        for (size_type i = _size; i < n; i++)
                            this->at(i) = val;
                        _size = n;
                    }
                }
            }

            size_type capacity() const { return (this->_capacity); }

            bool empty() const { return (this->_size == 0); }

            void reserve (size_type n) //rialloca capacity = n
            {
                if (n > _capacity)
                {
                    allocator_ref   tmp = copy_allocator(_size, n, *this, 0);
                    //this->destroy_allocator(_allocator, _size, _capacity, _container);
                    //_container = tmp.ptr;
                    //_allocator = tmp.all;
                    _capacity = n;
                }
            }

            /* Element access */

            reference at(size_type n)
            {
                reference ref = *(_container + n);
                return (ref);
            }
            
            const_reference at (size_type n) const
            {
                const_reference const_ref = *(_container + n);
                return (const_ref);
            }

            /* Modifiers */

            void push_back(const value_type& val)
            {
                if (_size == _capacity && _size)
                {
                    allocator_ref   tmp = copy_allocator(_size, _size * 2, this, NULL);
                    this->destroy_allocator(_allocator, _size, _capacity, _container);
                    _container = tmp.ptr;
                    _allocator = tmp.all;
                    _allocator.construct(_container + _size, val);
                    _size = _size + 1;
                    _capacity = _size * 2;
                }
                else
                {
                    _allocator.construct(_container + _size, val);
                    _size += 1;
                }
            }
        private:
            void destroy_allocator(allocator_type alloc, size_type sz, size_type capacity, value_type * addr)
            {
                for (size_type i = 0; i < sz; i++)
                    alloc.destroy(addr + i);
                alloc.deallocate(addr, capacity + 1);
            }
            struct allocator_ref
            {
                allocator_type  all;
                value_type*     ptr;
            };

            allocator_ref   copy_allocator(size_type sz, size_type capacity, vector vec, value_type val)
            {
                allocator_ref   ret;
                allocator_type  newalloc = allocator_type();
                value_type*     newptr = newalloc.allocate(capacity + 1);

                for (size_type i = 0; i < sz; i++)
                    newalloc.construct(newptr + i, vec.at(i));
                if (val != 0)
                {
                    for (size_type i = _size; i < capacity; i++)
                        newalloc.construct(newptr + i, val);
                }
                ret.all = newalloc;
                ret.ptr = newptr;
                return (ret);
            }
    };
}
