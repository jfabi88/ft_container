#include "utils.hpp"

int execSeventhTest()
{
    std::vector<int> stv(8, 9);
    ft::vector<int> ftv(8, 9);
    ft::vector<int>::iterator fit = ftv.begin();

    try {
        stv.reserve(stv.max_size() + 1);
    }
    catch (std::exception &e) {};

    try {
        ftv.reserve(ftv.max_size() + 1);
        return (0);
    }
    catch (std::exception &e) {}

    if (!compareVector("resize: seventh test: ", stv, ftv))
		return 1;
    return (0); 
}

int execSixthTest()
{
    std::vector<int> stv(8, 9);
    ft::vector<int> ftv(8, 9);
    ft::vector<int>::iterator fit = ftv.begin();

    try {
        stv.reserve(-9);
    }
    catch (std::exception &e) {};

    try {
        ftv.reserve(-9);
        return (0);
    }
    catch (std::exception &e) {}

    if (!compareVector("resize: seventh test: ", stv, ftv))
		return 1;
    return (0); 
}

int execFifthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    ft::vector<int> ftv;
    ft::vector<int>::iterator fit = ftv.begin();

    clock_t t = clock();
    stv.reserve(0);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.reserve(0);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (ftv.begin() != fit)
    {
        printError("resize: fifth test: reallocation of memory unnecessary", stv, ftv, 0);
        return (0);
    }
    if (!compareVector("resize: fifth test: ", stv, ftv))
		return 1;
    return (0); 
}

int execFourthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);
    ft::vector<int>::iterator fit = ftv.begin();

    clock_t t = clock();
    stv.reserve(8);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.reserve(8);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (ftv.begin() != fit)
    {
        printError("resize: fourth test: reallocation of memory unnecessary", stv, ftv, 0);
        return (0);
    }
    if (!compareVector("resize: fourth test: ", stv, ftv))
		return 1;
    return (0);
}

int execThirdTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    clock_t t = clock();
    stv.reserve(100000000);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.reserve(100000000);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("reserve: third test: ", stv, ftv))
		return 1;
    return (0);
}

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    ft::vector<int> ftv;

    clock_t t = clock();
    stv.reserve(10);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.reserve(10);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("reserve: second test: ", stv, ftv))
		return 1;
    return (0);
}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    ft::vector<int> ftv;

    clock_t t = clock();
    stv.reserve(0);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.reserve(0);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("reserve: first test: ", stv, ftv))
		return 1;
    return (0);
}

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
	result += execFifthTest(&timeFt, &timeStd);
	result += execSixthTest();
    result += execSeventhTest();
	if (result == 7)
		flag = 1;
	printResult("reserve", flag, timeFt, timeStd);
	return (1);
}
