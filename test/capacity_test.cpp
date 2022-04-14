#include <iostream>
#include <vector>
#include <memory>
#include "../sources/vector.hpp"

int main()
{

    /* std::vector<int> vect2(5, 6);
    vect2.push_back(8);
    std::vector<int>::iterator  it1;
    std::vector<int>::iterator  it2;
    it1 = vect2.begin();
    it2 = vect2.end();
    
    std::vector<int> vect3(it1, it2);
    std::cout << "size: " << vect3.size() << std::endl;
    std::cout << "capacity: " << vect3.capacity() << std::endl;
    for (size_t i = 0; i < vect3.size(); i++)
    {
        std::cout << vect3.at(i) << std::endl;
    }
    std::cout << std::endl;
    vect3.push_back(9);
    std::cout << "size: " << vect3.size() << std::endl;
    std::cout << "capacity: " << vect3.capacity() << std::endl;
    for (size_t i = 0; i < vect3.size(); i++)
    {
        std::cout << vect3.at(i) << std::endl;
    }
    std::cout << std::endl;
    vect3.pop_back();
    std::cout << "size: " << vect3.size() << std::endl;
    std::cout << "capacity: " << vect3.capacity() << std::endl;
    for (size_t i = 0; i < vect3.size(); i++)
    {
        std::cout << vect3.at(i) << std::endl;
    }
    vect3.push_back(9);
       vect3.push_back(9);
          vect3.push_back(9);
             vect3.push_back(9);
                vect3.push_back(9);
                   vect3.push_back(9);
                      vect3.push_back(11);
    std::cout << "size: " << vect3.size() << std::endl;
    std::cout << "capacity: " << vect3.capacity() << std::endl;
    std::cout << "maxsize: " << vect3.max_size() << std::endl; */
/*     std::cout << vect3.at(3) << std::endl;
    std::cout << "fine" << std::endl; */

   

/*     std::allocator<int> all;
    int* arr = all.allocate(vect2.size() * 2);
    arr[0] = 2;
    arr[1] = 3;
    arr[9] = 9;
    std::cout << arr[1] << std::endl;
    std::cout << arr[9] << std::endl;
    std::cout << arr[10] << std::endl; */
   /*  std::cout << "size: "<< vect2.size() << std::endl;
    std::cout << "capacity: "<< vect2.capacity() << std::endl;
    vect2.reserve(8);
    std::cout << vect2.capacity() << std::endl;

       vect2.push_back(213);
              vect2.push_back(23);
    std::cout << vect2.at(5) << std::endl;
        std::cout << vect2.at(6) << std::endl;
                      vect2.push_back(23);
        std::cout << vect2.at(7) << std::endl;
    std::cout << "capacity: " <<vect2.capacity() << std::endl;
    std::cout << vect2.size() << std::endl;
    vect2.push_back(23);
       std::cout << "capacity: " <<vect2.capacity() << std::endl;
    std::cout << vect2.size() << std::endl;
    std::cout << vect2.at(10) << std::endl; */
   
   /*  vect.push_back(7);
    for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << vect.at(i) << std::endl;
    }
    //vect.reserve(7);
    std::cout << "capacity" << vect.capacity() << std::endl;
    std::cout << "size" << vect.size() << std::endl;
    //std::cout << "at: 3" << vect2.at(5) << std::endl;  */



/* MAX SIZE */
/*     std::vector<std::string> vect2(4, "ciao");
    ft::vector<std::string> vect(4, "ciao");

    std::vector<int> vect3(4, 11);
    ft::vector<int> vect4(4, 11);

    std::vector<bool> vect5(4, true);
    ft::vector<bool> vect6(4, true);

    std::vector<float> vect7(4, 2.5f);
    ft::vector<float> vect8(4, 2.5f);

    std::vector<char> vect9(4, 'n');
    ft::vector<char> vect10(4, 'n');

    std::cout << "STRING" << std::endl;
    std::cout << "nostro: " << vect.max_size() << std::endl;
    std::cout << "sistema: " << vect2.max_size() << std::endl;
    std::cout << "INT" << std::endl;
    std::cout << "nostro: " << vect4.max_size() << std::endl;
    std::cout << "sistema: " << vect3.max_size() << std::endl;
    std::cout << "BOOL" << std::endl;
    std::cout << "nostro: " << vect6.max_size() << std::endl;
    std::cout << "sistema: " << vect5.max_size() << std::endl;
    std::cout << "FLOAT" << std::endl;
    std::cout << "nostro: " << vect8.max_size() << std::endl;
    std::cout << "sistema: " << vect7.max_size() << std::endl;
    std::cout << "CHAR" << std::endl;
    std::cout << "nostro: " << vect10.max_size() << std::endl;
    std::cout << "sistema: " << vect9.max_size() << std::endl; */


/* RESIZE & RESERVE*/

/*     std::vector<int> vect_st(5, 11);
    ft::vector<int> vect(5, 11);
    vect.reserve(8);
    vect_st.reserve(8);
    vect.resize(3, 8);
    vect_st.resize(3, 8);
    
    std::cout << "NOSTRO" << std::endl;
    for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << vect.at(i) << std::endl;
    }
    std::cout << "LORO" << std::endl;
    for (size_t i = 0; i < vect_st.size(); i++)
    {
        std::cout << vect_st.at(i) << std::endl;
    } */
}