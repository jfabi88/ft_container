#ifndef TREE_HPP
#define TREE_HPP

#include "pair.hpp"
#include "iterator.hpp"

namespace ft {

template < class Pair, class Compare >
bool is_less(typename Pair::first_type a, typename Pair::first_type b){
	Compare u;
	return u(a, b);
}

template < class Pair, class Compare>
struct Node
{
	public:
		typedef typename 	Pair::first_type	Ktype;
		typedef typename	Pair::second_type	Vtype;
		//Ktype									key;
		Ktype									first;
		//Vtype									value;
		Vtype									second;
		Node									*parent;
		Node									*left;
		Node									*right;
		bool 									end;

		Node(const Ktype &k = Ktype(), const Vtype &v = Vtype() ) : first(k), second(v), parent(nullptr), left(nullptr), right(nullptr), end(false){
		};
		~Node(){};
		Node(const Pair &pair) : first(pair.first), second(pair.second), parent(nullptr), left(nullptr), right(nullptr),  end(false){
		};

		bool    operator<(const Node &s) const
		{ 
			Compare u;
			return u(first, s.first);
		} 
};

template < class Pair, class Compare>
std::ostream& operator<<(std::ostream& os, const Node<Pair, Compare>& n)
{
	//os << "(" << n.key << "," << n.value << ")";
	os << n.first;
	return os;
}


template <class Pair, class Compare = std::less< typename Pair::first_type> >
class Tree {
	public:
		typedef	Node<Pair, Compare>							NodeType;
		typedef	std::allocator< NodeType >					allocator_type;
		typedef typename allocator_type::reference  		reference;			
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer  			pointer;			
		typedef typename allocator_type::const_pointer  	const_pointer;
		NodeType			*_begin;
	private:
		NodeType 			*_root;
		NodeType 			*_end;
		
		allocator_type  	_allocator;
		size_t				_size;

		NodeType *newNode(const NodeType &e){
			NodeType *node = _allocator.allocate(1);
			_allocator.construct(node, e);
			return node;
		}

		void	deleteNode( NodeType *t){
			_allocator.destroy(t);
			_allocator.deallocate(t, 1);
		}

		

	public:
		Tree() : _size(0) {
			this->_end = newNode(NodeType());
			this->_end->end = true;
			this->_begin = _end;
			this->_root = _begin;
		};

		Tree(const Pair &p){
			this->_end = newNode(NodeType());
			this->_end->end = true;
			this->_begin = _end;
			this->_root = _begin;
			insert(p);
		}

		~Tree(){
			deleteNode(_end);
			//destroyTree();
		};

		Tree   &operator=(const Tree &t) { _root = t._root;  return (*this);}

		NodeType* & getRoot() { return (_root);}

		bool end(pointer & p){return (p == _end);}

		NodeType* insert(const Pair &pair)
		{
			NodeType *node, *parent, *entry;

			entry = newNode(pair);
			parent = nullptr;
			node = _root;

			while (!end(node))
			{
				parent = node;
				if ( *entry < *node )
					node = node->left;
				else 
					node = node->right;
			}

			if (parent != nullptr)
			{
				if (*entry < *parent)
				{
					parent->left = entry;
					if (parent == _begin)
						_begin = entry;
				}
				else
					parent->right = entry;
				entry->parent = parent;
			}else{
				this->_root = entry;
				_begin = _root;
			}

			entry->left = _end;
			entry->right = _end;
			_size++;
			return entry;
		}

/* 		NodeType* insert(const Pair &pair)
		{
			NodeType *node, *parent;

			NodeType *_new = newNode(pair);
			if (this->root == nullptr){
				this->root = _new;
				root->right = end;
				_begin = root;
				end->parent = root;
			}
			else{
				node = this->root;
				while (node != nullptr && node != end)
				{
					parent = node;
					if ( *_new < *node )
						node = node->left;
					else 
						node = node->right;
				}
				_new->parent = parent;
				if (*_new < *parent)
				{
					parent->left = _new;
					if (parent == _begin)
						_begin = _new;
				}
				else
					parent->right = _new;
				if (node == end)
					_new->right = end;
			}
			_size++;
			return _new;
		} */

/* 		NodeType* rInsert(NodeType *t, const NodeType &e)
		{
			if (t == nullptr){
					root = newNode(e);
				return root;
			}

			NodeType *_new;

			if (e < *t){
				if (t->left)
					return rInsert(t->left,  e);
				t->left = _new = newNode(e);
			}else{
				if (t->right)
					return rInsert(t->right,  e);
				t->right = _new = newNode(e);
			}
			return _new;
		} */


