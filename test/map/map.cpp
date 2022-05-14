#include <iostream>
#include <map>
#include "../../sources/map.hpp"
#include "mUtils.hpp"

int main(){

std::cout << "DAJE_1\n";
ft::map<int, std::string> map;
std::cout << "DAJE_2\n";
std::map<int, std::string> smap;

ft::map<int, std::string>::iterator it;
std::map<int, std::string>::iterator sit;

smap.insert(std::make_pair(0, "zero"));
map.insert(ft::make_pair(0, "zero"));

sit = smap.begin();
std::cout << sit->first << "/" << (*sit).second << std::endl;

it = map.begin();
std::cout << it->first << "/" << (*it).second << std::endl;

sit = smap.insert(sit , std::make_pair(1, "uno"));
sit = smap.insert(sit, std::make_pair(2, "due"));
sit = smap.begin();
sit++;
//it = map.insert(ft::make_pair(0, "zero"));

}