#ifndef TREE_HPP
#define TREE_HPP

#include "pair.hpp"
namespace ft {

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

		//Node() : parent(nullptr), left(nullptr), right(nullptr), key(Ktype()), value(Vtype()) {};
		Node(const Ktype &k = Ktype(), const Vtype &v = Vtype() ) : key(k), value(v), parent(nullptr), left(nullptr), right(nullptr){};
		//Node(const Ktype &k = Ktype(), const Vtype &v) : key(k), value(v), parent(nullptr), left(nullptr), right(nullptr){};
		~Node(){};
		//Node(const Vtype &v) : value(v), parent(nullptr), left(nullptr), right(nullptr) {};
		//Node(const Vtype &v, Node *p) : value(v), parent(p), left(nullptr), right(nullptr){};
		//Node(const Vtype &v, Node *p, Node* l, Node* r) : value(v), parent(p), left(l), right(r){};
		Node(const Pair &pair) : key(pair.first), value(pair.second), parent(nullptr), left(nullptr), right(nullptr){};
/* 		Node(Pair &pair) {

		}; */

		bool    operator<(const Node &s)    
		{ 
			Compare u;
			return u(key, s.key);
		} 
};

template < class Pair>
std::ostream& operator<<(std::ostream& os, const Node<Pair>& n)
{
	os << "(" << n.key << "," << n.value << ")";
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
	public:
		Tree() : root(nullptr) {};
		Tree(const NodeType &r){
			root = allocator.allocate(1);
			allocator.construct(root, r);
		}

		Tree(const Pair &p){
			root = allocator.allocate(1);
			allocator.construct(root, NodeType(p));
		}

		~Tree(){
			//destroyTree();
		};

		Tree   &operator=(const Tree &t) { root = t.root;  return (*this);}

		NodeType* getRoot() { return (root);}

		NodeType& insert(const Pair &e)
		{
			NodeType *t = root, *p = nullptr;

			while (t != NULL){
				p = t;
				if ( e < *t )
					t = t->left;
				else 
					t = t->right;
			}
			if (p == nullptr){
				root = Tree(e);
			}else{
				if (e < *p)
					p->left = NodeType(e);
				else
					p->right = NodeType(e);
			}
			
			return this->root;
		}
};


}

#endif