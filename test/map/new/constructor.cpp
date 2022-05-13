#include "utils.hpp"

int execFirstTest(double *timeFt, double *timeStd)
{
    ft::map<std::string, int> ftm;
	std::map<std::string, int> stm;

	*timeFt += 0;
	*timeStd += 0;
	return (1);
}

int main()
{
	int		result = 0;
	int		flag = 0;
	double	timeFt = 0;
	double	timeStd = 0;

	result += execFirstTest(&timeFt, &timeStd);
	if (result == 1)
		flag = 1;
	printResult("constructor", flag, timeFt, timeStd);
    return (0);
}