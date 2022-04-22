#include <iostream>
#include <vector>
#include "utils.hpp"

class my_class
{
	public:
		typedef int value_type;
		typedef int difference_type;
		typedef int iterator_category;
		typedef int pointer;
		typedef int reference;
};

int main()
{
/*     std::cout << std::boolalpha;
	std::cout << "   Is an iterator?" << std::endl;
	std::cout << "char:                          " <<ft::is_iterator<char>::value << std::endl;
	std::cout << "std::string:                   " <<ft::is_iterator<std::string>::value << std::endl;
	std::cout << "int:                           " <<ft::is_iterator<int>::value << std::endl;
	std::cout << "float:                         " <<ft::is_iterator<float>::value << std::endl;
	std::cout << "int *:                         " <<ft::is_iterator<int*>::value << std::endl;
	std::cout << "char*:                         " <<ft::is_iterator<char*>::value << std::endl;
	std::cout << "vector<int>::iterator:         " <<ft::is_iterator<std::vector<int>::iterator>::value << std::endl;
	std::cout << "vector<char>::iterator:        " <<ft::is_iterator<std::vector<char>::iterator>::value << std::endl;
	std::cout << "vector<std::string>::iterator: " <<ft::is_iterator<std::vector<std::string>::iterator>::value << std::endl;
	std::cout << "vector<int*>::iterator:        " <<ft::is_iterator<std::vector<int*>::iterator>::value << std::endl;
	std::cout << "vector<float>::iterator:       " <<ft::is_iterator<std::vector<float>::iterator>::value << std::endl;
	std::cout << "vector<float>:                 " <<ft::is_iterator<std::vector<float> >::value << std::endl;
	std::cout << "my_class:                      " <<ft::is_iterator<my_class>::value << std::endl; */


/* 	std::vector<int> v;
	ft::vector<int>  cv;

	for (int i=1; i<11; i++) {
		v.push_back(i);
		cv.push_back(i);
	}

	std::cout << "begin/end/it++:\n";
	for( std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
		std::cout << *it << " ";
	}
	std::cout<< std::endl;

	for( ft::vector<int>::iterator fit = cv.begin(); fit != cv.end(); fit++){
		std::cout << *fit << " ";
	}
	std::cout<< std::endl;

	std::cout << "begin/end/++it:\n";
	for( std::vector<int>::iterator it = v.begin(); it != v.end(); ){
		std::cout << *(++it) << " ";
	}
	std::cout<< std::endl;

	for( ft::vector<int>::iterator fit = cv.begin(); fit != cv.end(); ){
		std::cout << *(++fit) << " ";
	}
	std::cout<< std::endl;

	std::cout << "operator+/operator-/operator==/operator>:\n";
	std::vector<int>::iterator it = v.begin();
	ft::vector<int>::iterator cit= cv.begin();

	std::cout << *(it + 4) << " " << *(v.end() - 2) << " " << ((v.end() - 2) == (v.begin() + 8)) << " ";
	std::cout << ((v.end() - 1) > (v.begin() + 7)) << "\n";
	std::cout << *(cit + 4) << " " << *(cv.end() - 2) << " " << ((cv.end() - 2) == (cv.begin() + 8)) << " ";
	std::cout << ((cv.end() - 1) > (cv.begin() + 7)) << "\n";

	ft::vector<int>::const_iterator ccit;
	std::vector<int>::const_iterator sit;

	std::cout << "const_iterator/++operator>:\n";
	for( std::vector<int>::const_iterator vl = v.begin(); vl != v.end(); vl++){
		std::cout << *(vl) << " ";
	}
	std::cout<< std::endl;
	for( ft::vector<int>::const_iterator ccit = cv.begin(); ccit != cv.end(); ccit++){
		std::cout << *(ccit) << " ";
	}

	size_t size = v.size();
	for (size_t i = 0; i < size; i++) {
			v.pop_back();
			cv.pop_back();
	}

	std::cout << "\nAfter pop_back()\n";
	for( std::vector<int>::const_iterator p = v.begin(); p != v.end(); p++){
		std::cout << *(p) << " ";
	}
	std::cout<< std::endl;
	for( ft::vector<int>::const_iterator ccit = cv.begin(); ccit != cv.end(); ccit++){
		std::cout << *(ccit) << " ";
	} */


	std::vector<int> ins;
	ft::vector<int>  ftins;

	ins.push_back(1); ins.push_back(2); ins.push_back(3); ins.push_back(4);
	ins.push_back(8); ins.push_back(9); ins.push_back(10);

	ftins.push_back(1); ftins.push_back(2); ftins.push_back(3); ftins.push_back(4);
	ftins.push_back(8); ftins.push_back(9); ftins.push_back(10);

	print_vector("1)beginning", ins);

	ins.insert(ins.begin()+4, 3, -1);
	ftins.insert(ftins.begin()+4, 3, -1);
	print_vector("2)insert(ins.begin()+4, 3, -1)", ins);
	print_vector("", ftins);

	ins.insert(ins.begin(), 1, 0);
	ftins.insert(ftins.begin(), 1, 0);
	print_vector("3)insert(ins.begin(), 1, 0)", ins);
	print_vector("", ftins);

	ins.insert(ins.begin() + 5, 1, 5);
	ftins.insert(ftins.begin() + 5, 1, 5);
	print_vector("4)insert(ins.begin()+5, 1, 5)", ins);
	print_vector("", ftins);

	ins.insert(ins.begin() + 6, 0, 6);
	ftins.insert(ftins.begin() + 6, 0,6);
	print_vector("5)insert(ins.begin() + 6, 0, 6)", ins);
	print_vector("", ftins);


	ins.insert(ins.begin() -1, 3, -3);
	ftins.insert(ftins.begin() -1, 3, -3);
	print_vector("6)insert(ins.begin() -1, 3, -3)", ins);
	print_vector("", ftins);

	ins.insert(ins.begin()-3, 4, 400);
	ftins.insert(ftins.begin()-3, 4, 400);
	print_vector("7)insert(ftins.begin()-3, 4, 400)", ins);
	print_vector("", ftins);

	ins.insert(ins.end(), 2, 555);
	ftins.insert(ftins.end(), 2, 555);
	print_vector("8)insert(ins.end(), 2, 555)", ins);
	print_vector("", ftins);

/* 	ins.insert(ins.end()+1, 3, 69);
	ftins.insert(ftins.end() + 1, 3, 69);
	print_vector("9)insert(ins.end() + 1, 3, 69)", ins);
	std::cout << "->" << *(ins.end()) << "," << *(ins.end() + 1) << "\n";
	print_vector("", ftins); */

/**************************************************************************************/
	std::vector<int> vf;
	ft::vector<int>  gc;
	std::vector<int>::iterator ivf;
	ft::vector<int>::iterator igc;

	vf.push_back(1); vf.push_back(2); vf.push_back(3); vf.push_back(4);vf.push_back(8); vf.push_back(9); vf.push_back(10);

	gc.push_back(1); gc.push_back(2); gc.push_back(3); gc.push_back(4);gc.push_back(8); gc.push_back(9); gc.push_back(10);

	print_vector("\nbeginning INSERT single element", ins);
	ivf = vf.insert(vf.begin()+4, 5);
	igc = gc.insert(gc.begin()+4, 5);
	print_vector("10)insert(vf.begin()+4, 5)", vf);
	print_vector("", gc);
	std::cout << *ivf << "," << *igc << "\n";

	ivf = vf.insert(vf.begin()+1, 55);
	igc = gc.insert(gc.begin()+1, 55);
	print_vector("11)insert(vf.begin()+1, 55)", vf);
	print_vector("", gc);
	std::cout << *ivf << "," << *igc << "\n";

	ivf = vf.insert(vf.begin()-1, 2222);
	igc = gc.insert(gc.begin()-1, 2222);
	print_vector("11)insert(vf.begin()-1, 2222)", vf);
	print_vector("", gc);
	std::cout << "->" << *(ivf - 1) << "," << *(igc - 1) << "\n";
	std::cout << *ivf << "," << *igc << "\n";

	return (0);
}