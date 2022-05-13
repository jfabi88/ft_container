#ifndef TREE_HPP
#define TREE_HPP

#include "pair.hpp"

namespace ft {

template < class Pair, class Compare >
bool is_less(typename Pair::first_type a, typename Pair::first_type b){
	Compare u;
	return u(a, b);
}

template < class Pair, class Compare = std::less< typename Pair::first_type> >
struct Node
{
	public:
		typedef typename 	Pair::first_type	Ktype;
		typedef typename	Pair::second_type	Vtype;
		Ktype									key;
		Vtype									value;
		Node									*parent;
		Node									*left;
		Node									*right;

		Node(const Ktype &k = Ktype(), const Vtype &v = Vtype() ) : key(k), value(v), parent(nullptr), left(nullptr), right(nullptr){};
		~Node(){};
		Node(const Pair &pair) : key(pair.first), value(pair.second), parent(nullptr), left(nullptr), right(nullptr){};

		bool    operator<(const Node &s) const
		{ 
			Compare u;
			return u(key, s.key);
		} 
};

template < class Pair>
std::ostream& operator<<(std::ostream& os, const Node<Pair>& n)
{
	//os << "(" << n.key << "," << n.value << ")";
	os << n.key;
	return os;
}


template <class Pair, class Compare = std::less< typename Pair::first_type> >
class Tree {
	public:
		typedef	Node<Pair, Compare>						NodeType;
		typedef	std::allocator< Node<Pair, Compare> >	allocator_type;
	private:
		NodeType 			*root;
		allocator_type  	allocator;

		NodeType *newNode(const NodeType &e){
			NodeType *node = allocator.allocate(1);
			allocator.construct(node, e);
			return node;
		}

		void	deleteNode( NodeType *t){
			allocator.destroy(t);
			allocator.deallocate(t, 1);
		}

	public:
		Tree() : root(nullptr) {};
		Tree(const NodeType &r){
			root = newNode(r);
		}

		Tree(const Pair &p){
			root = newNode(NodeType(p));
		}

		~Tree(){
			//destroyTree();
		};

		Tree   &operator=(const Tree &t) { root = t.root;  return (*this);}

		NodeType* getRoot() { return (root);}

		//NodeType* insert(const NodeType &e)
		NodeType* insert(const Pair &pair)
		{
			NodeType *node, *parent;

			NodeType *_new = newNode(pair);
			if (this->root == nullptr)
				this->root = _new;
			else{
				node = this->root;
				while (node != nullptr)
				{
					parent = node;
					if ( *_new < *node )
						node = node->left;
					else 
						node = node->right;
				}
				_new->parent = parent;
				if (*_new < *parent)
					parent->left = _new;
				else
					parent->right = _new;
			}
			
			return this->root;
		}

		NodeType* rInsert(NodeType *t, const NodeType &e)
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
		}


		NodeType *Search(NodeType *t, typename Pair::first_type target)
		{
			if ( t != nullptr ) {
				if (target == t->key)
					return t;
				//if (is_less(target, t->key))
				if (is_less< Pair,Compare>(target, t->key))
					return Search(t->left, target);
				return Search(t->right, target);
			}
			return nullptr;
		}

		//Il successore di un nodo X è il più piccolo nodo maggiore del nodo X
		NodeType *Successor(NodeType *x)
		{
			NodeType *t = x->right;
			while (t->left)
				t = t->left;
			return t;
		}

		// rimpiazza il nodo s con il nodo r
/* 		void replace(NodeType * &original, NodeType * &replace)
		{
			bool left = is_less<Pair,Compare>(original->key, original->parent->key);
			replace->left = original->left;
			replace->right = original->right;
			replace->parent = original->parent;

			if (left)
				replace->parent->left = replace;
			else
				replace->parent->right = replace;
		} */
		
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
			NodeType *t = Search(root, target);
			NodeType *s = nullptr;
			if (t)
			{
				//caso 1: t senza figli, caso 2: t con un solo figlio
				if (!t->left || !t->right)
				{					
					s = (t->left) ? t->left : t->right;
					if (t->parent)
					{
						if (is_less<Pair,Compare>(t->key, t->parent->key))
							t->parent->left = s;
						else
							t->parent->right = s;
					}
					if (s)
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
				if (t == root)
					root = s;				
				deleteNode(t);
			}
			return root;
		}

/* 		NodeType *Remove(typename Pair::first_type target)
		{
			NodeType *t = Search(root, target);
			NodeType *s;
			if (t)
			{
				//caso 1: t senza figli, caso 2: t con un solo figlio
				if (!t->left || !t->right)
				{
					NodeType *child = (t->left) ? t->left : t->right;
					if (t->parent)
					{
						if (is_less<Pair,Compare>(t->key, t->parent->key))
							t->parent->left = child;
						else
							t->parent->right = child;
					}
					if (child)
						child->parent = t->parent;
				}else if( (s = Successor(t)) == t->right){
					//caso 3a: t ha 2 figli e il figlio destro è il suo successore
					NodeType *tmp = s->right;
					replace(t, s);
					s->right = tmp;
					s->left->parent = s;
					if(t == root)
						root = s;
				}else{
					//caso 3b: t ha 2 figli e il suo successore si trova nell sottalbero(sinistro) del suo figlio destro
					//sostituisco il successore con il suo figlio destro
					s->parent->left = s->right;
					if (s->right)
						s->right->parent = s->parent;
					//sostituisco t con il successore s
					replace(t, s);
					if(t == root)
					root = s;
				}
				
				deleteNode(t);
			}
			return root;
		} */

		size_t PreOrder(NodeType *nodo) {
			if (nodo != NULL) {
				//visita(nodo);
				//std::cout << *nodo << std::endl;
				return  std::max(PreOrder(nodo->left), PreOrder(nodo->right)) + 1;
			}
			return 0;
		}


};

/* template <class Pair>
void prinTree(Tree<Pair> &tree) {


	if (nodo != NULL) {
		//visita(nodo);
		std::cout << *nodo << std::endl;
		PreOrder(nodo->left);
		PreOrder(nodo->right);
	}
} */


}

#endif
