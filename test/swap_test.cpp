#include <iostream>
#include <vector>
#include "utils.hpp"

int main()
{
    std::vector<int> uno(1, 5);
    std::vector<int> due(3, 7);

    ft::vector<int> ftuno(1, 5);
    ft::vector<int> ftdue(3, 7);

   
    uno.swap(due);
    print_vector("Standard uno", uno);
    print_sz_cp(uno);
    print_vector("due", due);
    print_sz_cp(due); 

    ftuno.swap(ftdue);
    print_vector("Nostro ftuno", ftuno);
    print_sz_cp(ftuno);
    print_vector("ftdue", ftdue);
    print_sz_cp(ftdue);

    ftdue.swap(ftuno);
    print_vector("Nostro ftuno", ftuno);
    print_sz_cp(ftuno);
    print_vector("ftdue", ftdue);
    print_sz_cp(ftdue);




    /* std::cout << "STANDARD" << std::endl;
    print_vector("bUNO", uno);
    print_sz_cp(uno);
    print_vector("bDUE", due);
    print_sz_cp(due); */

/*     std::cout << "NOSTRO" << std::endl;
    print_vector("FTbUNO", ftuno);
    print_sz_cp(ftuno);
    print_vector("FTbDUE", ftdue);
    print_sz_cp(ftdue); */

    //uno = due;
    /* due = uno;
    ftdue = ftuno;


    print_vector("dUNO", uno);
    print_sz_cp(uno);
    print_vector("dDUE", due);
    print_sz_cp(due);

    std::cout << "\n";
    print_vector("dUNO", ftuno);
    print_sz_cp(ftuno);
    print_vector("dDUE", ftdue);
    print_sz_cp(ftdue); */


   /*  std::vector<int> tre(1, 5);
    std::vector<int> quattro(3, 7); */
   /*  std::cout << std::endl << "___SWAP___" << std::endl << std::endl;

    print_vector("bTRE", tre);
    print_sz_cp(tre);
    print_vector("bQUATTRO", quattro);
    print_sz_cp(quattro);

    //tre.swap(quattro);
    quattro.swap(tre);

    print_vector("TRE", tre);
    print_sz_cp(tre);
    print_vector("QUATTRO", quattro);
    print_sz_cp(quattro); */

}