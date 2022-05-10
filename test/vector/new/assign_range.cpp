#include "utils.hpp"

int main()
{
    int		result = 0;
	int		flag = 0;
	double	timeFt = 0;
	double	timeStd = 0;

	result += execFirstTest(&timeFt, &timeStd);
	result += execSecondTest(&timeFt, &timeStd);
	result += execThirdTest(&timeFt, &timeStd);
    result += execFourthTest(&timeFt, &timeStd);
	if (result == 4)
		flag = 1;
	printResult("assign range", flag, timeFt, timeStd);
	return (1);
}
