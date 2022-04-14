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
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference    const_reference;

            typedef b_iterator<T>               iterator;
            typedef b_iterator<const T>         const_iterator;

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

            size_type size() const //ritorna il numero di elementi
            {
                return (this->_size);
            }

            size_type max_size() const //ritorna il numero massimo di elementi che puoi allocare
            {
                if (sizeof(value_type) == 1)
                    return (_allocator.max_size() / 2);
                return (_allocator.max_size());
                //return std::numeric_limits<size_type>::max() / sizeof(value_type);
            }

            void resize(size_type n, value_type val = value_type()) //ridimensiona la size in base ad n ed incide sulla capacity
            {
                if (n <= this->_size) //se n è < di size, la size, e di conseguenza la capacity, devono diminuire prendendo il valore di n
                {
                    size_type tmp = _size;
                    for (; _size != n; _size--)
                        _allocator.destroy(_container + _size);
                    _allocator.deallocate(_container, n - tmp);
                    _capacity = _size;
                }
                else //se n > size dall'ultimo size fino a n riempio con lo stesso val passato
                {
                    if (n > _capacity) //questo caso è da sistemare, ma se n > capacity bisogna riallocare capacity in base ad n e ricostruire
                    {
                        this->_capacity = n;
                        value_type* ptr = _allocator.allocate(_capacity + 1);
                        for (size_type i = 0; i < _size; i++)
                        {
                            _allocator.construct(ptr, this->at(i));
                            ptr++;
                        }
                        for (; _size <= n; _size++)
                            _allocator.construct(ptr++, val); //NON FUNZIONA QUESTA RIGA DI CODICE
                    }
                    else // se n > size ma c'è capacity, aggiungo size e val e basta
                    {
                        for (; _size < n; _size++)
                            this->at(_size) = val;
                    }
                }
            }

            size_type capacity() const //ritorna la capacity
            {
                return (this->_capacity);
            }

            bool empty() const
            {
                return (this->_size == 0);  //_size == 0 ? true : false
            }

            void reserve (size_type n) //rialloca capacity = n
            {
                this->_capacity = n;
                value_type* ptr = _allocator.allocate(_capacity + 1);
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
                if (this->_size == this->_capacity && _size)
                {
                    this->_capacity = this->_size * 2;
                    value_type* ptr = _allocator.allocate(_capacity + 1);
                    for (size_type i = 0; i < _size; i++)
                    {
                        _allocator.construct(ptr, this->at(i));
                        std::cout << "ptr :"<< ptr << std::endl;
                        ptr++;
                    }
                    std::cout << "val: " << val << std::endl;
                    std::cout << "ptr :"<< ptr << std::endl;
                    _allocator.construct(ptr, val);
                    this->_size++;
                }
                /* else
                {
                    _allocator.construct(this.at()
                } */
            }
    };
}
