#include <iostream>
#include "structs.hpp"
#include "iterator.hpp"

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
                for (int i = 0; i < _size; i++)
                    std::cout << _container[i] << std::endl;
                std::cout << "Default destructor called" << std::endl;
            }

            iterator begin()    { return (iterator(&_container[0])); }
            iterator end()      { return (iterator(&_container[_size])); }
            const_iterator begin() const    { return (const_iterator(&_container[0])); }
            const_iterator end() const      { return (const_iterator(&_container[_size])); }

            /* Capacity */

            size_type size() const
            {
                return (this->_size);
            }

            size_type max_size() const
            {

            }

            size_type capacity() const
            {
                return (this->_capacity);
            }

            bool empty() const 
            {
                return (this->_size == 0);  //_size == 0 ? true : false
            }

            void reserve (size_type n)
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
                        ptr++;
                    }
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
