#include "utils.hpp"

int execSeventhTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    std::vector<int> stv2 = stv;
    ft::vector<int> ftv;
    ft::vector<int> ftv2 = ftv;
    int emptyStd;
    int emptyFt;

    clock_t t = clock();
    emptyStd = stv2.empty();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    emptyFt = ftv2.empty();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (emptyStd != emptyFt)
    {
        printError("empty: seventh test: ", stv2, ftv2, 2);
        return (0);
    }
    return (1);   
}

int execSixthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    std::vector<int> stv2(stv);
    ft::vector<int> ftv;
    ft::vector<int> ftv2(ftv);
    int emptyStd;
    int emptyFt;

    clock_t t = clock();
    emptyStd = stv2.empty();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    emptyFt = ftv2.empty();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (emptyStd != emptyFt)
    {
        printError("empty: sixth test: ", stv2, ftv2, 2);
        return (0);
    }
    return (1);   
}

int execFifthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    std::vector<int> stv2(stv.begin(), stv.end());
    ft::vector<int> ftv;
    ft::vector<int> ftv2(ftv.begin(), ftv.end());
    int emptyStd;
    int emptyFt;

    clock_t t = clock();
    emptyStd = stv2.empty();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    emptyFt = ftv2.empty();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (emptyStd != emptyFt)
    {
        printError("empty: fifth test: ", stv2, ftv2, 2);
        return (0);
    }
    return (1);   
}

int execFourthTest()
{
    return 1;
}

int execThirdTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(0, 10);
    ft::vector<int> ftv(0, 10);
    int emptyStd;
    int emptyFt;

    clock_t t = clock();
    emptyStd = stv.empty();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    emptyFt = ftv.empty();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (emptyStd != emptyFt)
    {
        printError("empty: third test: ", stv, ftv, 2);
        return (0);
    }
    return (1);   
}

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10);
    ft::vector<int> ftv(10);
    int emptyStd;
    int emptyFt;

    clock_t t = clock();
    emptyStd = stv.empty();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    emptyFt = ftv.empty();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (emptyStd != emptyFt)
    {
        printError("empty: second test: ", stv, ftv, 2);
        return (0);
    }
    return (1);   
}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    ft::vector<int> ftv;
    int emptyStd;
    int emptyFt;

    clock_t t = clock();
    emptyStd = stv.empty();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    emptyFt = ftv.empty();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (emptyStd != emptyFt)
    {
        printError("empty: first test: ", stv, ftv, 2);
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
	result += execThirdTest(&timeFt, &timeStd);
	result += execFourthTest();
	result += execFifthTest(&timeFt, &timeStd);
	result += execSixthTest(&timeFt, &timeStd);
    result += execSeventhTest(&timeFt, &timeStd);
	if (result == 7)
		flag = 1;
	printResult("empty", flag, timeFt, timeStd);
	return (1);
}
