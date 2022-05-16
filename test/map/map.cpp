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

std::cout << "STD:\n";
sit = smap.insert(sit , std::make_pair(1, "uno"));
std::cout << sit->first << "/" << (*sit).second << std::endl;
sit = smap.insert(sit, std::make_pair(2, "due"));
std::cout << sit->first << "/" << (*sit).second << std::endl;
sit = smap.begin();
std::cout << "begin = " << sit->first << "/" << (*sit).second << std::endl;
sit++;
std::cout << sit->first << "/" << (*sit).second << std::endl;

std::cout << "FT:\n";
it = map.insert(it , ft::make_pair(1, "uno"));
std::cout << it->first << "/" << (*it).second << std::endl;
it = map.insert(it, ft::make_pair(2, "due"));
std::cout << it->first << "/" << (*it).second << std::endl;
it = map.begin();
std::cout << "begin = " << it->first << "/" << (*it).second << std::endl;
it++;
std::cout << it->first << "/" << (*it).second << std::endl;



sit = smap.insert(smap.begin(), std::make_pair(9, "nove"));
smap.insert(sit, std::make_pair(8, "8"));
it = map.insert(map.begin(), ft::make_pair(9, "nove"));
map.insert(it, ft::make_pair(8, "8"));


ft::map<int, std::string> map2;
std::map<int, std::string> smap2;

std::map<int, std::string> smap2;

std::cout << "\nInsert Range\n";
smap2.insert(smap.begin(), sit);
for (sit = smap2.begin(); sit != smap2.end(); sit++){
    std::cout << sit->first << "/" << (*sit).second << std::endl;
}
}