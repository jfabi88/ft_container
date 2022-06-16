#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <vector>
#include <set>
#include "../sources/map.hpp"
#include "../sources/stack.hpp"
#include "../sources/vector.hpp"
#include "../sources/set.hpp"
#include "./mUtils.hpp"
#include<ctime>
#include <sys/time.h>
#include<cstdlib>

# define RESET			"\033[0m"
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */
# define ROJO			"\033[31m"

volatile static time_t s_start;
volatile static time_t f_start;
volatile static time_t s_end;
volatile static time_t f_end;

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

void emptyLine()
{
    std::cout << std::endl;
}

/* Vector */
template <class T>
void print_vector(std::vector<T> &vector, int opt = 1)
{
    if (opt <= 2){
        std::cout << std::endl;
        std::cout << BLUE << "std::Vector" << RESET << std::endl;
        std::cout << "[ "; 
        for(size_t i = 0; i < vector.size(); i++)
            std::cout << GREEN << vector.at(i) << RESET << ", ";
        std::cout << ']' << std::endl;
        std::cout << "STD::Vector Size: " << CYAN << vector.size() << RESET << std::endl;
        std::cout << "STD::Vector Capacity: " << CYAN << vector.capacity() << RESET << std::endl;
    }
    if (opt >= 2){
	    time_t t1 = s_end - s_start;
        std::cout << "STD TIME: " << CYAN <<  std::to_string(t1)  << RESET <<  "ms" << std::endl;
    }

}

template <class T>
void print_vector(ft::vector<T> &vector, int opt = 1)
{
     if (opt <= 2){
        std::cout << std::endl;
        std::cout << BLUE << "Ft::Vector" << RESET << std::endl;
        std::cout << "[ "; 
        for(size_t i = 0; i < vector.size(); i++)
            std::cout << GREEN << vector.at(i) << RESET << ", ";
        std::cout << ']' << std::endl;
        std::cout << "FT::Vector Size: " << CYAN << vector.size() << RESET << std::endl;
        std::cout << "FT::Vector Capacity: " << CYAN << vector.capacity() << RESET << std::endl;
    }
    if (opt >= 2){
         time_t t1 = f_end - f_start;
        std::cout << "FT TIME: " << CYAN <<  std::to_string(t1)  << RESET <<  "ms" << std::endl;
    }
}
void printTimes(){
	time_t t1 = s_end - s_start;
    time_t t2 = f_end - f_start;

    std::cout << "STD TIME ms vs FT TIME ms: ";
    if (t1 >= t2){
        std::cout << ROJO <<  std::to_string(t1)  << RESET <<  " vs " << GREEN <<  std::to_string(t2)  << RESET <<  std::endl;
    }else{
        std::cout << GREEN <<  std::to_string(t1)  << RESET <<  " vs " << ROJO <<  std::to_string(t2)  << RESET  <<  std::endl;
    }
}
/* Stack */

template <class T>
void isEmpty(std::stack<T> &stack)
{
    stack.empty() ? std::cout << ROJO << "std::Stack is empty" << RESET << std::endl : std::cout << GREEN << "std::Stack is not empty." << RESET << std::endl ;
}

template <class T>
void isEmpty(ft::stack<T> &stack)
{
    stack.empty() ? std::cout << ROJO << "ft::Stack is empty" << RESET << std::endl : std::cout << GREEN << "ft::Stack is not empty." << RESET << std::endl ;
}

/* --- Map -- */

template <class T, class U>
void isEmpty(std::map<T, U> &map)
{
    map.empty() ? std::cout << ROJO << "std::Map is empty" << RESET << std::endl : std::cout << GREEN << "std::Map is not empty." << RESET << std::endl ;
}

template <class T, class U>
void isEmpty(ft::map<T, U> &map)
{
    map.empty() ? std::cout << ROJO << "ft::Map is empty" << RESET << std::endl : std::cout << GREEN << "ft::Map is not empty." << RESET << std::endl ;
}

