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
            typedef Key                                                 key_type;
            typedef T                                                   mapped_type;
            typedef typename Alloc::value_type                          value_type;
            typedef Compare                                             key_compare;
            typedef Node<value_type>                                    map_node;
            typedef Alloc                                               allocator_type;
            typedef typename Alloc::template rebind<map_node>::other    alloc_node;     /* https://stackoverflow.com/questions/14148756/what-does-template-rebind-do */
            typedef Tree<Alloc, key_compare>           					TreeType;
            typedef typename TreeType::iterator                         iterator;
            typedef typename TreeType::const_iterator                   const_iterator;
            typedef b_reverse_iterator<iterator>                        reverse_iterator;
            typedef b_reverse_iterator<const_iterator>                  const_reverse_iterator;
            typedef std::ptrdiff_t                                      difference_type;
            typedef size_t                                              size_type;
        private:
            typedef typename TreeType::NodeType NodeType;
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

		private:
			allocator_type  _allocator;
			size_type       _size;
			key_compare		_comp;
			alloc_node		_alloc;

			std::string myOutOfRange(const key_type& k) const
			{
				std::stringstream sstm;
				sstm << "map::at:  key not found: __k (which is " << k << ")" << std::endl;
				return sstm.str();
			}
			TreeType	_tree;
		public:
			//ft::Tree<value_type, key_compare>	_tree;

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

/* ------------------------------- ELEMENT ACCESS ------------------------------- */
     		mapped_type& at (const key_type& k)
			{
				NodeType * last;
				NodeType *t = _tree.Search(_tree.getRoot(), k, last);
				if (t->end)
					throw std::out_of_range(myOutOfRange(k));
				return iterator(t)->second;
			}

			const mapped_type& at (const key_type& k) const
			{
				NodeType * last;
				NodeType *t = _tree.Search(_tree.getRoot(), k, last);
				if (t->end)
					throw std::out_of_range(myOutOfRange(k));
				return const_iterator(t)->second;
			}

			mapped_type& operator[] (const key_type& k)
			{
				return (*( ( this->insert(make_pair(k, mapped_type())) ).first ) ).second;
			}
/* ------------------------------- ITERATORS ------------------------------- */

			iterator begin(){
				return iterator(_tree._begin);
			}

			const_iterator begin() const
			{
				return const_iterator(_tree._begin);
			}

			iterator end(){
				return iterator(_tree._end);
			}

			const_iterator end() const
			{
				return const_iterator(_tree._end);
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}

/* ------------------------------- CAPACITY ------------------------------- */

			size_type size() const { return this->_tree.size(); }

			size_type count(const key_type& k) const
			{
				NodeType *last;
                NodeType *t = this->_tree.Search(this->_tree.getRoot(), k, last);
				if (t->end)
					return 0;
				return 1;
			}

			bool empty() const { return (this->_tree.size() == 0); }

			size_type max_size() const 
			{
				return (_alloc.max_size());
			}

/* ------------------------------- MODIFIERS ------------------------------- */

			//single element
			pair<iterator,  bool> insert(const value_type& val)
			{
				NodeType * last = _tree.getRoot();
				NodeType *t = _tree.Search(_tree.getRoot(), val.first, last);

				if (!t->end)
					return ft::make_pair<iterator,  bool>(iterator(t), false);
				//last punta al' ultimo nodo confrontato da Search
				t = _tree.insert(last, val);
				//t = _tree.insert(_tree.getRoot(), val);
				return ft::make_pair<iterator, bool>(iterator(t), true);
			}

			//with hint
			iterator insert(iterator position, const value_type& val)
			{
				NodeType *t, *last;
				
				//se il nuovo elemento >= di quello in position
				if (_comp(position._ptr->_value.first, val.first)){
					NodeType *next = _tree.Next(position._ptr);
					//se il nuovo elemento è l'elemento successivo a quello in position
					if (next->end || _comp(val.first, next->_value.first)){
						//std::cout << "Eccomi!!!\n";
						t = _tree.insert(position._ptr, val);
						return iterator(t);	
					}
				}
				last = _tree.getRoot();
				t = _tree.Search(_tree.getRoot(), val.first, last);
				//se non esiste un elemento con la stessa chiave
				if (t->end)
					t = _tree.insert(last, val);
				
				return iterator(t);				
			}

			//range
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last,  typename enable_if<!is_integral<InputIterator>::value && is_iterator<InputIterator>::value, InputIterator>::type* = 0)
			{
				iterator it (_tree.getRoot());
				for (; first != last; first++) {
					it = insert(it, *first);
				}
			}

			size_type erase(const key_type& k)
			{
				return this->_tree.Remove(k);
			}

     		void erase(iterator position)
			{
				this->erase(position->first);
			}
	

			void erase(iterator first, iterator last)
			{
/* 				for (; first != last; first++) {
					this->erase(first);
				}	 */		

				while (first != last){
					key_type k = first->first;
					first++;
					erase(k);
				}

			}

			void clear()
			{
				erase(begin(), end());
			}
			
			key_compare key_comp() const
			{
				return key_compare();
			}

			value_compare value_comp() const
			{
				return value_compare(key_comp());
			}

      		iterator find(const key_type& k)
			{
				NodeType *last;
                NodeType *t = this->_tree.Search(this->_tree.getRoot(), k, last);
				if (t->end)
					return end();
				return iterator(t);				
			}

			const_iterator find(const key_type& k) const
			{
				NodeType *last;
                NodeType *t = this->_tree.Search(this->_tree.getRoot(), k, last);
				if (t->end)
					return end();
				return const_iterator(t);		
			}

			iterator lower_bound(const key_type& k)
			{
				iterator it;
				iterator _end = end();
				for (it = begin(); it != _end; it++){
					if (!_comp(it->first, k))
						break;
				}
                return it;
			}

			const_iterator lower_bound(const key_type& k) const
			{
				const_iterator it;
				const_iterator _end = end();
				for (it = begin(); it != _end; it++){
					if (!_comp(it->first, k))
						break;
				}
                return it;
			}

			iterator upper_bound(const key_type& k)
			{
				iterator it;
				iterator _end = end();
				for (it = begin(); it != _end; it++){
					if (_comp(k,it->first))
						break;
				}
                return it;
			}

			const_iterator upper_bound(const key_type& k) const
            {
				const_iterator it;
				const_iterator _end = end();
				for (it = begin(); it != _end; it++){
					if (_comp(k,it->first))
						break;
				}
                return it;
            }

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				const_iterator lower = lower_bound(k);
				const_iterator upper = upper_bound(k);
				return ft::make_pair<const_iterator, const_iterator>(lower,upper);
			}

			pair<iterator,iterator>	equal_range (const key_type& k)
			{
				iterator lower = lower_bound(k);
				iterator upper = upper_bound(k);
				return ft::make_pair<iterator, iterator>(lower,upper);
			}

			void swap (map& x)
			{
				ft::swap(this->_allocator, x._allocator);
				ft::swap(this->_size, x._size);
				ft::swap(this->_tree, x._tree);
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

	void debugxx()
	{
		int ciao;
	}

}

namespace std
{
	template< class T, class Alloc >
	void swap( ft::map<T,Alloc>& lhs, ft::map<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	};
}

#endif