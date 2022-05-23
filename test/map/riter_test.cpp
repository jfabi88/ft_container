#include "../../sources/map.hpp"
#include <iostream>
#include <map>
#include "mUtils.hpp"

int main()
{
   std::map<int, int>   m;
   std::map<int, int>::reverse_iterator riter;

	for (int i = 1; i < 10; i++)
		m.insert(std::make_pair(i, i + 1));

	for (std::map<int, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
		std::cout << iter->first << " " << iter->second << std::endl;

	std::map<int, int>::iterator it = m.begin();
	std::cout << "BEGIN= " << it->first << " " << it->second << std::endl;

	std::map<int, int>::iterator it1 = m.end();
	std::cout << "END= " << it1->first << " " << it1->second << std::endl;

	ft::map<int, int>   ftm;
   	ft::map<int, int>::reverse_iterator ftiter;

	for (int i = 1; i < 10; i++)
		ftm.insert(ft::make_pair(i, i + 1));

	for (ft::map<int, int>::iterator iter = ftm.begin(); iter != ftm.end(); ++iter)
		std::cout << iter->first << " " << iter->second << std::endl;

	ft::map<int, int>::iterator ftit = ftm.begin();
	std::cout << "BEGIN= " << ftit->first << " " << ftit->second << std::endl;

	ft::map<int, int>::iterator ftit1 = ftm.end();
	std::cout << "END= " << ftit1->first << " " << ftit1->second << std::endl;

	std::cout << "RBEGIN KEY = " <<  m.rbegin()->first << std::endl;
	std::cout << "FT::RBEGIN KEY = " <<  ftm.rbegin()->first << std::endl;

}