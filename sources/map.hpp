#pragma once
#include <iostream>
#include "pair.hpp"
#include "tree.hpp"
#include  "iterator.hpp"

#include "string.h"

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
					return ft::make_pair<iterator,  bool>(iterator(t), false);

				t = _tree.insert(t->parent, val);
				return ft::make_pair<iterator, bool>(iterator(t), true);
			}

			//with hint
			iterator insert(iterator position, const value_type& val)
			{
				NodeType *t = _tree.Search(_tree.getRoot(), val.first);
				
				//se non esiste un elemento con la stessa chiave
				if (t->end)
				{
					if (_comp(position._ptr->first, val.first)){
						NodeType *next = _tree.Next(position._ptr);
						
						//se sono l'elemento successivo a quello in position
						if (next->end || _comp(val.first, next->first)){
							t = _tree.insert(position._ptr, val);
							return iterator(t);	
						}
					}
					t = _tree.insert(_tree.getRoot(), val);
				}
				
				return iterator(t);				
			}

			//range
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last,  typename enable_if<!is_integral<InputIterator>::value && is_iterator<InputIterator>::value, InputIterator>::type* = 0)
			{

				for (InputIterator i = first; i != last; i++){
					insert(const value_type& val)
					_allocator.construct(_container + next, *i);
					next++;
				} 

			}

			key_compare key_comp() const
			{
				return key_compare();
			}

			value_compare value_comp() const
			{
				return value_compare(key_comp());
			}



	};
}

ft::map<std::string, int> m;