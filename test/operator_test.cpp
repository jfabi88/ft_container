#include <iostream>
#include <vector>
#include "utils.hpp"

int main()
{
	std::vector<std::string> stdVec1;
	std::vector<std::string> stdVec2;
	ft::vector<std::string> ftVec1;
	ft::vector<std::string> ftVec2;

	stdVec1.push_back("Pollo al forno");
	stdVec2.push_back("Insalata");
	ftVec1.push_back("Pollo al forno") ;
	ftVec2.push_back("Insalata");

	std::cout << "STD" << std::endl;
	std::cout << std::boolalpha;
	std::cout << "vector1 <= vector2 : " << (stdVec1 <= stdVec2) << std::endl;
	std::cout << "vector1 >= vector2 : " << (stdVec1 >= stdVec2) << std::endl;
	std::cout << "vector1 == vector2 : " << (stdVec1 == stdVec2) << std::endl;
	std::cout << "vector1 != vector2 : " << (stdVec1 != stdVec2) << std::endl;
	std::cout << "vector1 < vector2 : " << (stdVec1 < stdVec2) << std::endl;
	std::cout << "vector1 > vector2 : " << (stdVec1 > stdVec2) << std::endl;
	std::cout << "VEC" << std::endl;
	std::cout << "vector1 <= vector2 : " << (ftVec1 <= ftVec2) << std::endl;
	std::cout << "vector1 >= vector2 : " << (ftVec1 >= ftVec2) << std::endl;
	std::cout << "vector1 == vector2 : " << (ftVec1 == ftVec2) << std::endl;
	std::cout << "vector1 != vector2 : " << (ftVec1 != ftVec2) << std::endl;
	std::cout << "vector1 < vector2 : " << (ftVec1 < ftVec2) << std::endl;
	std::cout << "vector1 > vector2 : " << (ftVec1 > ftVec2) << std::endl;
	return (0);
}
