#include <iostream>
#include <map>
#include <vector>
#include "../../sources/tree.hpp"
#include "../../sources/vector.hpp"
#include <math.h>
#include <iomanip>
#define KGRN  "\x1B[32m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED   	"\033[31m" 


int nTreeH(int h)
{
	return (pow(2, h + 1) - 1);
}

/* template <class T>
void visitNode(T *node, std::map<int, T > &map, int n = 0, int h = 0)
{
	if (node == nullptr)
		return;
	
	map.insert(std::make_pair(n, *node));
	int a = 2*n + 1;
	visitNode(node->left, map, a, h + 1);
	visitNode(node->right, map, a+1, h + 1);
} */

template <class T>
void visitNode(T *node, std::map<int, std::vector< std::pair<int, T> > > &map, int n = 0, int h = 0)
{
	if (node == nullptr)
		return;

	if ( map.find(h) == map.end() ) {
		std::vector< std::pair<int, T> > v;
		map.insert(std::make_pair(h, v));
	}

	map[h].push_back(std::make_pair(n, *node));
	int a = 2*n + 1;
	visitNode(node->left, map, a, h + 1);
	visitNode(node->right, map, a+1, h + 1);
}

/* template <class P>
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
} */

size_t calcSpace(size_t tot, size_t nSpace, size_t lenght)
{
	return (lenght - (tot * nSpace) ) / (tot + 1);
}

void printSpace(size_t n, char c = ' ')
{
	std::cout << std::string(n, c);
}


template <class P>
void prinTree(ft::Tree<P> &tree)
{
	typedef typename ft::Tree<P>::NodeType type;
	size_t h = tree.PreOrder(tree.getRoot());
	size_t max = nTreeH(h);
	size_t lastN = pow(2, h);
	size_t nSpace = 4;
	size_t lenght = lastN * nSpace;

	std::map<int, std::vector< std::pair<int, type> > > _map;
	visitNode< type >(tree.getRoot(), _map);

	std::vector<int> v;
	typename std::map<int, std::vector< std::pair<int, type> > >::iterator itm;

	int lVl = 0, last = 0, n = 0;
	
	std::cout << "_map.size() = " << _map.size() << "\n";
	std::cout << "max = " << max << "\n";
	std::cout << "lastN = " << lastN << "\n";
	std::cout << "lenght = " << lenght << "\n";

	for(itm = _map.begin(); itm != _map.end(); itm++) 
	{
		lVl = itm->first;
		std::vector< std::pair<int, type> > v = itm->second;
		size_t qnt = calcSpace(pow(2, lVl), nSpace, lenght);
		for( typename std::vector< std::pair<int, type> >::iterator it = v.begin(); it != v.end(); ) 
		{
			if (n == it->first){
				//se sono fratello destro(it->first % 2 == 0) ed è stato stampato il mio fratello sinistro (last == it->first-1)
				if ( (it->first % 2 == 0) && last == it->first-1)
					printSpace(qnt, '_');
				else
					printSpace(qnt);
				std::string  value =  std::to_string(it->second.key);
				size_t s = nSpace - value.length();
				size_t l = s / 2;
				std::cout << std::string(l,' ') << value << std::string(s-l,' ');
				last = it->first;
				it++;
			}else{
				printSpace(qnt);
				std::string(nSpace,' ');
			}
			n++;
		}
		printSpace(qnt);
		std::cout << "\n";
	}
	
}