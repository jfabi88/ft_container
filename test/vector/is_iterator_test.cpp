
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

class my_class2
{
	public:
		typedef int value_type;
		typedef int difference_type;
		typedef int iterator_category;
		typedef int pointer;
};

int main()
{
	try {
    std::cout << std::boolalpha;
	std::cout << "   Is an iterator?" << std::endl;
	std::cout << "char:                          " <<ft::is_iterator<char>::value << "/" << /* std::_Is_iterator_v<char> << */ std::endl;
	std::cout << "std::string:                   " <<ft::is_iterator<std::string>::value << "/" << /* std::_Is_iterator_v<std::string> << */ std::endl;
	std::cout << "int:                           " <<ft::is_iterator<int>::value << "/" << /* std::_Is_iterator_v<int> << */ std::endl;
	std::cout << "float:                         " <<ft::is_iterator<float>::value << "/" << /* std::_Is_iterator_v<float> << */ std::endl;
	std::cout << "int *:                         " <<ft::is_iterator<int*>::value << "/" << /* std::_Is_iterator_v<int*> << */ std::endl;
	std::cout << "char*:                         " <<ft::is_iterator<char*>::value << "/" << /* std::_Is_iterator_v<char*> << */ std::endl;
	std::cout << "vector<int>::iterator:         " <<ft::is_iterator<std::vector<int>::iterator>::value << "/" << /* std::_Is_iterator_v<std::vector<int>::iterator> << */ std::endl;
	std::cout << "vector<char>::iterator:        " <<ft::is_iterator<std::vector<char>::iterator>::value << "/" << /* std::_Is_iterator_v<std::vector<char>::iterator> << */ std::endl;
	std::cout << "vector<std::string>::iterator: " <<ft::is_iterator<std::vector<std::string>::iterator>::value << "/" << /* std::_Is_iterator_v<std::vector<std::string>::iterator> << */ std::endl;
	std::cout << "vector<int*>::iterator:        " <<ft::is_iterator<std::vector<int*>::iterator>::value << "/" << /* std::_Is_iterator_v<std::vector<int*>::iterator> << */ std::endl;
	std::cout << "vector<float>::iterator:       " <<ft::is_iterator<std::vector<float>::iterator>::value << "/" << /* std::_Is_iterator_v<std::vector<float>::iterator> << */ std::endl;
	std::cout << "vector<float>:                 " <<ft::is_iterator<std::vector<float> >::value << "/" << /* std::_Is_iterator_v<std::vector<float>> << */ std::endl;
	std::cout << "my_class:                      " <<ft::is_iterator<my_class>::value << "/" << /* std::_Is_iterator_v<my_class> <<  */std::endl;
	std::cout << "my_class2:                      " <<ft::is_iterator<my_class2>::value << "/" << /* std::_Is_iterator_v<my_class2> << */ std::endl;
	
/* 	std::cout << "Has iterator traits?" << std::endl;
	std::cout << "char:                          " <<ft::has_iterator_traits<char>::value << "/" <<  std::endl;
	std::cout << "vector<int>::iterator:         " <<ft::has_iterator_traits<std::vector<int>::iterator>::value << "/" <<  std::endl;
	ft::iterator_traits<std::vector<int>::iterator> a;
	ft::void_t< ft::iterator_traits<char> > b; */
	}
	catch (const std::exception& e) {
		// Code that executes when an exception of type
		// networkIOException is thrown in the try block
		// ...
		// Log error message in the exception object
		std::cout << "ERROR: " << e.what();
	}
}
