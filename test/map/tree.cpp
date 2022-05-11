#include <iostream>
#include <map>
#include "../../sources/tree.hpp"
#include "mUtils.hpp"

int main(){

	ft::Tree< ft::pair<std::string, int> > tree;
	ft::Node< ft::pair<std::string, int> > a("a", 11);
	ft::Node< ft::pair<std::string, int> > b("b", 12);

	//std::boolalpha;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::boolalpha << (a < b) << std::endl;

	ft::Tree< ft::pair<std::string, int> > tree2(a);
	ft::pair<std::string, int> p("ciao", 5);
	std::pair<std::string, int> pstd("ciao", 5);
	ft::Tree< ft::pair<std::string, int> > tree3(p);

	ft::Node< ft::pair<std::string, int> > aCopy(a);
	std::cout << "copy of a: "<< aCopy << std::endl;
	std::cout << *tree3.getRoot() << std::endl;

	typedef ft::pair<int , std::string> pair;
	ft::Tree< pair > ciliegio;
	ft::Tree< pair > pero;
	ciliegio.insert(pair(20, "20"));
	ciliegio.insert(pair(50, "cinquanta"));
	ciliegio.insert(pair(43, "43"));
	ciliegio.insert(pair(39, "trenta9"));
	ciliegio.insert(pair(11, "11"));
	ciliegio.insert(pair(7, "sette"));
	ciliegio.insert(pair(15, "15"));
	ciliegio.insert(pair(9, "nove"));
	ciliegio.insert(pair(23, "23"));

	pero.rInsert(pero.getRoot(), pair(20, "20"));
	pero.rInsert(pero.getRoot(),pair(50, "cinquanta"));
	pero.rInsert(pero.getRoot(),pair(43, "43"));
	pero.rInsert(pero.getRoot(),pair(39, "trenta9"));
	pero.rInsert(pero.getRoot(),pair(11, "11"));
	pero.rInsert(pero.getRoot(),pair(7, "sette"));
	pero.rInsert(pero.getRoot(),pair(15, "15"));
	pero.rInsert(pero.getRoot(),pair(9, "nove"));
	
	std::cout << "ciliegio:" << std::endl;
	//ciliegio.PreOrder(ciliegio.getRoot());

	std::cout << std::endl << "pero:" << std::endl;
	//pero.PreOrder(pero.getRoot());

	//prinTree(ciliegio);
	//prinTree<pair>(ciliegio);
	std::cout << std::endl << " HEY " << std::endl;
	prinTree(ciliegio);
}
