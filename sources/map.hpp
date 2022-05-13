#pragma once
#include <iostream>
#include "pair.hpp"
#include "tree.hpp"
#include  "iterator.hpp"

namespace ft
{   
	template < class Key,                                    	 // map::key_type
		class T,                                       			// map::mapped_type
		class Compare = std::less<Key>,                     	// map::key_compare
		class Alloc = std::allocator< pair< const Key, T > >    // map::allocator_type
	>
	class map
	{
		public:
			typedef Key						key_type;
			typedef T						mapped_type;
			typedef pair<const Key, T>		value_type;
			typedef Compare					key_compare;
			
			class value_compare : std::binary_function<value_type, value_type, bool> {
				friend class map;
				protected:
					key_compare comp;
					value_compare(key_compare c) : comp(c) {};
				public:
					typedef bool result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};	
			typedef Alloc					allocator_type;
			typedef typename Alloc::reference		reference;
			typedef typename Alloc::const_reference	const_reference;
			typedef typename Alloc::pointer			pointer;
			typedef typename Alloc::const_pointer	const_pointer;
			typedef typename ft::tree_iterator<value_type, key_compare>			iterator;
			//typedef map_iterator			const_iterator;
			//typedef map_reverse_iterator	reverse_iterator;
			//typedef map_reverse_iterator	const_reverse_iterator;
			typedef std::ptrdiff_t			difference_type;
			typedef size_t					size_type;
		private:
			allocator_type  _allocator;
			pointer     	_container;
			size_type       _size;
			key_compare		_comp;
			ft::Tree<value_type, key_compare>	_tree;
		public:
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_size = 0;
				_comp = comp;
				_allocator = alloc;
				_tree = Tree<value_type, key_compare>();
			}
	};
}

ft::map<std::string, int> m;