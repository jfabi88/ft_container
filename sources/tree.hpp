#ifndef TREE_HPP
#define TREE_HPP

#define  BLACK	0
#define  RED	1
#include "pair.hpp"
#include "iterator.hpp"
#include "utils.hpp"

namespace ft {

template < class Pair, class Compare , class KeyType>
bool is_less(KeyType &a, KeyType &b){
	Compare u;
	return u(a, b);
}

template < class Pair, class Compare , class KeyType>
bool is_less(Pair &a, Pair &b){
	return (is_less(a.first, b.first));
}

template < class Pair>
struct Node
{
	public:
		Pair									_value;
		Node									*parent;
		Node									*left;
		Node									*right;
		bool 									end;
		int										color;

		Node(): parent(nullptr), left(nullptr), right(nullptr),  end(false), color(RED) {};
		~Node(){};
		Node(const Pair &pair) : _value(pair), parent(nullptr), left(nullptr), right(nullptr),  end(false), color(RED) {};

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
		NodePointer _ptr;
	private:
		
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

		reference   operator*() const   { return _ptr->_value; }
		pointer     operator->() const     { return &(_ptr->_value); }

		tree_iterator& operator++() {_ptr = next_node(_ptr); return *this; };
		tree_iterator operator++(int) {tree_iterator tmp = *this; _ptr = next_node(_ptr); return tmp; };
		tree_iterator& operator--() {_ptr = prev_node(_ptr); return *this; };								//Prefix increment operator
		tree_iterator operator--(int) {tree_iterator tmp = *this; _ptr = prev_node(_ptr); return tmp; }; //Postfix increment operator
		bool operator==(const tree_iterator &tri) const { return (_ptr == tri._ptr); };
		bool operator!=(const tree_iterator &tri) const { return (_ptr != tri._ptr); };
		tree_iterator   &operator=(const tree_iterator &s) { _ptr = s._ptr;  return (*this);}
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

/*	PROPRIET?? ALBERO ROSSO-NERO (il cui mantenimento garantisce il bilanciamento)
	1) Ogni nodo ha colore rosso o nero.
	2) Il nodo root inizialmente ?? nero.
	3) Ogni foglia ?? nera e contiene elemento null;
	4) Entrambi i figli di ciascun nodo rosso sono neri;
	5) Ogni cammino da un nodo a una foglia nel suo sottoalbero contiene lo stesso numero di nodi neri.
*/
template <class Alloc, class value_compare, class key_compare>
class Tree {
	public:
		typedef typename Alloc::value_type		   								Pair;
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
		value_compare 		comp;

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

		//se il nuovo nodo inserito ?? la root lo coloro di nero
		void insert_case1(pointer n) {
			if (n->parent->end)
				n->color = BLACK;
			else
				insert_case2(n);
		}

		//se il padre del nuovo nodo(rosso) ?? nero
		void insert_case2(pointer n) {
			if (n->parent->color == RED)
				insert_case3(n);
		}

		//casi 3,4,5 assumo n abbia nonno G, poich?? il padre rosso non pu?? essere per regola 2 la root
		//se P(padre) e U(uncle) di N sono entrambi rossi, li coloro di nero e G di rosso.
		//Data possibile violazione delle proriet?? 2 e 4 applico ricorsivamente su G insert_case1
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

		//se il padre P ?? rosso ma lo zio U ?? nero
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

		//il padre P ?? rosso ma il nonno G e lo zio U sono neri, il nuovo nodo N ?? il figlio sinistro di P, e P ?? il figlio sinistro di G.
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

		void swapNode(pointer a, pointer b)
		{
			pointer temp;
			a->left->parent = b;
			if (!b->left->end)
				b->left->parent = a;
			a->right->parent = b;
			if (!b->right->end)
				b->right->parent = a;
			temp = b->left;
			b->left = a->left;
			a->left = temp;
			temp = b->right;
			b->right = a->right;
			a->right = temp;
			temp = b->parent;
			b->parent = a->parent;
			a->parent = temp;
			int color = b->color;
			b->color = a->color;
			a->color = color;
			if (b->parent->end)
				_root = b;
			else {
				if (b->parent->left == a)
					b->parent->left = b;
				else
					b->parent->right = b;
			}
			if (a->parent->left == b)
				a->parent->left = a;
			else
				a->parent->right = a;
		}

