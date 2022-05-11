#include <iostream>
#include <map>
#include "../../sources/tree.hpp"
#include "../../sources/vector.hpp"
#include <math.h> 


/* template <class T , class N = typename ft::Tree<T>::NodeType >
void visitNode(N *node, std::map<int, N > &map, int n)
{
	map.at(n) = node;
	visitNode(node->left, map, n+1);
	visitNode(node->right, map, n+2);
} */

int nTreeH(int h)
{
	return (pow(2, h + 1) - 1);
}

template <class T>
void visitNode(T *node, std::map<int, T > &map, int n = 0, int h = 0)
{
	if (node == nullptr)
		return;
	
	map.insert(std::make_pair(n, *node));
	int a = 2*n + 1;
	visitNode(node->left, map, a, h + 1);
	visitNode(node->right, map, a+1, h + 1);
}

/* template <class T , class N = typename ft::Tree<T>::NodeType>
void prinTree(ft::Tree<T> &tree)
{
	std::map<int, N> map;
	typename std::map<int, N>::iterator itr;
	visitNode(tree.getRoot(), map, 0);
	for(itr = map.begin(); itr != map.end(); itr++) 
	{
		std::cout << itr->second << '\n';
	}
} */