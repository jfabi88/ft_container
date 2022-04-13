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

   // std::vector<int> vect2(5, 6);

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
    ft::vector<int> vect(4, 7);
    vect.push_back(56);
    /* for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << vect.at(i) << std::endl;
    } */
    //vect.reserve(7);
    std::cout << "capacity" << vect.capacity() << std::endl;
    std::cout << "size" << vect.size() << std::endl;
    
}