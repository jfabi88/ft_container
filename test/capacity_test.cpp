#include <iostream>
#include <vector>
#include <memory>
#include "../sources/vector.hpp"

template <class T>
void print_vector(std::string title, std::vector<T> vector)
{
    std::cout << title << std::endl;
    std::cout << "[";
    for (size_t i = 0; i < vector.size() - 1; i++)
        std::cout << vector.at(i) << ", ";
    std::cout << vector.at(vector.size() - 1) << "]" << std::endl;
}

template <class T>
void print_vector(std::string title, ft::vector<T> vector)
{
    std::cout << title << std::endl;
    std::cout << "[";
    for (size_t i = 0; i < vector.size() - 1; i++)
        std::cout << vector.at(i) << ", ";
    std::cout << vector.at(vector.size() - 1) << "]" << std::endl;
}

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



/*MAX SIZE */
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
    std::cout << "ft::vector: " << vect.max_size() << std::endl;
    std::cout << "sd::vector: " << vect2.max_size() << std::endl;
    std::cout << "INT" << std::endl;
    std::cout << "ft::vector: " << vect4.max_size() << std::endl;
    std::cout << "sd::vector: " << vect3.max_size() << std::endl;
    std::cout << "BOOL" << std::endl;
    std::cout << "ft::vector: " << vect6.max_size() << std::endl;
    std::cout << "sd::vector: " << vect5.max_size() << std::endl;
    std::cout << "FLOAT" << std::endl;
    std::cout << "ft::vector: " << vect8.max_size() << std::endl;
    std::cout << "sd::vector: " << vect7.max_size() << std::endl;
    std::cout << "CHAR" << std::endl;
    std::cout << "ft::vector: " << vect10.max_size() << std::endl;
    std::cout << "sd::vector: " << vect9.max_size() << std::endl; */


/* RESIZE & RESERVE*/

/*     std::vector<int> rvect_st(5, 11);
    ft::vector<int> rvect(5, 11);
    rvect.reserve(8);
    rvect_st.reserve(8);
    rvect.resize(3, 8);
    rvect_st.resize(3, 8);
    
    std::cout << "TEST RESIZE RESERVE (int)" << std::endl;
    std::cout << "Size e capacity di ft::vector : " << rvect.size() << " " << rvect.capacity() << std::endl;
    std::cout << "Size e capacity di sd::vector: " << rvect_st.size() << " " << rvect_st.capacity() << std::endl;
    print_vector("FT::VECTOR", rvect);
    print_vector("SD::VECTOR", rvect_st);
    rvect.resize(5, 8);
    rvect_st.resize(5, 8);
    std::cout << "Size e capacity di ft::vector : " << rvect.size() << " " << rvect.capacity() << std::endl;
    std::cout << "Size e capacity di sd::vector: " << rvect_st.size() << " " << rvect_st.capacity() << std::endl;
    print_vector("FT::VECTOR", rvect);
    print_vector("SD::VECTOR", rvect_st);
    rvect.resize(7);
    rvect_st.resize(7);
    std::cout << "Size e capacity di ft::vector : " << rvect.size() << " " << rvect.capacity() << std::endl;
    std::cout << "Size e capacity di sd::vector: " << rvect_st.size() << " " << rvect_st.capacity() << std::endl;
    print_vector("FT::VECTOR", rvect);
    print_vector("SD::VECTOR", rvect_st);
    rvect.resize(10);
    rvect_st.resize(10);
    std::cout << "Size e capacity di ft::vector : " << rvect.size() << " " << rvect.capacity() << std::endl;
    std::cout << "Size e capacity di sd::vector: " << rvect_st.size() << " " << rvect_st.capacity() << std::endl;
    print_vector("FT::VECTOR", rvect);
    print_vector("SD::VECTOR", rvect_st);
    rvect.resize(14, 9);
    rvect_st.resize(14, 9);
    std::cout << "Size e capacity di ft::vector : " << rvect.size() << " " << rvect.capacity() << std::endl;
    std::cout << "Size e capacity di sd::vector: " << rvect_st.size() << " " << rvect_st.capacity() << std::endl;
    print_vector("FT::VECTOR", rvect);
    print_vector("SD::VECTOR", rvect_st); */

/* RESIZE & RESERVE*/