		NodeType *Search(NodeType *t, typename Pair::first_type target)
		{
			if (!end(t)) {
				if (target == t->first)
					return t;
				if (is_less< Pair,Compare>(target, t->first))
					return Search(t->left, target);
				return Search(t->right, target);
			}
			return t;
		}

		//Il successore di un nodo X è il più piccolo nodo maggiore del nodo X
		NodeType *Successor(NodeType *x)
		{
			NodeType *t = x->right;
			while (!end(t->left))
				t = t->left;
			return t;
		}

		NodeType *Next(NodeType *x) {
			NodeType *t = (!end(x->right)) ? Successor(x) :  x->parent;
			while (*t < *x)
				t = t->parent;
			return t;
		}
	
		void replace(NodeType *original, NodeType *replace)
		{
			replace->left = original->left;
			replace->right = original->right;
			replace->parent = original->parent;
			if (original->parent)
			{
				bool left = is_less<Pair,Compare>(original->key, original->parent->key);
				if (left)
					replace->parent->left = replace;
				else
					replace->parent->right = replace;
			}
			if (replace->left)
				replace->left->parent = replace;
			if (replace->right)
				replace->right->parent = replace;
		}

		NodeType *Remove(typename Pair::first_type target)
		{
			NodeType *t = Search(_root, target);
			NodeType *s = _end;

			if (!end(t))
			{
				//caso 1: t senza figli, caso 2: t con un solo figlio
				if (end(t->left) || end(t->right))
				{					
					s = (end(t->left)) ? t->right : t->left;
					if (t->parent)
					{
						if (is_less<Pair,Compare>(t->key, t->parent->key))
							t->parent->left = s;
						else
							t->parent->right = s;
					}
					if (!end(s))
						s->parent = t->parent;
				}else if( (s = Successor(t)) == t->right){
					//caso 3a: t ha 2 figli e il figlio destro è il suo successore
					NodeType *tmp = s->right;
					replace(t, s);
					s->right = tmp;
					s->left->parent = s;
				}else{
					//caso 3b: t ha 2 figli e il suo successore si trova nell sottalbero(sinistro) del suo figlio destro
					//sostituisco il successore con il suo figlio destro
					s->parent->left = s->right;
					if (s->right)
						s->right->parent = s->parent;
					//sostituisco t con il successore s
					replace(t, s);
				}
				if (t == _root)
					_root = s;
				_size--;
				if (_size == 0)
					_begin = _end;
				else if (t == _begin)
					_begin = Next(_begin);
				deleteNode(t);
			}
			return _root;
		}

		NodeType	*begin() { return (_begin); }
		size_t		size() { return (_size); }

		size_t PreOrder(NodeType *nodo) {
			if (nodo != nullptr && !nodo->end) {
				//visita(nodo);
				//std::cout << *nodo << std::endl;
				return  std::max(PreOrder(nodo->left), PreOrder(nodo->right)) + 1;
			}
			return 0;
		}

};

template <class Node, class Compare >
class tree_iterator
{
	//private:
		//typedef Node<Pair, Compare> NodeType;
	public:
		typedef typename iterator_traits<Node>::iterator_category	iterator_category;
		typedef typename iterator_traits<Node>::value_type			value_type;
		typedef typename iterator_traits<Node>::difference_type		difference_type;
		typedef typename iterator_traits<Node>::pointer				pointer;
		typedef typename iterator_traits<Node>::reference			reference;
	private:
		pointer _ptr;
		pointer next_node(pointer *x) {
			pointer *t = x->right;
			if (t)
			{
				while (t->left)
					t = t->left;
			}
			else
			{
				t = x->parent;
				while (*t < *x)
					t = t->parent;
			}
			return t;
		}
	public:
		tree_iterator() : _ptr(nullptr){}
		tree_iterator(pointer p) : _ptr(p){}

		reference   operator*() const   { return *_ptr; }
		pointer     operator->()        { return _ptr; }

		tree_iterator& operator++() {_ptr = next_node(_ptr); return *this; };
		tree_iterator operator++(int) {tree_iterator tmp = *this; _ptr = next_node(_ptr); return tmp; };
		template <class Key, class T, class Comp, class Alloc> friend class map;
};

}

#endif
