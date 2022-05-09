#ifndef TREE_HPP
#define TREE_HPP

#include "pair.hpp"
namespace ft {

	template < class K, class T, class Compare = std::less<K> >
	struct Node
	{
		typedef ft::pair<K, T>	value_type;
		value_type 				value;
		Node					*parent;
		Node					*left;
		Node					*right;

		Node() : parent(nullptr), left(nullptr), right(nullptr), value(value_type()) {};
		Node(const K &k, const T &t) : value(ft::pair<K,T>(k, t)), parent(nullptr), left(nullptr), right(nullptr){};
		~Node(){};
		Node(const value_type &v) : value(v), parent(nullptr), left(nullptr), right(nullptr) {};
		Node(const value_type &v, Node *p) : value(v), parent(p), left(nullptr), right(nullptr){};
		Node(const value_type &v, Node *p, Node* l, Node* r) : value(v), parent(p), left(l), right(r){};

/* 		std::ostream& operator<<(std::ostream& os, const Node& n)
		{
			os << "(" << n.value.first << "," << n.value.second << ")";
    		return os;
		} */

		bool    operator<(const Node &s)    
		{ 
			Compare u;
			return u(value, s.value);
		} 
	};

	template <class K, class T, class Compare = std::less<T> >
	class Tree {
		public:
			typedef ft::pair<K, T>	pair_type;
			Tree() : root(nullptr) {};
			Tree(Node<K,T> *r) : root(r) {};
			~Tree(){};
		private:
			Node<K, T, Compare> *root;
	};


}

#endif