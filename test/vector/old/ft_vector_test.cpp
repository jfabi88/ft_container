#include "utils.hpp"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    ft::vector<int> first;
    ft::vector<int> second(10, 100);
    std::vector<int> test;
    std::vector<int> test2(test);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);

    ft::vector<int> third(second.begin(), second.end());
    ft::vector<int> fouth(third);
    //std::vector<std::string> stdthird("stronzo", "zoticone");
    //ft::vector<std::string> third("stronzo", "zoticone");

    //std::string fstr;
    //std::string sstr;

    //fstr = "ciao";
    //sstr = "pollo";
    //std::vector<int> fstd("stronzo", "fti");
    //std::vector<std::string> ftd("stronzo", "oti");
    //std::vector<int> fstd2(fstr, sstr);
    //std::cout << fstd.size() << std::endl;
    //for(size_t i = 0; i < fstd.size(); i++)
        //std::cout << (char)fstd.at(i) << std::endl;
/*     std::cout << (char)fstd.at(1) << std::endl;
    std::cout << (char)fstd.at(2) << std::endl;
    std::cout << (char)fstd.at(3) << std::endl;
    std::cout << (char)fstd.at(7) << std::endl; */

    //std::vector<char> ciao('c', 'p');
    //ft::vector<int> f("stronzo", "zoticone");
/*     std::cout << third.at(0) << std::endl;
    std::cout << third.at(1) << std::endl;
    std::cout << third.at(2) << std::endl;
     std::cout << third.at(third.size() - 1) << std::endl; 
    std::cout << third.size() << std::endl; */
    
    //std::vector<std::string> stringa;

    //stringa.push_back("ciao");
    //stringa.push_back("mondo");
    //stringa.push_back("crudele");
    // int dist = stringa.begin() - stringa.end();
    // std::cout << dist << std::endl;
    // std::vector<std::string> f(stringa.end(), stringa.begin());
    
    return (0);
}