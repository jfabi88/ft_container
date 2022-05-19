#include <iostream>
#include <map>
#include "../../sources/tree.hpp"
#include "../../sources/map.hpp"
#include "mUtils.hpp"

int main(){

	ft::Tree< ft::pair<std::string, int> > tree;
/* 	ft::Node< ft::pair<std::string, int> > a("a", 11);
	ft::Node< ft::pair<std::string, int> > b("b", 12);

	//std::boolalpha;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::boolalpha << (a < b) << std::endl; */

	//ft::Tree< ft::pair<std::string, int> > tree2(a);
	ft::pair<std::string, int> p("ciao", 5);
	std::pair<std::string, int> pstd("ciao", 5);
	ft::Tree< ft::pair<std::string, int> > tree3(p);
 
/* 	ft::Node< ft::pair<std::string, int> > aCopy(a);
	std::cout << "copy of a: "<< aCopy << std::endl; */
	//std::cout << *tree3.getRoot() << std::endl;

	typedef ft::pair<int , std::string> pair;
	typedef ft::map<int, std::string> MapType;
	typedef ft::Tree< MapType::value_type,  MapType::key_compare > TreeType;
	//ft::map<int, std::string>:: ciliegio;
	TreeType ciliegio;
	TreeType::pointer NodePointer;
	typedef TreeType::NodeType NodeType;

	ft::Tree< pair > pero;
	std::cout << "ciliegio(20):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(20, "20"));
	prinTree(ciliegio);

	std::cout << "ciliegio(50):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(50, "cinquanta"));
	prinTree(ciliegio);

	std::cout << "ciliegio(43):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(43, "43"));
	prinTree(ciliegio);

	std::cout << "ciliegio(39):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(39, "trenta9"));
	prinTree(ciliegio);

	std::cout << "ciliegio(11):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(11, "11"));
	prinTree(ciliegio);

	std::cout << "ciliegio(7):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(7, "sette"));
	prinTree(ciliegio);

	std::cout << "ciliegio(15):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(15, "15"));
	prinTree(ciliegio);


	std::cout << "ciliegio(23):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(23, "23"));
	prinTree(ciliegio);

	std::cout << "ciliegio(40):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(40, "quaranta"));
	prinTree(ciliegio);

	std::cout << "ciliegio(53):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(53, "53"));
	prinTree(ciliegio);

	std::cout << "ciliegio(8):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(8, "otto"));
	prinTree(ciliegio);

	std::cout << "ciliegio(10):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(10, "dieci"));
	prinTree(ciliegio);
	
	std::cout << "ciliegio:" << std::endl;
	//ciliegio.PreOrder(ciliegio.getRoot());
	prinTree(ciliegio);
	NodeType *tmp = ciliegio.begin();
	for (int i = 0; i < ciliegio.size() - 1; i++)
	{
		std::cout << *tmp << std::endl;
		tmp = ciliegio.Next(tmp);
	}
	std::cout << *tmp << std::endl;
/*
	//NodeType *t = ciliegio.Search(ciliegio.getRoot(), 15);
	ciliegio.Remove(15);
	std::cout << std::endl << "remove 15:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(7);
	std::cout << std::endl << "remove 7:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(9);
	std::cout << std::endl << "remove 9:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(39);
	std::cout << std::endl << "remove 39:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(20);
	std::cout << std::endl << "remove 20 [Root]:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(43);
	std::cout << std::endl << "remove 43:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(11);
	std::cout << std::endl << "remove 11:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(10);
	std::cout << std::endl << "remove 10:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(50);
	std::cout << std::endl << "remove 50:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(23);
	std::cout << std::endl << "remove 23 [Root]:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(40);
	std::cout << std::endl << "remove 40 [Root]:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(53);
	std::cout << std::endl << "remove 53 [Root]:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(8);
	std::cout << std::endl << "remove 8:" << std::endl;
	prinTree(ciliegio);

	ciliegio.Remove(8);
	std::cout << std::endl << "remove 8:" << std::endl;
	prinTree(ciliegio);


	ciliegio.insert(pair(77, "77"));
	std::cout << std::endl << "insert 77:" << std::endl;
	prinTree(ciliegio);*/
}
