#ifndef TREE_HPP
#define TREE_HPP

#define  BLACK	0
#define  RED	1
#include "pair.hpp"
#include "iterator.hpp"
#include "utils.hpp"

namespace ft {

template < class Pair, class Compare >
bool is_less(typename Pair::first_type &a, typename Pair::first_type &b){
	Compare u;
	return u(a, b);
}

template < class Pair, class Compare >
bool is_less(Pair &a, Pair &b){
	return (is_less(a.first, b.first));
}

template < class Pair>
struct Node
{
	public:
		typedef typename	Pair::first_type	Ktype;
		typedef typename	Pair::second_type	Vtype;
		Pair									_value;
		Node									*parent;
		Node									*left;
		Node									*right;
		bool 									end;
		int										color;

		Node(const Ktype &k = Ktype(), const Vtype &v = Vtype() ) : _value(k, v), parent(nullptr), left(nullptr), right(nullptr), end(false), color(RED)
		{};
		~Node(){};
		Node(const Pair &pair) : _value(pair), parent(nullptr), left(nullptr), right(nullptr),  end(false), color(RED) {
		};
		Ktype getFirst() { return _value.getFirst(); };
		Vtype getSecond() { return _value.getSecond(); };

		Node &operator=(const Node& c) {
			_value = c._value;
			parent = c.parent;
			left = c.left;
			right = c.right;
			end = c.end;
			color = c.color;
			return (*this);

		}
};

template < class Pair>
std::ostream& operator<<(std::ostream& os, const Node<Pair>& n)
{
	//os << "(" << n.key << "," << n.value << ")";
	os << n._value.first;
	//os << n.getFirst();
	return os;
}

template <class Pair>
class tree_iterator
{
	public:
		typedef  			Pair														value_type;
		typedef 			Node<value_type>                                			NodeType;
		typedef	typename 	std::allocator<NodeType>::template rebind<NodeType>::other	Alloc;
		typedef typename 	Alloc::pointer 												NodePointer;
		typedef typename	Alloc::difference_type										difference_type;   
		typedef	std::bidirectional_iterator_tag											iterator_category;		
		typedef typename 	std::allocator<Pair>::pointer								pointer;
		typedef typename 	std::allocator<Pair>::reference								reference;	
	private:

		NodePointer _ptr;
		NodePointer next_node(NodePointer x) {
			if (x->end)
				return x;
			NodePointer t = x->right;	
			if (!t->end)
			{
				while (!t->left->end)
					t = t->left;
			}
			else
			{
				t = x->parent;
				while (t && !t->end && x == t->right){
					x = t;
					t = x->parent;
				}
			}
			return t;
		}

		NodePointer prev_node(NodePointer x) {
			NodePointer t = x->left;
			if (x->end){
				return x->parent;	
			}
			if (!t->end)
			{
				while (!t->right->end)
					t = t->right;
			}
			else
			{
				t = x->parent;
				while (t && !t->end && x == t->left){
					x = t;
					t = x->parent;
				}

			}
			return t;
		}

	public:
		tree_iterator() : _ptr(nullptr){}
		tree_iterator(NodePointer p) : _ptr(p){}

		tree_iterator(const tree_iterator& __u) : _ptr(__u._ptr){}
		tree_iterator(tree_iterator<const Pair>& __u) : _ptr(__u._ptr){}

		reference   operator*() const   { return _ptr->_value; }
		pointer     operator->() const     { return &(_ptr->_value); }

		tree_iterator& operator++() {_ptr = next_node(_ptr); return *this; };
		tree_iterator operator++(int) {tree_iterator tmp = *this; _ptr = next_node(_ptr); return tmp; };
		tree_iterator& operator--() {_ptr = prev_node(_ptr); return *this; };								//Prefix increment operator
		tree_iterator operator--(int) {tree_iterator tmp = *this; _ptr = prev_node(_ptr); return tmp; }; //Postfix increment operator
		template <class Key, class T, class Comp, class Alloc> friend class map;
		bool operator==(const tree_iterator &tri) const { return (_ptr == tri._ptr); };
		bool operator!=(const tree_iterator &tri) const { return (_ptr != tri._ptr); };
		tree_iterator   &operator=(const tree_iterator &s) { _ptr = s._ptr;  return (*this);}