template <class T, class U>
void printMapInfo(std::map<T, U> &map)
{
    isEmpty(map);
    std::cout << "std::Map size: " << map.size() << '\n';
    std::cout << "std::Map max_size: " << map.max_size() << '\n';
}

template <class T, class U>
void printMapInfo(ft::map<T, U> &map)
{
    isEmpty(map);
    std::cout << "std::Map size: " << map.size() << '\n';
    std::cout << "std::Map max_size: " << map.max_size() << '\n';
}

template <class T, class U>
void printMapValues(std::map<T, U> &map)
{
    std::map<int, std::string>::iterator it;
    std::cout << CYAN << "std::Map contains:\n" << RESET;
    for (it=map.begin(); it!=map.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

template <class T, class U>
void printMapValues(ft::map<T, U> &map)
{
    ft::map<int, std::string>::iterator it;
    std::cout << CYAN << "ft::Map contains:\n" << RESET;
    for (it=map.begin(); it!=map.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

void populateMap(std::map<int, std::string> &map, int seed, int qnt = 10)
{
    std::cout << std::endl;
    std::cout << "Populating std::map... " << std::to_string(qnt) << " elements" << std::endl;
    for(int i = seed; i < seed + qnt; i++)
        map.insert(std::make_pair(i, std::to_string(i)));
    std::cout << std::endl;  
}

void populateMap(ft::map<int, std::string> &map, int seed, int qnt = 10)
{
    std::cout << std::endl;
    std::cout << "Populating ft::map... " << std::to_string(qnt) << " elements" << std::endl;
    for(int i = seed; i < seed + qnt; i++)
        map.insert(ft::make_pair(i, std::to_string(i)));
    std::cout << std::endl;  
}

void populateSet(std::set<int> &map, int seed, int qnt = 10)
{
    std::cout << std::endl;
    std::cout << "Populating std::set... " << std::to_string(qnt) << " elements" << std::endl;
    for(int i = seed; i < seed + qnt; i++)
        map.insert(i);
    std::cout << std::endl;  
}

void populateSet(ft::set<int> &map, int seed, int qnt = 10)
{
    std::cout << std::endl;
    std::cout << "Populating ft::set... " << std::to_string(qnt) << " elements" << std::endl;
    for(int i = seed; i < seed + qnt; i++)
        map.insert(i);
    std::cout << std::endl;  
}

int main(int ac, char**av)
{
    if (ac != 2)
	{
		std::cerr << "Usage: ./program seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		return 1;
	}
	const int seed = atoi(av[1]);
	srand(seed);
    int x = rand();

    std::vector<int> sv(x, x);
    ft::vector<int> fv(x, x);

    std::vector<int> stv(x, x);
    ft::vector<int> ftv(x, x);

    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << MAGENTA << "                                          VECTOR                                           " << RESET << "|" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;

    std::cout << MAGENTA << "CAPACITY" << RESET << std::endl;
    std::cout << YELLOW << "size()" << RESET << std::endl;   std::cout << "Std: " << sv.size() << std::endl;  std::cout << "Ft: " << fv.size() << std::endl;
    std::cout << YELLOW << "max_size()"  RESET << std::endl;   std::cout << "Std: " << sv.max_size() << std::endl;  std::cout << "Ft: " << fv.max_size() << std::endl;
    std::cout << YELLOW << "capacity()"  RESET << std::endl;   std::cout << "Std: " << sv.capacity() << std::endl;  std::cout << "Ft: " << fv.capacity() << std::endl;
    std::cout << YELLOW << "empty()"  RESET << std::endl;   std::cout << "Std: " << sv.empty() << std::endl;  std::cout << "Ft: " << fv.empty() << std::endl;
    std::cout << YELLOW << "resize()"  RESET << std::endl;   std::cout << "Std actual size: " << sv.size() << std::endl;  std::cout << "Ft actual size: " << fv.size() << std::endl;
    sv.resize(x/2);
    fv.resize(x/2);
    std::cout << YELLOW << "resize()"  RESET << std::endl;   std::cout << "Std new size: " << sv.size() << std::endl;  std::cout << "Ft new size: " << fv.size() << std::endl;
    std::cout << YELLOW << "resize()"  RESET << std::endl;   std::cout << "Std capacity: " << sv.capacity() << std::endl;  std::cout << "Ft capacity: " << fv.capacity() << std::endl;

    std::cout << YELLOW << "reserve()"  RESET << std::endl;   
    std::cout << "Actual std capacity: " << sv.capacity() << std::endl;  std::cout << "Actual std size: " << sv.size() << std::endl;
    std::cout << "Actual ft capacity: " <<  fv.capacity() << std::endl;  std::cout << "Actual ft size: " << fv.size() << std::endl;
    std::cout << CYAN << "reserve(x+(x/2))"  RESET << std::endl; 
    sv.reserve(x+(x/2));
    fv.reserve(x+(x/2));
    std::cout << "New std capacity: " << sv.capacity() << std::endl;  std::cout << "New std size: " << sv.size() << std::endl;
    std::cout << "New ft capacity: " << fv.capacity() << std::endl;  std::cout << "New ft size: " << fv.size() << std::endl;
    
    std::cout << std::endl;
    std::cout << MAGENTA << "MODIFIERS" << RESET << std::endl;
    std::cout << YELLOW << "assign(10, seed)"  RESET << std::endl;
    sv.assign(10, seed);
    fv.assign(10, seed);
    print_vector(sv);
    print_vector(fv);
    emptyLine();

    std::cout << YELLOW << "assign(1000000, seed)"  RESET << std::endl;
    s_start = timer();
    stv.assign(1000000, seed);
    s_end = timer();
    f_start = timer();
    ftv.assign(1000000, seed);
    f_end = timer();
    print_vector(stv, 3);
    print_vector(ftv, 3);
    emptyLine();

    std::cout << YELLOW << "push_back(1111)"  RESET << std::endl;
    sv.push_back(1111);
    fv.push_back(1111);
    print_vector(sv);
    print_vector(fv);
    emptyLine();

    std::cout << YELLOW << "pop_back()"  RESET << std::endl;
    sv.pop_back();
    fv.pop_back();
    print_vector(sv);
    print_vector(fv);
    emptyLine();

    std::cout << YELLOW << "clear()"  RESET << std::endl;
    fv.clear();
    sv.clear();
    std::cout << "Std size: " << sv.size() << std::endl;  std::cout << "Ft size: " << fv.size() << std::endl;
    std::cout << "Std capacity: " << sv.capacity() << std::endl;  std::cout << "Ft capacity: " << fv.capacity() << std::endl;
    emptyLine();

    std::cout << YELLOW << "clear()"  RESET << std::endl;
    s_start = timer(); stv.clear(); s_end = timer();
    f_start = timer(); ftv.clear(); f_end = timer();
    print_vector(stv, 3);
    print_vector(ftv, 3);
    emptyLine();

    std::cout << YELLOW << "insert(vector.begin(), 10, " + std::to_string(seed+1) << ")" << RESET << std::endl;
    sv.insert(sv.begin(), 10, seed + 1);
    fv.insert(fv.begin(), 10, seed + 1);
    print_vector(sv);
    print_vector(fv);
    emptyLine();

    std::cout << YELLOW << "insert(vector.begin(), 10000, " + std::to_string(seed+1) << ")" << RESET << std::endl;
    stv.insert(sv.begin(), 10000, seed + 1);
    ftv.insert(fv.begin(), 10000, seed + 1);
    print_vector(stv, 3);
    print_vector(ftv, 3);
    emptyLine();

    std::cout << YELLOW << "erase(vector.begin(), vector.begin()+ 3)"  RESET << std::endl;
    sv.erase(sv.begin(), sv.begin()+ 3);
    fv.erase(fv.begin(), fv.begin()+ 3);
    print_vector(sv);
    print_vector(fv);
    emptyLine();

    std::cout << YELLOW << "erase(vector.begin(), vector.end())"  RESET << std::endl;
    stv.erase(stv.begin(), stv.end());
    ftv.erase(ftv.begin(), ftv.end());
    print_vector(stv, 3);
    print_vector(ftv, 3);
    emptyLine();

    std::cout << MAGENTA << "ELEMENT ACCESS" << RESET << std::endl;
    std::cout << YELLOW << "operator[]"  RESET << std::endl;
    std::cout << "std:vector[0]: " << CYAN << sv[0] << RESET << std::endl;
    std::cout << "ft:vector[0]: " << CYAN << fv[0] << RESET << std::endl;
    std::cout << YELLOW << "at()"  RESET << std::endl;
    std::cout << "std:vector.at(): " << CYAN << sv.at(0) << RESET << std::endl;
    std::cout << "ft:vector.at(): " << CYAN << fv.at(0) << RESET << std::endl;
    std::cout << YELLOW << "front()"  RESET << std::endl;
    std::cout << "std:vector.front(): " << CYAN << sv.front() << RESET << std::endl;
    std::cout << "ft:vector.front(): " << CYAN << fv.front() << RESET << std::endl;
    emptyLine();

    std::cout << YELLOW << "back()"  RESET << std::endl;
    std::cout << YELLOW << "a little push_back first...42"  RESET;
    sv.push_back(42);
    fv.push_back(42);
    print_vector(sv);
    print_vector(fv);
    std::cout << "std:vector.back(): " << sv.back() << std::endl;
    std::cout << "ft:vector.back(): " << fv.back() << std::endl;


    emptyLine();
    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << MAGENTA << "                                          STACK                                            " << RESET << "|" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
    emptyLine();


    std::stack<int> sStack;
    ft::stack<int>  fStack;

    std::cout << MAGENTA << "Costructor" << RESET <<  std::endl;
    std::stack<int,std::vector<int> > sSuperStack (sv);     
    ft::stack<int,ft::vector<int> > fSuperStack (fv);
    sSuperStack.push(seed * 2);
    fSuperStack.push(seed * 2);
    std::cout << sSuperStack.top() << std::endl;
    std::cout << fSuperStack.top() << std::endl;

    isEmpty(sStack);
    isEmpty(fStack);
    std::cout << YELLOW << "push(const value_type& val)"  RESET << std::endl; 
    sStack.push(seed);
    fStack.push(seed);
    std::cout << YELLOW << "top()"  RESET << std::endl; 
    std::cout << sStack.top() << std::endl;
    std::cout << fStack.top() << std::endl;
    std::cout << YELLOW << "push(const value_type& val)"  RESET << std::endl; 
    sStack.push(seed+1);
    fStack.push(seed+1);
    std::cout << YELLOW << "top()"  RESET << std::endl; 
    std::cout << sStack.top() << std::endl;
    std::cout << fStack.top() << std::endl;
    std::cout << CYAN << "std::stack size: " << sStack.size() << RESET << std::endl;
    std::cout << CYAN << "ft::stack size:  " << fStack.size() << RESET <<  std::endl;
    isEmpty(sStack);
    isEmpty(fStack);
    std::cout << YELLOW << "pop()"  RESET << std::endl; 
    sStack.pop();
    fStack.pop();
    std::cout << YELLOW << "top()"  RESET << std::endl; 
    std::cout << sStack.top() << std::endl;
    std::cout << fStack.top() << std::endl;
    std::cout << YELLOW << "pop()"  RESET << std::endl; 
    sStack.pop();
    fStack.pop();
    isEmpty(sStack);
    isEmpty(fStack);


    emptyLine();
    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << MAGENTA << "                                          MAP                                              " << RESET << "|" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;

    std::map<int, std::string> smap;
	ft::map<int, std::string> fmap;
    std::map<int, std::string> stmap;
	ft::map<int, std::string> ftmap;
	ft::map<int, std::string>::iterator fit;
	std::map<int, std::string>::iterator sit;

    populateMap(smap, seed);
    populateMap(fmap, seed);
    sit = smap.begin();
    fit = fmap.begin();
    printMapValues(smap);
    printMapValues(fmap);
    emptyLine();

    //TEMPISTICHE
    s_start = timer();  populateMap(stmap, seed, 100000); s_end = timer();
    f_start = timer();  populateMap(ftmap, seed, 100000); f_end = timer();
    printTimes();

    std::cout << MAGENTA << "CAPACITY" << RESET << std::endl;
    printMapInfo(smap);
    printMapInfo(fmap);

    emptyLine();
    std::cout << MAGENTA << "ELEMENT ACCESS" << RESET << std::endl;
    std::cout << YELLOW << "operator[] (const key_type& k) - map[seed+3]"  RESET << std::endl;
    std::cout << "result: " CYAN << smap[seed + 3] << RESET << std::endl;
    std::cout << "result: " CYAN << fmap[seed + 3] << RESET << std::endl;
    
    emptyLine();
    std::cout << MAGENTA << "MODIFIERS" << RESET << std::endl;
    std::cout << YELLOW << "insert(const value_type& val) - std::make_pair(x, 'fortytwo')"  RESET << std::endl;    
    smap.insert(std::make_pair(x, "fortytwo"));
    fmap.insert(ft::make_pair(x, "fortytwo"));
    printMapValues(smap);
    printMapValues(fmap);
    std::cout << std::endl;
    std::cout << YELLOW << "erase(const key_type& k) - map.erase(seed + 2)" << RESET << std::endl;
    smap.erase(seed + 2);
    fmap.erase(seed + 2);
    printMapValues(smap);
    printMapValues(fmap);
    std::cout << std::endl;
    std::cout << YELLOW << "erase(iterator position) - erase(map.begin());" << RESET << std::endl; 
    smap.erase(sit);
    fmap.erase(fit);
    printMapValues(smap);
    printMapValues(fmap);
    std::cout << std::endl;
    std::cout << YELLOW << "erase(iterator first, iterator last) - erase(it -> 15 , it -> 17)" << RESET << std::endl;
    sit=smap.find(15);
	std::map<int, std::string>::iterator sit2 = smap.find(17);
    fit=fmap.find(15);
    ft::map<int, std::string>::iterator fit2 = fmap.find(17);     
    smap.erase(sit, sit2);
    fmap.erase(fit, fit2);
    printMapValues(smap);
    printMapValues(fmap);

    std::cout << std::endl;
    std::cout << YELLOW << "swap(map& x)" << RESET << std::endl;
    std::map<int, std::string> smap2;
    populateMap(smap2, seed *2);
    ft::map<int, std::string> fmap2;
    populateMap(fmap2, seed *2);

    std::cout << BLUE << "Original STD values" << RESET << std::endl;
    std::cout << YELLOW << "smap: " << RESET;
    printMapValues(smap);
    std::cout << YELLOW << "smap2: " << RESET;
    printMapValues(smap2);
    smap.swap(smap2);
    std::cout << BLUE << "Swapped STD values" << RESET << std::endl;
    std::cout << YELLOW << "smap: " << RESET;
    printMapValues(smap);
    std::cout << YELLOW << "smap2: " << RESET;
    printMapValues(smap2);
    std::cout << BLUE << "Original FT values" << RESET << std::endl;
    std::cout << YELLOW << "fmap: " << RESET;
    printMapValues(fmap);
    std::cout << YELLOW << "fmap2: " << RESET;
    printMapValues(fmap2);
    fmap.swap(fmap2);
    std::cout << BLUE << "Swapped FT values" << RESET << std::endl;
    std::cout << YELLOW << "fmap: " << RESET;
    printMapValues(fmap);
    std::cout << YELLOW << "fmap2: " << RESET;
    printMapValues(fmap2);

    std::cout << std::endl;
    std::cout << YELLOW << "clear()" << RESET << std::endl;
    smap.clear();
    fmap.clear();

    s_start = timer();  stmap.clear(); s_end = timer();
    f_start = timer();  ftmap.clear(); f_end = timer();
    printTimes();
    
    printMapInfo(smap);
    printMapInfo(fmap);

    populateMap(smap, seed);
    populateMap(fmap, seed);
    printMapValues(smap);
    printMapValues(fmap);

    std::cout << std::endl;
    std::cout << MAGENTA << "OPERATIONS" << RESET << std::endl;    
    std::cout << YELLOW << "find(const key_type& k) - map.find(seed + 3) - Returns an iterator pointing that key" << RESET << std::endl;
    sit = smap.find(seed + 3);
    fit = fmap.find(seed + 3);
    std::cout << CYAN << "STD MAP ITERATOR is now pointing to: " << sit->first << "=>" << sit->second << RESET << std::endl;
    std::cout << CYAN << "FT MAP ITERATOR is now pointing to: " << fit->first << "=>" << fit->second << RESET << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "count (const key_type& k) - map.count(seed + 3) - Returns number of element with specific key" << RESET << std::endl;
    std::cout <<"result: " CYAN << smap.count(seed + 2) << RESET << std::endl;
    std::cout <<"result: " CYAN << fmap.count(seed + 2) << RESET << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "lower_bound (const key_type& k) - map.lower_bound(seed + 3) - Returns iterator to the element with specific key" << RESET << std::endl;
    std::cout <<"result: " CYAN << smap.lower_bound(seed + 3)->first << RESET << std::endl;
    std::cout <<"result: " CYAN << fmap.lower_bound(seed + 3)->first << RESET << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "upper_bound (const key_type& k) - map.upper_bound(seed + 3) - An iterator to the the first element in the container whose key is considered to go after k" << RESET << std::endl;
    std::cout <<"result: " CYAN << smap.upper_bound(seed + 3)->first << RESET << std::endl;
    std::cout <<"result: " CYAN << fmap.upper_bound(seed + 3)->first << RESET << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "equal_range (const key_type& k) - map.equal_range(seed + 3) - The function returns a pair of map iterators" << RESET << std::endl;
    std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> sRet = smap.equal_range(seed + 3);
    ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> fRet = fmap.equal_range(seed + 3);
    std::cout << "STD lower_bound points to: ";
    std::cout << CYAN << sRet.first->first << " => " << sRet.first->second << RESET << '\n';
    std::cout << "STD upper_bound points to: ";
    std::cout << CYAN << sRet.second->first << " => " << sRet.second->second << RESET << '\n';
    std::cout << "FT lower_bound points to: ";
    std::cout << CYAN << fRet.first->first << " => "  << fRet.first->second << RESET << '\n';
    std::cout << "FT upper_bound points to: ";
    std::cout << CYAN << fRet.second->first << " => " << fRet.second->second << RESET << '\n';

    emptyLine();
    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << MAGENTA << "                                          SET                                             " << RESET << "|" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;


	ft::set<int> fset;

	std::cout << "insert 20,50,43,39,11:" << std::endl;
	fset.insert(20);
	fset.insert(50);
	fset.insert(43);
	fset.insert(39);
	fset.insert(11);
    prinTree(fset._tree);
	std::cout << "insert 7,15,23,40,53,8,10:" << std::endl;
	fset.insert(7);
	fset.insert(15);
	fset.insert(23);
	fset.insert(40);
	fset.insert(53);
	fset.insert(8);
	fset.insert(10);

    prinTree(fset._tree);

    //20,50,7
    std::cout << std::endl << "erase 23:" << std::endl;
	fset.erase(23);
    prinTree(fset._tree);
    emptyLine();
    std::cout << "erase 11,20,50,39,43:" << std::endl;
    fset.erase(11); fset.erase(20); fset.erase(50); fset.erase(39); fset.erase(43);
    prinTree(fset._tree);
    emptyLine();
    std::cout << std::endl << "erase 15:" << std::endl;
	fset.erase(15);
    prinTree(fset._tree);
    emptyLine();
    std::cout << std::endl << "clear:" << std::endl;
	fset.clear();
    prinTree(fset._tree);
}