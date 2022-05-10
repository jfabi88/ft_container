#include <iostream>
#include <map>
#include "../../sources/tree.hpp"

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
	ft::Tree< pair > albero;
	ft::Tree< pair > albero2;
	albero.insert(pair(20, "20"));
	albero.insert(pair(50, "cinquanta"));
	albero.insert(pair(43, "43"));
	albero.insert(pair(39, "trenta9"));
	albero.insert(pair(11, "11"));
	albero.insert(pair(7, "sette"));
	albero.insert(pair(15, "15"));
	albero.insert(pair(9, "nove"));

	albero2.rInsert(albero2.getRoot(), pair(20, "20"));
	albero2.rInsert(albero2.getRoot(),pair(50, "cinquanta"));
	albero2.rInsert(albero2.getRoot(),pair(43, "43"));
	albero2.rInsert(albero2.getRoot(),pair(39, "trenta9"));
	albero2.rInsert(albero2.getRoot(),pair(11, "11"));
	albero2.rInsert(albero2.getRoot(),pair(7, "sette"));
	albero2.rInsert(albero2.getRoot(),pair(15, "15"));
	albero2.rInsert(albero2.getRoot(),pair(9, "nove"));

	std::cout << "Albero 'albero'" << std::endl;
	albero.PreOrder(albero.getRoot());

	std::cout << "Albero 'albero2'" << std::endl;
	albero2.PreOrder(albero2.getRoot());

}
