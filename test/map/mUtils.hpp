#include <iostream>
#include <map>
#include <vector>
#include "../../sources/tree.hpp"
#include "../../sources/vector.hpp"
#include <math.h>
#include <iomanip>
#define _KGRN  "\x1B[32m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define _RED   	"\033[31m" 


int nTreeH(int h)
{
	return (pow(2, h + 1) - 1);
}

template <class T>
void visitNode(T *node, std::map<int, std::vector< std::pair<int, T> > > &map, int n = 0, int h = 0)
{
	if (node == nullptr || node->end)
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

size_t calcSpace(size_t tot, size_t nSpace, size_t lenght)
{
	return (lenght - (tot * nSpace) ) / (tot + 1);
}

void printSpace(size_t n, char c = ' ')
{
	std::cout << std::string(n, c);
}


template <class Alloc, class Compare>
void prinTree(ft::Tree<Alloc, Compare> &tree)
{
	//typedef typename ft::Tree<P, Compare, A>::NodeType type;
	typedef typename ft::Tree<Alloc, Compare>::NodeType type;
	size_t h = tree.PreOrder(tree.getRoot());
	//size_t max = nTreeH(h);
	size_t lastN = pow(2, h);
	size_t nSpace = 4;
	size_t lenght = lastN * nSpace;

	//_map(int lvlTree, pair<int indiceNodo, nodo>)
	std::map<int, std::vector< std::pair<int, type> > > _map;
	typename std::map<int, std::vector< std::pair<int, type> > >::iterator itm;
	visitNode< type >(tree.getRoot(), _map);
	std::vector<int> v;
	
	int lVl = 0, last = 0, n = 0, color = 0, pcolor = 5;
						// 	green,	blue,	magenta,	yellow,		_RED,	white	
	const char* args[] = {"\033[32m", "\033[34m", "\033[35m", "\033[33m", "\033[31m", "\033[13m"};
 	std::vector<std::string> colors(args, args + 6);
 	//std::cout << "_map.size() = " << _map.size() << "\n";
	/*std::cout << "max = " << max << "\n";
	std::cout << "lastN = " << lastN << "\n";
	std::cout << "lenght = " << lenght << "\n"; */
	bool root;
	for(itm = _map.begin(); itm != _map.end(); itm++) 
	{
		//livello albero
		lVl = itm->first;
		std::vector< std::pair<int, type> > v = itm->second;
		size_t nOnThisLevel = pow(2, lVl);
		size_t qnt = calcSpace(nOnThisLevel, nSpace, lenght);
		std::string  value;
		
		typename std::vector< std::pair<int, type> >::iterator it = v.begin();
		
		for (size_t i = 0; i < nOnThisLevel; i++)
		{
			root = (lVl == 0 && i== 0);
			if (n == it->first){
				//se sono fratello destro(it->first % 2 == 0) ed è stato stampato il mio fratello sinistro (last == it->first-1)
				if ( (it->first % 2 == 0) && last == it->first-1)
					printSpace(qnt, '_');
				else
					printSpace(qnt);
				value = std::to_string(it->second._value.first);
				size_t s = nSpace - value.length() - 2;
				size_t l = s / 2;
				color = n % colors.size();
				pcolor = ((n-1) / 2)  % colors.size();
				bool left = (it->second._value.first < it->second.parent->_value.first);
				//bool left = (&it->second ==  it->second.parent->left);
				std::cout << std::string(s-l,' ') << colors.at(pcolor) << (left || root? "[" : "") << RESET
				<< colors.at(color) << value << RESET << (it->second.color? "r" : "b")
				<< colors.at(pcolor) << (!left || root? "]" : "") << RESET << std::string(l,' ');
				last = it->first;
				it++;
			}else{
				printSpace(qnt);
				value = "   ";
				size_t s = nSpace - value.length();
				size_t l = s / 2;
				std::cout << std::string(s-l,' ') << value << std::string(l,' ');
			}
			n++;
		}
		printSpace(qnt);
		std::cout << "\n";
	}
	
}