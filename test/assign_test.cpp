#include <iostream>
#include <vector>
#include "utils.hpp"

int main ()
{
    /* ---------------------FILL ASSIGN--------------------- */
    
    /* std::cout << "STANDARD"<< std::endl;
    std::vector<int> first(8, 7);
    
    print_vector("prima", first);
    print_sz_cp(first);
    first.assign (5,100);             // 7 ints with a value of 100
    print_vector("dopo assign", first);
    print_sz_cp(first);

    std::cout << "------------------------"<< std::endl;

    std::cout << "NOSTRO"<< std::endl;

    ft::vector<int> ftfirst(8, 7);
    print_vector("prima", ftfirst);
    print_sz_cp(ftfirst);
    ftfirst.assign (5,100);             // 7 ints with a value of 100
    print_vector("dopo assign", ftfirst);
    print_sz_cp(ftfirst);  */

    /* ---------------------RANGE ASSIGN--------------------- */

    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;

    std::cout << "0) at Beginning" << std::endl;
    print_vector("", first, 0, true);

    std::cout << std::endl << "1) assign (7,100);" << std::endl;
    first.assign (7,100);             // 7 ints with a value of 100
    print_vector("", first, 0, true);

    std::cout << std::endl << "2) assign(it,first.end()-1);" << std::endl;
    std::vector<int>::iterator it;
    it = first.begin() + 1;
    print_vector("prima", second , 0, true);
    second.assign (it,first.end() -1); // the 5 central values of first
    print_vector("dopo", second, 0, true);

    ft::vector<int> ftfirst;
    ft::vector<int> ftsecond;
    ft::vector<int> ftthird;

    ftfirst.assign(7,100);             // 7 ints with a value of 100
    print_vector("ftfirst", ftfirst, 0, true);
    ft::vector<int>::iterator ftit;
    ftit = ftfirst.begin() + 1;
    ftsecond.assign(ftit, ftfirst.end() -1); // the 5 central values of first
    print_vector("dopo", ftsecond, 0, true); 

    /* int myints[] = {1776,7,4};
    third.assign (myints,myints+4);
    print_vector("THIRD", third);
    print_sz_cp(third);  // assigning from array. */

 /*    std::vector<int> tmp(6, 8);
    std::vector<int> prova(2, 7);
    std::vector<int>::iterator itpr;


    ft::vector<int> ftprova(2, 7);
    ft::vector<int> fttmp(6, 8);
    ft::vector<int>::iterator ftpr;

    itpr = prova.begin();
    prova.insert(itpr, tmp.begin(), tmp.end() - 1);
    print_vector("STANDARD", prova, 0, true);

    std::cout << "------------------------------\n";

    ftpr = ftprova.begin();

    ftprova.insert(ftpr, fttmp.begin(), fttmp.end() - 1);
    print_vector("OUR", ftprova, 0, true);

    itpr++; */

}
