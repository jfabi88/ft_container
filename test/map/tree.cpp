#include <iostream>
#include <map>
#include "../../sources/tree.hpp"
#include "../../sources/map.hpp"
#include "mUtils.hpp"

int main(){

	typedef ft::pair<int , std::string> pair;
	typedef ft::map<int, std::string> MapType;
	typedef  MapType::TreeType	TreeType;
	typedef TreeType::pointer NodePointer;
	TreeType ciliegio;
	ft::map<int, std::string, std::plus<int> >::TreeType pero;
	std::map<int, std::string, std::plus<int> > melo;
	ft::map<int, std::string, std::plus<int> >  cedro;

	std::cout << "ciliegio(20):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(20, "20"));
	pero.insert(pero.getRoot(),pair(20, "20"));
	melo.insert(std::make_pair<int, std::string>(20, "20"));
	cedro.insert(ft::make_pair<int, std::string>(20, "20"));
	//prinTree(ciliegio);

	std::cout << "ciliegio(50):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(50, "cinquanta"));
	pero.insert(pero.getRoot(),pair(50, "cinquanta"));
	melo.insert(std::make_pair<int, std::string>(50, "cinquanta"));
	cedro.insert(ft::make_pair<int, std::string>(50, "cinquanta"));
	//prinTree(ciliegio);

	std::cout << "ciliegio(43):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(43, "43"));
	pero.insert(pero.getRoot(),pair(43, "43"));
	melo.insert(std::make_pair<int, std::string>(43, "43"));
	cedro.insert(ft::make_pair<int, std::string>(43, "43"));
	//prinTree(ciliegio);

	std::cout << "ciliegio(39):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(39, "trenta9"));
	pero.insert(pero.getRoot(),pair(39, "trenta9"));
	melo.insert(std::make_pair<int, std::string>(39, "trenta9"));
	cedro.insert(ft::make_pair<int, std::string>(39, "trenta9"));
	//prinTree(ciliegio);

	std::cout << "ciliegio(11):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(11, "11"));
	pero.insert(pero.getRoot(),pair(11, "11"));
	melo.insert(std::make_pair<int, std::string>(11, "11"));
	cedro.insert(ft::make_pair<int, std::string>(11, "11"));
	//prinTree(ciliegio);

	std::cout << "ciliegio(7):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(7, "sette"));
	pero.insert(pero.getRoot(),pair(7, "sette"));
	melo.insert(std::make_pair<int, std::string>(7, "sette"));
	cedro.insert(ft::make_pair<int, std::string>(7, "sette"));
	//prinTree(ciliegio);

	std::cout << "ciliegio(15):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(15, "15"));
	pero.insert(pero.getRoot(),pair(15, "15"));
	melo.insert(std::make_pair<int, std::string>(15, "15"));
	cedro.insert(ft::make_pair<int, std::string>(15, "15"));
	//prinTree(ciliegio);


	std::cout << "ciliegio(23):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(23, "23"));
	//prinTree(ciliegio);

	std::cout << "ciliegio(40):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(40, "quaranta"));
	//prinTree(ciliegio);

	std::cout << "ciliegio(53):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(53, "53"));
	//prinTree(ciliegio);

	std::cout << "ciliegio(8):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(8, "otto"));
	//prinTree(ciliegio);

	std::cout << "ciliegio(10):" << std::endl;
	ciliegio.insert(ciliegio.getRoot(),pair(10, "dieci"));
	//prinTree(ciliegio);
	
	std::cout << "ciliegio:" << std::endl;
	prinTree(ciliegio);


	NodePointer pt = ciliegio.begin();
	for (int i = 0; i < ciliegio.size(); i++)
	{
		std::cout << *pt << std::endl;
		pt = ciliegio.Next(pt);
	}

	std::cout << "pero:" << std::endl;
	prinTree(pero);

	ft::map<int, std::string, std::plus<int> >::TreeType::pointer pp = pero.begin();
	for (int i = 0; i < pero.size(); i++)
	{
		std::cout << *pp << std::endl;
		pp = pero.Next(pp);
	}

	std::cout << "\nmelo:" << std::endl;
	for(std::map<int, std::string, std::plus<int> >::iterator sit = melo.begin(); sit != melo.end(); sit++){
		std::cout << sit->first << std::endl;
	}

	std::cout << "\ncedro:" << std::endl;
	for(ft::map<int, std::string, std::plus<int> >::iterator it = cedro.begin(); it != cedro.end(); it++){
		std::cout << it->first << std::endl;
	}

	std::map<int, std::string, std::plus<int> >::iterator ciao;
}
