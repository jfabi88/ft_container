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
			
		private:
			typedef Tree<value_type, key_compare> TreeType;

		public:
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
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef tree_iterator<typename TreeType::pointer, key_compare>   	iterator;
			typedef tree_iterator<typename TreeType::const_pointer, key_compare>   const_iterator;
			typedef std::ptrdiff_t			difference_type;
			typedef size_t					size_type;
		private:
			typedef typename Tree<value_type, key_compare>::NodeType NodeType;
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
			}

			iterator begin()
			{
				return iterator(_tree._begin);
			}

			const_iterator begin() const{
				return const_iterator(_tree._begin);
			}

			//single element
			pair<iterator,  bool> insert(const value_type& val)
			{
				NodeType *t = _tree.Search(_tree.getRoot(), val.first);

				if (!_tree.end(t))
				{
					return ft::make_pair<iterator,  bool>(iterator(t), false);
				}
				t = _tree.insert(val);
				return ft::make_pair<iterator, bool>(iterator(t), true);
			}
	};
}

ft::map<std::string, int> m;