		template<class _P>
		friend class const_tree_iterator;
};


template <class Pair>
class const_tree_iterator
{
	public:
		typedef 			Pair														value_type;
		typedef 			Node<value_type>                                			NodeType;
		typedef	typename 	std::allocator<NodeType>::template rebind<NodeType>::other	Alloc;
		typedef typename 	Alloc::pointer 												NodePointer;
		typedef typename	Alloc::difference_type										difference_type;   
		typedef	std::bidirectional_iterator_tag											iterator_category;		
		typedef typename 	std::allocator<Pair>::const_pointer							pointer;
		typedef typename 	std::allocator<Pair>::reference								reference;	
	private:
		NodePointer _ptr;
		NodePointer next_node(NodePointer x) {
			if (x->end)
				return x;
			NodePointer t = x->right;	
			if (!t->end)
			{
				while (!t->left->end)
					t = t->left;
			}
			else
			{
				t = x->parent;
				while (t && !t->end && x == t->right){
					x = t;
					t = x->parent;
				}
			}
			return t;
		}

		NodePointer prev_node(NodePointer x) {
			NodePointer t = x->left;
			if (x->end){
				return x->parent;	
			}
			if (!t->end)
			{
				while (!t->right->end)
					t = t->right;
			}
			else
			{
				t = x->parent;
				while (t && !t->end && x == t->left){
					x = t;
					t = x->parent;
				}

			}
			return t;
		}

	public:
		const_tree_iterator() : _ptr(nullptr){}
		const_tree_iterator(NodePointer p) : _ptr(p){}

		const_tree_iterator(const const_tree_iterator& __u) : _ptr(__u._ptr){}
		const_tree_iterator(tree_iterator<Pair>& __u) : _ptr(__u._ptr){}
		const_tree_iterator(const tree_iterator<Pair>& __u) : _ptr(__u._ptr){}
		const_tree_iterator(tree_iterator<const Pair>& __u) : _ptr(__u._ptr){}

		reference   operator*() const   { return _ptr->_value; }
		pointer     operator->() const     { return &(_ptr->_value); }

		const_tree_iterator& operator++() {_ptr = next_node(_ptr); return *this; };
		const_tree_iterator operator++(int) {const_tree_iterator tmp = *this; _ptr = next_node(_ptr); return tmp; };
		const_tree_iterator& operator--() {_ptr = prev_node(_ptr); return *this; };								//Prefix increment operator
		const_tree_iterator operator--(int) {const_tree_iterator tmp = *this; _ptr = prev_node(_ptr); return tmp; }; //Postfix increment operator
		bool operator==(const const_tree_iterator &tri) const { return (_ptr == tri._ptr); };
		bool operator!=(const const_tree_iterator &tri) const { return (_ptr != tri._ptr); };
		const_tree_iterator   &operator=(const const_tree_iterator &s) { _ptr = s._ptr;  return (*this);}
};

/*	PROPRIETà ALBERO ROSSO-NERO (il cui mantenimento garantisce il bilanciamento)
	1) Ogni nodo ha colore rosso o nero.
	2) Il nodo root inizialmente è nero.
	3) Ogni foglia è nera e contiene elemento null;
	4) Entrambi i figli di ciascun nodo rosso sono neri;
	5) Ogni cammino da un nodo a una foglia nel suo sottoalbero contiene lo stesso numero di nodi neri.
*/
template <class Alloc, class Compare>
class Tree {
	public:
		typedef typename Alloc::value_type										Pair;
		typedef Node<Pair>                                    					NodeType;
		typedef typename Alloc::template rebind<NodeType>::other    			allocator_type;
		typedef typename Alloc::template rebind< Node<const Pair> >::other    	const_allocator_type;
		typedef typename allocator_type::value_type                     		value_type;
		typedef typename allocator_type::reference                      		reference;
		typedef typename allocator_type::const_reference                		const_reference;
		typedef typename allocator_type::pointer                       			pointer;
		typedef typename allocator_type::const_pointer                  		const_pointer;
		pointer                                                         		_begin;                     	//jfabi: da mettere privati e fare
		pointer                                                         		_end;                           //getBeign e getEnd
		typedef  tree_iterator< Pair>    		 		iterator;
		typedef  const_tree_iterator< Pair>    		const_iterator;
	private:
		pointer				_root;
		
