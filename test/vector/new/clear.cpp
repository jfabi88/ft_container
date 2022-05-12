#include "utils.hpp"

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    ft::vector<int> ftv;

    clock_t t = clock();
    stv.clear();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.clear();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (ftv.size() != 0 && ftv.begin() != ftv.end())
    {
        printError("clear: second test: " + printVector(ftv), stv, ftv, 1);
        return (0);
    }
    return (1);
}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 2);
    ft::vector<int> ftv(10, 2);

    clock_t t = clock();
    stv.clear();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.clear();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (ftv.size() != 0 && ftv.begin() != ftv.end())
    {
        printError("clear: first test: " + printVector(ftv), stv, ftv, 1);
        return (0);
    }
    return (1);
}

int main()
{
    int		result = 0;
	int		flag = 0;
	double	timeFt = 0;
	double	timeStd = 0;

	result += execFirstTest(&timeFt, &timeStd);
	result += execSecondTest(&timeFt, &timeStd);
	if (result == 2)
		flag = 1;
	printResult("clear", flag, timeFt, timeStd);
	return (1);
}