/*     std::cout << "CIAO" << std::endl;
    std::vector<std::string> rsvect_st(5, "Sole");
    ft::vector<std::string> rsvect(5, "Sole");
    std::cout << "Come state" << std::endl;
    rsvect.reserve(8);
    std::cout << "Come state" << std::endl;
    rsvect_st.reserve(8);
    std::cout << "Come state" << std::endl;
    rsvect.resize(3, "Luna");
    rsvect_st.resize(3, "Luna");

    std::cout << "TEST RESIZE RESERVE (std::string)" << std::endl;
    std::cout << "Size e capacity di ft::vector : " << rsvect.size() << " " << rsvect.capacity() << std::endl;
    std::cout << "Size e capacity di sd::vector: " << rsvect_st.size() << " " << rsvect_st.capacity() << std::endl;
    print_vector("FT::VECTOR", rsvect);
    print_vector("SD::VECTOR", rsvect_st);
    rsvect.resize(5, "Marte");
    rsvect_st.resize(5, "Marte");
    std::cout << "Size e capacity di ft::vector : " << rsvect.size() << " " << rsvect.capacity() << std::endl;
    std::cout << "Size e capacity di sd::vector: " << rsvect_st.size() << " " << rsvect_st.capacity() << std::endl;
    print_vector("FT::VECTOR", rsvect);
    print_vector("SD::VECTOR", rsvect_st);
    rsvect.resize(7);
    rsvect_st.resize(7);
    std::cout << "Size e capacity di ft::vector : " << rsvect.size() << " " << rsvect.capacity() << std::endl;
    std::cout << "Size e capacity di sd::vector: " << rsvect_st.size() << " " << rsvect_st.capacity() << std::endl;
    print_vector("FT::VECTOR", rsvect);
    print_vector("SD::VECTOR", rsvect_st);
    rsvect.resize(10);
    rsvect_st.resize(10);
    std::cout << "Size e capacity di ft::vector : " << rsvect.size() << " " << rsvect.capacity() << std::endl;
    std::cout << "Size e capacity di sd::vector: " << rsvect_st.size() << " " << rsvect_st.capacity() << std::endl;
    print_vector("FT::VECTOR", rsvect);
    print_vector("SD::VECTOR", rsvect_st);
    rsvect.resize(14, "Venere");
    rsvect_st.resize(14, "Venere");
    std::cout << "Size e capacity di ft::vector : " << rsvect.size() << " " << rsvect.capacity() << std::endl;
    std::cout << "Size e capacity di sd::vector: " << rsvect_st.size() << " " << rsvect_st.capacity() << std::endl;
    print_vector("FT::VECTOR", rsvect);
    print_vector("SD::VECTOR", rsvect_st); */



    std::vector<int>::size_type sz;
    ft::vector<int>::size_type cz;
    std::vector<int> foo;
    ft::vector<int> cfoo;

/*     sz = foo.capacity();
    std::cout << "making foo grow from: " << sz << "\n";
    for (int i=0; i<100; ++i) {
        foo.push_back(i);
        if (sz!=foo.capacity()) {
        sz = foo.capacity();
        std::cout << "capacity changed: " << sz << '\n';
        }
    } */

    std::cout << "\n****************************************************\n";
    cz = cfoo.capacity();
    std::cout << "making foo grow from: " << cz << "\n";
    std::cout << "MAX SIZE: " << cfoo.max_size() << "\n";
    for (int i=0; i<100; ++i) {
       cfoo.push_back(i);
        if (cz!=cfoo.capacity()) {
            cz = cfoo.capacity();
            std::cout << i << ")capacity changed: " << cz;
            print_vector(" vECTOR", cfoo);
            std::cout << '\n';
            //std::cout << " value: " << cfoo.at(i) << '\n';
        }
    }

    std::cout << "\n****************************************************\n";

/*     std::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
        bar.push_back(i);
        if (sz!=bar.capacity()) {
        sz = bar.capacity();
        std::cout << "capacity changed: " << sz << '\n';
        }
    } */

/*     ft::vector<int> cbar;
    cz = cbar.capacity();
    cbar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
        cbar.push_back(i);
        if (cz!=cbar.capacity()) {
        cz = cbar.capacity();
        std::cout << "capacity changed: " << cz << '\n';
        }
    } */
}