		allocator_type  	_allocator;
		size_t				_size;

		pointer	newNode(const value_type &e, bool end = false){
			pointer	node = _allocator.allocate(1);
			_allocator.construct(node, e);
			if (end){
				node->end = true;
				node->left = node;
				node->right = node;
				node->parent = node;
				node->color = BLACK;
			}else{
				node->left = _end;
				node->right = _end;
				node->parent = _end;
			}
				
			return node;
		}

		void	deleteNode(pointer t){
			_allocator.destroy(t);
			_allocator.deallocate(t, 1);
		}

		void destroyNode(pointer t) {
			_allocator.destroy(t);
		}

		pointer grandparent(pointer n) {
			if (n->parent->end)
				return this->_end;
			return n->parent->parent;
		}

		pointer uncle(pointer n) {
			if (grandparent(n)->end)
				return this->_end;
			if (n->parent == grandparent(n)->left)
				return grandparent(n)->right;
			else
				return grandparent(n)->left;
		}


		void rotate_left(pointer p){
			pointer rChild = p->right;
			p->right = rChild->left;
			if (!rChild->left->end)
				rChild->left->parent = p;
			rChild->left = p;
			rChild->parent = p->parent;
			if (p == p->parent->left)
				p->parent->left = rChild;
			else
				p->parent->right = rChild;
			p->parent = rChild;
			if(_root == p){
				_root = rChild;
				_root->parent = _end;
			}
		}

		void rotate_right(pointer p){
			pointer lChild = p->left;
			p->left = lChild->right;
			if (!lChild->right->end)
				lChild->right->parent = p;
			lChild->right = p;
			lChild->parent = p->parent;
			if (p == p->parent->left)
				p->parent->left = lChild;
			else
				p->parent->right = lChild;
			p->parent = lChild;
			if (_root == p){
				_root = lChild;
				_root->parent = _end;
			}
		}

		//se il nuovo nodo inserito è la root lo coloro di nero
		void insert_case1(pointer n) {
			if (n->parent->end)
				n->color = BLACK;
			else
				insert_case2(n);
		}

		//se il padre del nuovo nodo(rosso) è nero
		void insert_case2(pointer n) {
			if (n->parent->color == RED)
				insert_case3(n);
		}

		//casi 3,4,5 assumo n abbia nonno G, poichè il padre rosso non può essere per regola 2 la root
		//se P(padre) e U(uncle) di N sono entrambi rossi, li coloro di nero e G di rosso.
		//Data possibile violazione delle prorietà 2 e 4 applico ricorsivamente su G insert_case1
		void insert_case3(pointer n) {
			if (!uncle(n)->end && uncle(n)->color == RED) {
				n->parent->color = BLACK;
				uncle(n)->color = BLACK;
				grandparent(n)->color = RED;
				insert_case1(grandparent(n));
			}
			else
				insert_case4(n);
		}

		//se il padre P è rosso ma lo zio U è nero
		void insert_case4(pointer n) {
			//se N figlio destro e P figlio sinistro
			if (n == n->parent->right && n->parent == grandparent(n)->left) {
				rotate_left(n->parent);
				n = n->left;
			} //se N figlio sinistro e P figlio destro
			else if (n == n->parent->left && n->parent == grandparent(n)->right) {
				rotate_right(n->parent);
				n = n->right;
			}
			insert_case5(n);
		}