		void RbTreeDelete(pointer n)
		{
			pointer child;
			//n ha due figli, lo scambio con il suo predecessore
			if (!n->left->end && !n->right->end) {
				swapNode(n, Predecessor(n));
			}

			// n non ha figli o uno solo
			//assert(n->left->end || n->right->end);
			child = n->right->end ? n->left  : n->right;
			if (n->color == BLACK) {
				n->color = child->color;
				delete_case1(n);
			}
			replace(n, child);

			/* TODO check next two lines, should be removed? */
			if (n->parent->end && !child->end) // root should be black
				child->color = BLACK;
			_Remove(n, child);
			//verify_properties();
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

		void verify_property_1(pointer n) {
			assert(n->color == RED || n->color == BLACK);
			if (n->end) return;
			verify_property_1(n->left);
			verify_property_1(n->right);
		}

		void verify_property_2() {
			assert(_root->color == BLACK);
		}

		void verify_property_4(pointer n) {
			if (n->color == RED) {
				assert (n->left->color   == BLACK);
				assert (n->right->color  == BLACK);
				assert (n->parent->color == BLACK);
			}
			if (n->end) return;
			verify_property_4(n->left);
			verify_property_4(n->right);
		}

		void verify_property_5(pointer root) {
			int black_count_path = -1;
			verify_property_5_helper(root, 0, &black_count_path);
		}

		void verify_property_5_helper(pointer n, int black_count, int* path_black_count) {
			if (n->color == BLACK) {
				black_count++;
			}
			if (n->end) {
				if (*path_black_count == -1) {
					*path_black_count = black_count;
				} else {
					assert (black_count == *path_black_count);
				}
				return;
			}
			verify_property_5_helper(n->left,  black_count, path_black_count);
			verify_property_5_helper(n->right, black_count, path_black_count);
		}

	public:
		Tree() : _size(0), comp(value_compare(key_compare())) {
			this->_end = newNode(value_type(), true);
			//this->_end = newNode(true);
			this->_begin = _end;
			this->_root = _begin;
		};

		Tree(const Pair &p){
			this->_end = newNode(value_type(), true);
			//this->_end = newNode( true);
			this->_begin = _end;
			this->_root = _begin;
			this->comp = value_compare(key_compare());
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

		void verify_properties() {
			verify_property_1(_root);
			verify_property_2();
			/* Property 3 is implicit */
			verify_property_4(_root);
			verify_property_5(_root);
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
			pointer parent, entry;

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

		pointer	Search(pointer t, const Pair &target, pointer &last, bool flag = false) const
		{
			//salvo in last l'ultimo nodo confrontato (per ottimizzare insert)
			if (!t->end) {
				last = t;
				if (less(target, t->_value) )
					return Search(t->left, target, last);
				if (less(t->_value, target) || flag)
					return Search(t->right, target, last);
			}
			
			return t;
		} 

/* 		pointer	Search(pointer t, key_type &target, pointer &last, bool flag = false) const
		{
			//typename Pair::second s;
			Pair val  = value_type
			
			return this->Search(t, val, last, flag);
			//salvo in last l'ultimo nodo confrontato (per ottimizzare insert)
			if (!t->end) {
				last = t;
				if (less(target, t->_value.first) )
					return Search(t->left, target, last);
				if (less(t->_value.first, target) || flag)
					return Search(t->right, target, last);
			}
			
			return t;
		} */

		pointer lower_bound(const Pair &k){
			pointer i;
			Search(_root, k, i);
			//Pair kval  = ft::make_pair(k, _end->_value.second);
			//while(!i->end && less(i->_value.first, k) )
			while(!i->end && less(i->_value, k) )
				i = i->parent;

			return i;
		}

		pointer upper_bound(const Pair &k){
			pointer i;
			Search(_root, k, i, true);
			//Pair kval  = ft::make_pair(k, _end->_value.second);
			//while(!i->end && !less(k, i->_value.first) )
			while(!i->end && !less(k, i->_value) )
				i = i->parent;

			return i;
		}

		//Il successore di un nodo X ?? il pi?? piccolo nodo maggiore del sottalbero destro del nodo X
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

		void replace(pointer	original, pointer	replace)
		{
			if (original->parent != replace)
			{
				if (!replace->end)
					replace->parent = original->parent;
				if (!original->parent->end){
					if (original->parent->left == original)
						original->parent->left = replace;
					else
						original->parent->right = replace;
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

			// t ?? il nodo pi?? grande dell' albero 
			if (t == this->_end->parent){
				this->_end->parent = Prev(t);
			}
			deleteNode(t);
		}

		size_t	Remove(Pair target)
		{
			//std::cout << "remove" << std::endl;
			pointer	last;
			pointer	t = Search(_root, target, last);
			size_t n = 0;
			if (!t->end)
			{
				RbTreeDelete(t);
				n = 1;
			}

			return n;
		}

		pointer		begin() { return (_begin); }
		size_t		size() const { return (_size); }

		size_t PreOrder(pointer	nodo) {
			if (nodo != nullptr && !nodo->end) {
				return  std::max(PreOrder(nodo->left), PreOrder(nodo->right)) + 1;
			}
			return 0;
		}

		bool less(pointer &a, pointer &b) const{
			return (this->comp(a->_value, b->_value));
		}

		bool less(const typename value_compare::first_argument_type &a, const typename value_compare::first_argument_type &b) const{
			return (this->comp(a, b));
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
	template <class Pair, class value_compare, class key_compare>
	void swap( ft::Tree<Pair, value_compare, key_compare>& lhs, ft::Tree<Pair, value_compare, key_compare>& rhs )
	{
		lhs.swap(rhs);
	};
}

#endif