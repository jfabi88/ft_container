#include <iostream>

namespace ft
{
    template <class T>
    class vector
    {
        public:
            typedef T value_type;
            typedef std::allocator<value_type> allocator_type;
            typedef size_t size_type;
        private:
            allocator_type  _allocator;
            value_type*     _container;
            size_type       _size;
        public:
            vector(const allocator_type& alloc = allocator_type())
            {
                _allocator = alloc;
                _size = 0;
                std::cout << "Default constructor called" << std::endl;
            }
            vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            {
                _allocator = alloc;
                _container = _allocator.allocate(n);
                _size = n;
                for (size_t i = 0; i < _size; i++)
                    _allocator.construct(_container + i, val);
                std::cout << "Fill constructor called" << std::endl;
            }
            template <class InputIterator>
            vector(InputIterator first, InputIterator second, const allocator_type& alloc = allocator_type())
            {
                int dist;

                if ( (dist = second - first) < 0)
                    throw (std::length_error("vector"));
                _allocator = alloc;
                _container = _allocator.allocate(dist);
                _size = dist;
                //for (size_t i = 0; i < _size; i++)
                //    _allocator.construct(_container + i, (first + i));
/*                 for(InputIterator i = first; i != second; i++){
                    _allocator.construct(_container + i, *i);
                } */
                std::cout << "Range constructor called" << std::endl;
            }
            ~vector()
            {
                for (int i = 0; i < _size; i++)
                    std::cout << _container[i] << std::endl;
                std::cout << "Default destructor called" << std::endl;
            }
    };
}