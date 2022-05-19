#ifndef TREE_HPP
#define TREE_HPP

#define  BLACK	0
#define  RED	1
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

		bool    operator<(const Node &s) const
		{ 
			Compare u;
			return u(_value.first, s._value.first);
		}

		Ktype getFirst() { return _value.getFirst(); };
		Vtype getSecond() { return _value.getSecond(); };
};

template < class Pair, class Compare>
std::ostream& operator<<(std::ostream& os, const Node<Pair, Compare>& n)
{
	//os << "(" << n.key << "," << n.value << ")";
	os << n._value.first;
	//os << n.getFirst();
	return os;
}

/*	PROPRIETà ALBERO ROSSO-NERO (il cui mantenimento garantisce il bilanciamento)
	1) Ogni nodo ha colore rosso o nero.
	2) Il nodo root inizialmente è nero.
	3) Ogni foglia è nera e contiene elemento null;
	4) Entrambi i figli di ciascun nodo rosso sono neri;
	5) Ogni cammino da un nodo a una foglia nel suo sottoalbero contiene lo stesso numero di nodi neri.
*/
template <class Pair, class Compare = std::less< typename Pair::first_type> >
class Tree {
	public:
		typedef	Node<Pair, Compare>										NodeType;
		typedef	std::allocator< NodeType >								allocator_type;
		typedef typename std::allocator< NodeType >::reference  		reference;			
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer  						pointer;			
		typedef typename allocator_type::const_pointer  				const_pointer;
		pointer				_begin;						//jfabi: da mettere privati e fare
		pointer				_end;							//getBeign e getEnd
	private:
		pointer				_root;
		
		allocator_type  	_allocator;
		size_t				_size;

		pointer	newNode(const NodeType &e, bool end = false){
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

		pointer grandparent(pointer n) {
			return n->parent->parent;
		}

		pointer uncle(pointer n) {
			if (n->parent == grandparent(n)->left)
				return grandparent(n)->right;
			else
				return grandparent(n)->left;
		}	


		void rotate_left(pointer p){
			//std::cout << "rotate_left of " << *p << " _root == p ?" << (_root == p) << "\n";
			pointer rChild = p->right;
			p->right = rChild->left;
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
			}
		}

		void rotate_right(pointer p){
			//std::cout << "rotate_right of " << *p << " _root == p ?" << (_root == p) << "\n";
			pointer lChild = p->left;
			p->left = lChild->right;
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
				//_root->parent = _end;
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
				/* Here, n == n->parent->right && n->parent == grandparent(n)->right */
				rotate_left(grandparent(n));
			}
		}
	public:
		Tree() : _size(0) {
			this->_end = newNode(NodeType(), true);
			this->_begin = _end;
			this->_root = _begin;
			this->_root->parent = this->_end;
		};

		Tree(const Pair &p){
			this->_end = newNode(NodeType(), true);
			this->_end->end = true;
			this->_begin = _end;
			this->_root = _begin;
			this->_root->parent = this->_end;
			insert(this->_root, p);
		}

		~Tree(){
			destroyTree();
		};


		void	clear(pointer nodo)
		{
			if (nodo != nullptr && !nodo->end) {
				clear(nodo->left);
				clear(nodo->right);
				deleteNode(nodo);
			}
		}

		void	destroyTree()
		{
			clear(_root);
			deleteNode(_end);
		}

		Tree   &operator=(const Tree &t) { _root = t._root;  return (*this);}

		pointer & getRoot() { return (_root);}

		bool end(pointer & p){return (p == _end);}

		pointer insert(pointer node, const Pair &pair)
		{
			pointer parent, entry, tmp;

			entry = newNode(pair);
			parent = nullptr;

			while (!node->end)
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
				this->_root->parent = this->_end;
				_begin = _root;
			}

			entry->left = _end;
			entry->right = _end;
			_size++;
			insert_case1(entry);
			return entry;
		}

		pointer	Search(pointer	t, typename Pair::first_type &target)
		{
			//salvo in _end->parent l'ultimo nodo confrontato (per ottimizzare insert)
			if (!t->end) {
				_end->parent = t;
				if (target == t->_value.first)
					return t;
				if (is_less< Pair, Compare>(target, t->_value.first) )
					return Search(t->left, target);
				return Search(t->right, target);
			}
			
			return t;
		}

		//Il successore di un nodo X è il più piccolo nodo maggiore del sottalbero destro del nodo X
		pointer	Successor(pointer &x)
		{
			pointer t = x->right;
			while (!end(t->left))
				t = t->left;
			return t;
		}

		void	pNext(pointer &x) {
			std::cout << *x << "\n";
			pointer next = 	Next(x);
			if (!next->end)
				pNext(next);
		}

		pointer	Next(pointer &x) {
			//pointer	t = (!x->right->end) ? Successor(x) :  x->parent;
			pointer	t;
			if (!x->right->end)
				return Successor(x);
			t = x->parent;
			while (!t->end && *t < *x)
				t = t->parent;
			return t;
		}
	
		void replace(pointer	original, pointer	replace)
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

		pointer	Remove(typename Pair::first_type target)
		{
			pointer	t = Search(_root, target);
			pointer	s = _end;

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
					pointer	tmp = s->right;
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

};

template <class Pair, class Compare >
class tree_iterator
{
	public:
		typedef typename iterator_traits<Pair>::value_type				value_type;
		typedef	Node<value_type, Compare> NodeType;
		typedef typename std::allocator< NodeType >::pointer 			NodePointer;	   
		typedef typename iterator_traits<Pair>::iterator_category		iterator_category;
		
		typedef ptrdiff_t												difference_type;
		typedef typename iterator_traits<Pair>::pointer					pointer;
		typedef typename iterator_traits<Pair>::reference				reference;	
	private:
		NodePointer _ptr;
		NodePointer next_node(NodePointer x) {
			NodePointer t = x->right;
			if (!t->end)
			{
				while (!t->left->end)
					t = t->left;
			}
			else
			{
				t = x->parent;
				while (!t->end && *t < *x)
					t = t->parent;
			}
			return t;
		}
	public:
		tree_iterator() : _ptr(nullptr){}
		tree_iterator(NodePointer p) : _ptr(p){}

		reference   operator*() const   { return _ptr->_value; }
		pointer     operator->()        { return &_ptr->_value; }

		tree_iterator& operator++() {_ptr = next_node(_ptr); return *this; };
		tree_iterator operator++(int) {tree_iterator tmp = *this; _ptr = next_node(_ptr); return tmp; };
		template <class Key, class T, class Comp, class Alloc> friend class map;
		bool operator==(const tree_iterator &tri) { return (_ptr == tri._ptr); };
		bool operator!=(const tree_iterator &tri) { return (_ptr != tri._ptr); };
};

}

#endif
