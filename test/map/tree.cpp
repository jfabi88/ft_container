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
	//ft::Tree< ft::pair<std::string, int> > tree3(p);


}