		//il padre P è rosso ma il nonno G e lo zio U sono neri, il nuovo nodo N è il figlio sinistro di P, e P è il figlio sinistro di G.
		void insert_case5(pointer n) {
			n->parent->color = BLACK;
			grandparent(n)->color = RED;
			if (n == n->parent->left && n->parent == grandparent(n)->left) {
				rotate_right(grandparent(n));
			} else {
				/* n == n->parent->right && n->parent == grandparent(n)->right */
				rotate_left(grandparent(n));
			}
		}

		pointer sibling(pointer n) {
			if (n == n->parent->left)
				return n->parent->right;
			else
				return n->parent->left;
		}

		void delete_one_child(pointer n) {
			/* Si assume che n ha al massimo un figlio non nullo */
			pointer child = (n->right->end) ? n->left: n->right;
			if (!child->end){
				replace(n, child);
				if (n->color == BLACK) {
					if (child->color == RED)
						child->color = BLACK;
					else
						delete_case1(child);
				}
			}else{
				return _Remove1(n);
			}

			_Remove(n, child);
			//deleteNode(n);
		}

		void delete_case1(pointer n) {
			if (n->parent->end)
				return;
			delete_case2(n);
		}

		void delete_case2(pointer n) {
			if (sibling(n)->color == RED) {
				n->parent->color = RED;
				sibling(n)->color = BLACK;
				if (n == n->parent->left)
					rotate_left(n->parent);
				else
					rotate_right(n->parent);
			}
			delete_case3(n);
		}

		void delete_case3(pointer n) {
			if (n->parent->color == BLACK &&
				sibling(n)->color == BLACK &&
				sibling(n)->left->color == BLACK &&
				sibling(n)->right->color == BLACK)
			{
				sibling(n)->color = RED;
				delete_case1(n->parent);
			}
			else
				delete_case4(n);
		}

		void delete_case4(pointer n) {
			if (n->parent->color == RED &&
				sibling(n)->color == BLACK &&
				sibling(n)->left->color == BLACK &&
				sibling(n)->right->color == BLACK)
			{
				sibling(n)->color = RED;
				n->parent->color = BLACK;
			}
			else
				delete_case5(n);
		}

		void delete_case5(pointer n) {
			if (n == n->parent->left &&
				sibling(n)->color == BLACK &&
				sibling(n)->left->color == RED &&
				sibling(n)->right->color == BLACK)
			{
				sibling(n)->color = RED;
				sibling(n)->left->color = BLACK;
				rotate_right(sibling(n));
			}
			else if (n == n->parent->right &&
					sibling(n)->color == BLACK &&
					sibling(n)->right->color == RED &&
					sibling(n)->left->color == BLACK)
			{
				sibling(n)->color = RED;
				sibling(n)->right->color = BLACK;
				rotate_left(sibling(n));
			}
			delete_case6(n);
		}

		void delete_case6(pointer n) {
			sibling(n)->color = n->parent->color;
			n->parent->color = BLACK;
			if (n == n->parent->left) {
				sibling(n)->right->color = BLACK;
				rotate_left(n->parent);
			}
			else
			{
				sibling(n)->left->color = BLACK;
				rotate_right(n->parent);
			}
		}

	public:
		Tree() : _size(0) {
			this->_end = newNode(value_type(), true);
			this->_begin = _end;
			this->_root = _begin;
		};

		Tree(const Pair &p){
			this->_end = newNode(value_type(), true);
			this->_begin = _end;
			this->_root = _begin;
			insert(this->_root, p);
		}

		~Tree(){
			destroyTree();
		};


