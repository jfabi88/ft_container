#include <iostream>
#include <vector>
#include "utils.hpp"

class prova {
    public:
        size_t val;
        prova(){
            val = 9;
            std::cout << "prova constructor called\n";
        };
        prova(const prova &x){
            val = x.val;
            std::cout << "prova copy constructor called\n";
        };
        ~prova(){
            std::cout << "prova destructor called\n";
        };
};

int main()
{
    std::vector<prova> v(3);
    std::cout << "AFTER THE CLEAR\n";

    std::vector<int> er;
    std::vector<int>::iterator it_er;
    std::vector<int>::iterator it2_er;
    ft::vector<int> ft_er;
    ft::vector<int>::iterator ift_er;
    ft::vector<int>::iterator ift2_er;

    for (size_t i = 0; i < 20; i++)
    {
        er.push_back(i );
        ft_er.push_back(i);
    } 

    print_vector("STANDARD VECTOR", er, 0, true);
    //print_sz_cp(er);

    print_vector("OUR VECTOR", ft_er, 0, true);
    //print_sz_cp(ft_er); 

/*      std::cout << "----------------ERASE WITH POSITION----------------" << std::endl;

    it_er = er.begin() + 1;
    er.erase(it_er);

    std::cout << "STANDARD VECTOR AFTER ERASE" << std::endl;
    print_vector("", er);
    print_sz_cp(er);
    std::cout << "return value = " << *(it_er) << std::endl;

    ift_er = ft_er.begin() + 1;
    ft_er.erase(ift_er);

    std::cout << "OUR VECTOR AFTER ERASE" << std::endl;
    print_vector("", ft_er);
    print_sz_cp(ft_er);
    std::cout << "return value = " << *(ift_er) << std::endl;

    std::cout << "----------------ERASE WITH FIRST AND LAST----------------" << std::endl; */

    it_er = er.begin();
    it2_er = er.begin() + 2;
    er.erase(it_er, it2_er);

    std::cout << "STANDARD VECTOR AFTER ERASE(begin(), begin()+2)" << std::endl;
    print_vector("", er, 0, true);
    std::cout << "return value = " << *(it_er) << std::endl;

    ift_er = ft_er.begin();
    ift2_er = ft_er.begin() + 2;
    ft_er.erase(ift_er, ift2_er);

    std::cout << "OUR VECTOR AFTER  ERASE(begin(), begin()+2)" << std::endl;
    print_vector("", ft_er, 0, true);
    std::cout << "return value = " << *(ift_er) << std::endl;
}