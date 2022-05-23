#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "tree.hpp"
#include  "iterator.hpp"
#include  "utils.hpp"

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
			typedef tree_iterator< pointer, key_compare>   				iterator;
			typedef tree_iterator< const_pointer, key_compare>			const_iterator;
			typedef reverse_tree_iterator< pointer, key_compare>   				reverse_iterator;
			typedef reverse_tree_iterator< const_pointer, key_compare>			const_reverse_iterator;
			typedef std::ptrdiff_t										difference_type;
			typedef size_t												size_type;
			typedef Node<value_type> 						map_node;
			typedef typename Alloc::template rebind<map_node>::other	alloc_node; 	/* https://stackoverflow.com/questions/14148756/what-does-template-rebind-do */
		private:
			typedef typename Tree<value_type, key_compare>::NodeType NodeType;
			allocator_type  _allocator;
			pointer     	_container;
			size_type       _size;
			key_compare		_comp;
			alloc_node		_alloc;
		public:
			ft::Tree<value_type, key_compare>	_tree;

			//empty constructor
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_size = 0;
				_comp = comp;
				_allocator = alloc;
			}

			//range constructor
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
			{
				this->_size = 0;
				this->_comp = comp;
				this->_allocator = alloc;
				insert(first, last);
			}

			//copy constructor
			map (const map& x)
			{
				this->_size = 0;
				this->_comp = x._comp;
				this->_allocator = x._allocator;
				insert(x.begin(), x.end());
			}

			map& operator= (const map& x)
			{
				this->_size = 0;
				this->_comp = x._comp;
				this->_tree.clear(this->_tree.getRoot());
				this->insert(x.begin(), x.end());
				return (*this);
			}

			mapped_type& operator[] (const key_type& k)
			{
				return (*( ( this->insert(make_pair(k, mapped_type())) ).first ) ).second;
			}
/* ------------------------------- CAPACITY ------------------------------- */

			size_type size() const { return this->_tree.size(); }

			bool empty() const { return (this->_tree.size() == 0); }

			size_type max_size() const {
				return (_alloc.max_size());
			}

			iterator begin(){
				return iterator(_tree._begin);
			}

			const_iterator begin() const{
				return const_iterator(_tree._begin);
			}

			reverse_iterator rbegin(){
				return reverse_iterator(_tree._end);
			}

			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(_tree._end);
			}

			iterator end(){
				return iterator(_tree._end);
			}

			const_iterator end() const{
				return const_iterator(_tree._end);
			}

			reverse_iterator rend(){
				return reverse_iterator(_tree._begin);
			}

			const_reverse_iterator rend() const{
				return const_reverse_iterator(_tree._begin);
			}


			//single element
			pair<iterator,  bool> insert(const value_type& val)
			{
				NodeType * last;
				NodeType *t = _tree.Search(_tree.getRoot(), val.first, last);

				if (!t->end)
					return ft::make_pair<iterator,  bool>(iterator(t), false);
				//last punta al' ultimo nodo confrontato da Search
				//t = _tree.insert(last, val);
				t = _tree.insert(_tree.getRoot(), val);
				return ft::make_pair<iterator, bool>(iterator(t), true);
			}

			//with hint
			iterator insert(iterator position, const value_type& val)
			{
				NodeType *t, *last;
				
				//se il nuovo elemento >= di quello in position
				if (_comp(position._ptr->_value.first, val.first)){
					NodeType *next = _tree.Next(position._ptr);
					//NodeType *next = _tree._end;
					//se il nuovo elemento è l'elemento successivo a quello in position
					//if (next->end || _comp(val.first, next->getFirst())){
					if (next->end || _comp(val.first, next->_value.first)){
						//std::cout << "Eccomi!!!\n";
						t = _tree.insert(position._ptr, val);
						return iterator(t);	
					}
				}

				t = _tree.Search(_tree.getRoot(), val.first, last);
				//se non esiste un elemento con la stessa chiave
				if (t->end)
					//t = _tree.insert(last, val);
					t = _tree.insert(_tree.getRoot(), val);
				
				return iterator(t);				
			}

			//range
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last,  typename enable_if<!is_integral<InputIterator>::value && is_iterator<InputIterator>::value, InputIterator>::type* = 0)
			{
/* 				for (; first != last; first++) {
					insert(*first);
				} */
				iterator it (_tree.getRoot());
				for (; first != last; first++) {
					it = insert(it, *first);
				}
			}


     		void erase(iterator position)
			{
				this->erase(position->first);
			}
	
			size_type erase(const key_type& k)
			{
				return this->_tree.Remove(k);
			}
	
    		 void erase (iterator first, iterator last)
			 {

			 }

			key_compare key_comp() const
			{
				return key_compare();
			}

			value_compare value_comp() const
			{
				return value_compare(key_comp());
			}

			const_iterator upper_bound (const key_type& k) const
            {
                NodeType *node = this->_tree.Search(this->_tree.getRoot(), k);
                if (!node->end){
                    node = this->_tree.Next(node);
                }
                return const_iterator(node);
            }
	};


	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

}

#endif