		void	ft_clear(pointer nodo)
		{
			if (nodo != nullptr && !nodo->end) {
				clear(nodo->left);
				clear(nodo->right);
				deleteNode(nodo);
			}
		}

		void clear(pointer nodo)
		{
			ft_clear(nodo);
			this->_begin = _end;
			this->_root = _end;
			this->_size = 0;
			this->_root->parent = this->_end;
		}

		void	destroyTree()
		{
			clear(_root);
			deleteNode(_end);
		}

		Tree   &operator=(const Tree &t) {
			std::cout << "bella rega" << std::endl;
			_size = t._size;
			*_begin = *(t._begin);
			*_end = *(t._end);
			_allocator = t._allocator;
			*_root = *(t._root);
			return (*this);
		}

		pointer getRoot() const { return (_root);}

		//bool end(pointer & p){return (p == _end);}
		bool end(pointer & p) const {return p->end;}

		pointer insert(pointer node, const Pair &pair)
		{
			pointer parent, entry, tmp;

			entry = newNode(pair);
			parent = nullptr;

			while (!node->end)
			{
				parent = node;
				if ( less(entry, node) )
					node = node->left;
				else 
					node = node->right;
			}

			if (parent != nullptr)
			{
				if (less(entry, parent))
				{
					parent->left = entry;
					if (parent == _begin)
						_begin = entry;
				}
				else{
					parent->right = entry;
					if(parent == this->_end->parent)
						this->_end->parent = entry;
				}
				entry->parent = parent;

			}else{
				this->_root = entry;
				this->_root->parent = this->_end;
				_begin = _root;
				this->_end->parent = this->_root;
			}

			entry->left = _end;
			entry->right = _end;
			_size++;
			insert_case1(entry);
			return entry;
		}


		pointer	Search(pointer t, typename Pair::first_type &target, pointer &last, bool flag = false) const
		{
			//salvo in last l'ultimo nodo confrontato (per ottimizzare insert)
			if (!t->end) {
				last = t;
				if (less(target, t->_value.first) )
					return Search(t->left, target, last);
				if (less(t->_value.first, target) || flag)
					return Search(t->right, target, last);
			}
			
			return t;
		}

		pointer lower_bound(const typename Pair::first_type &k){
			pointer i;
			Search(_root, k, i);
			while(!i->end && less(i->_value.first, k) )
				i = i->parent;

			return i;
		}

		pointer upper_bound(const typename Pair::first_type &k){
			pointer i;
			Search(_root, k, i, true);
			while(!i->end && !less(k, i->_value.first) )
				i = i->parent;

			return i;
		}

		//Il successore di un nodo X è il più piccolo nodo maggiore del sottalbero destro del nodo X
		pointer	Successor(pointer &x) const
		{
			pointer t = x->right;
			while (!end(t->left))
				t = t->left;
			return t;
		}

		pointer	Predecessor(pointer &x)
		{
			pointer t = x->left;
			while (!end(t->right))
				t = t->right;
			return t;
		}

		pointer	Next(pointer &x) const{
			pointer	t;
			if (!x->right->end)
				return Successor(x);

			t = x->parent;
			while (!t->end && x == t->right){
				x = t;
				t = x->parent;
			}
			return t;
		}

		pointer	Prev(pointer &x) {
			pointer	t;
			if (!x->left->end)
				return Predecessor(x);

			t = x->parent;
			while (!t->end && x == t->left){
				x = t;
				t = x->parent;
			}
			return t;
		}

/* 		void replace(pointer	original, pointer	replace)
		{
			replace->left = original->left;
			replace->right = original->right;
			replace->parent = original->parent;
			if (original->parent)
			{
				//bool left = is_less<Pair,Compare>(original->_value.first, original->parent->_value.first);
				bool left = original->parent->left == original;
				if (left)
					replace->parent->left = replace;
				else
					replace->parent->right = replace;
			}
			if (!replace->left->end && replace->left != replace)
				replace->left->parent = replace;
			if (!replace->right->end  && replace->right != replace)
				replace->right->parent = replace;
		} */

