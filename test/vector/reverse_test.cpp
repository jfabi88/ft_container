#include "utils.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> prova;
    std::vector<int>::reverse_iterator pr;
    prova.push_back(9);
    prova.push_back(4);
    prova.push_back(8);
    prova.push_back(3);
    prova.push_back(1);
    pr = prova.rend() - 1; //= begin()
    

    ft::vector<int> ftprova;
    ft::vector<int>::reverse_iterator ftpr;
    ftprova.push_back(9);
    ftprova.push_back(4);
    ftprova.push_back(8);
    ftprova.push_back(3);
    ftprova.push_back(1);
    ftpr = ftprova.rend() - 1; //= begin()
    

    print_vector("Standard output", prova, 2, true);
    print_vector("Our output", ftprova, 2, true);

    std::cout << std::boolalpha;
    std::cout << "\n[STD] pr != prova.rend() - 1: " << (pr != prova.rend() - 1) << std::endl;
    std::cout << "[OUR] ftpr != ftprova.rend() - 1: " << (ftpr != ftprova.rend() - 1) << std::endl;
    std::cout << "[STD] pr == prova.rend() - 1: " << (pr == prova.rend() - 1) << std::endl;
    std::cout << "[OUR] ftpr == ftprova.rend() - 1: " << (ftpr == ftprova.rend() - 1) << std::endl;
    std::cout << "[STD] pr != prova.rend() - 2: " << (pr != prova.rend() - 2) << std::endl;
    std::cout << "[OUR] ftpr != ftprova.rend() - 2: " << (ftpr != ftprova.rend() - 2) << std::endl;
    std::cout << "[STD] pr == prova.rend() - 2: " << (pr == prova.rend() - 2) << std::endl;
    std::cout << "[OUR] ftpr == ftprova.rend() - 2: " << (ftpr == ftprova.rend() - 2) << std::endl; 
    std::cout << "[STD] pr += 2: " << *(pr += 2) << std::endl;
    std::cout << "[OUR] ftpr += 2: " << *(ftpr +=2) << std::endl;
    std::cout << "[STD] pr -= 4: " << *(pr -= 4) << std::endl;
    std::cout << "[OUR] ftpr -= 4: " << *(ftpr -= 4) << std::endl;
    std::cout << "[STD] pr > (prova.rend() - 2): " <<  (pr > (prova.rend() - 2)) << std::endl;
    std::cout << "[OUR] ftpr > (ftprova.rend() - 2): " <<  (ftpr > (ftprova.rend() - 2)) << std::endl;
    std::cout << "[STD] pr < (prova.rend() - 2): " <<  (pr < (prova.rend() - 2)) << std::endl;
    std::cout << "[OUR] ftpr < (ftprova.rend() - 2): " <<  (ftpr < (ftprova.rend() - 2)) << std::endl;

    std::vector<int>::reverse_iterator rt;
    rt = pr;
    std::cout << "[STD] rt: " << *(rt) << std::endl;

    ft::vector<int>::reverse_iterator ftrt;
    ftrt = ftpr;
    std::cout << "[OUR] ftrt: " << *(ftrt) << std::endl;

    std::cout << std::endl;

    

}
