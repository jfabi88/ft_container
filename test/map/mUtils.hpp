#include <iostream>
#include <map>
#include <vector>
#include "../../sources/tree.hpp"
#include "../../sources/vector.hpp"
#include <math.h>
#define KGRN  "\x1B[32m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED   	"\033[31m" 

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

template <class P>
void prinTree(ft::Tree<P> &tree)
{
	typedef typename ft::Tree<P>::NodeType type;

	std::map<int, type > _map;
	visitNode< type >(tree.getRoot(), _map, 0);

	std::vector<int> v;
	typename std::map<int, type >::iterator itr;
	int h = 0, n = 0;
	std::vector<int>::iterator it;
	for(itr = _map.begin(); itr != _map.end(); ) 
	{
		it = std::find(v.begin(), v.end(), n);
		if (n == itr->first){
			if (it != v.end())
				v.erase(it);
			int p = 2*n + 1;
			v.push_back(p); v.push_back(p+1);
			std::cout << itr->first << ") "  << GREEN << itr->second << RESET << " ";
			itr++;
		}else if(it != v.end()){
			std::cout << n << ") " << RED << "x " << RESET;
			v.erase(it);
		}
		if (n == nTreeH(h) - 1){
			std::cout << "\n";
			h++;
		}
		n++;
	}
	std::cout << "\n";
}