		void replace(pointer	original, pointer	replace)
		{
			if (original->parent != replace)
			{
				replace->parent = original->parent;
				//bool left = is_less<Pair,Compare>(original->_value.first, original->parent->_value.first);
				if (!original->parent->end){
					if (original->parent->left == original)
						replace->parent->left = replace;
					else
						replace->parent->right = replace;
				}
			}
			if (original->left != replace)
			{
				if (!original->left->end){
					replace->left = original->left;
					replace->left->parent = replace;
				}
			}
			if (original->right != replace)
			{
				if (!original->right->end){
					replace->right = original->right;
					replace->right->parent = replace;
				}
			}
		}

		void _Remove(pointer t, pointer s){
			if (t == _root)
				_root = s;
			_size--;
			if (_size == 0)
				_begin = _end;
			else if (t == _begin)
				_begin = Next(_begin);

			// t è il nodo più grande dell' albero 
			if (t == this->_end->parent){
				this->_end->parent = Prev(t);
			}
			deleteNode(t);
		}

		void _Remove1(pointer t){
			//caso 1: t senza figli, caso 2: t con un solo figlio
			if (end(t->left) || end(t->right))
			{					
				pointer	s = end(t->left) ? t->right : t->left;
				if (t->parent)
				{
					// t è figlio sinistro
					if (t == t->parent->left)
						t->parent->left = s;
					else // t è figlio destro
						t->parent->right = s;
				}
				if (!end(s))
					s->parent = t->parent;
				return _Remove(t, s);
			}
			_Remove2(t);
		}

		void _Remove2(pointer t){
			pointer	s;
			//caso 3a: t ha 2 figli e il figlio destro è il suo successore
			if( (s = Successor(t)) == t->right )
			{
				pointer	tmp = s->right;
				replace(t, s);
				s->right = tmp;
				s->left->parent = s;
				return _Remove(t, s);
			}
			_Remove3(t, s);
		}

		void _Remove3(pointer t, pointer s){
			//caso 3b: t ha 2 figli e il suo successore si trova nell sottalbero(sinistro) del suo figlio destro
			//sostituisco il successore con il suo figlio destro
			s->parent->left = s->right;
			if (s->right)
				s->right->parent = s->parent;
			//sostituisco t con il successore s
			replace(t, s);
			_Remove(t, s);
		}

		size_t	Remove(typename Pair::first_type target)
		{
			//std::cout << "remove" << std::endl;
			pointer	last;
			pointer	t = Search(_root, target, last);
			pointer	s = _end;
			size_t n = 0;
			if (!t->end)
			{
				_Remove1(t);
				//delete_one_child(t);
				n = 1;
			}

			return n;
		}

		pointer		begin() { return (_begin); }
		size_t		size() const { return (_size); }

		size_t PreOrder(pointer	nodo) {
			if (nodo != nullptr && !nodo->end) {
				//visita(nodo);
				//std::cout << *nodo << std::endl;
				return  std::max(PreOrder(nodo->left), PreOrder(nodo->right)) + 1;
			}
			return 0;
		}

		bool less(pointer &a, pointer &b) const{
			Compare comp;
			return (comp(a->_value.first, b->_value.first));
		}

		bool less(typename Pair::first_type &a, typename Pair::first_type &b) const{
			Compare comp;

			return (comp(a, b));
		}

		void swap (Tree& x)
		{
			ft::swap(this->_allocator, x._allocator);
			ft::swap(this->_size, x._size);
			ft::swap(this->_begin, x._begin);
			ft::swap(this->_end, x._end);
			ft::swap(this->_root, x._root);
		}
};
}

namespace ft
{
	template <class Pair, class Compare>
	void swap( ft::Tree<Pair, Compare>& lhs, ft::Tree<Pair, Compare>& rhs )
	{
		lhs.swap(rhs);
	};
}

#endif