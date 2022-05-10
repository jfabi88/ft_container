#include "utils.hpp"

int execSeventhTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    std::vector<int> stv2 = stv;
    ft::vector<int> ftv(10, 10);
    ft::vector<int> ftv2 = ftv;
    int sizeStd;
    int sizeFt;

    clock_t t = clock();
    sizeStd = stv2.size();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    sizeFt = ftv2.size();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (sizeStd != sizeFt)
    {
        printError("size: seventh test: ", stv2, ftv2, 2);
        return (0);
    }
    return (1);   
}

int execSixthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    std::vector<int> stv2(stv);
    ft::vector<int> ftv(10, 10);
    ft::vector<int> ftv2(ftv);
    int sizeStd;
    int sizeFt;

    clock_t t = clock();
    sizeStd = stv2.size();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    sizeFt = ftv2.size();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (sizeStd != sizeFt)
    {
        printError("size: sixth test: ", stv2, ftv2, 2);
        return (0);
    }
    return (1);   
}

int execFifthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    std::vector<int> stv2(stv.begin(), stv.end());
    ft::vector<int> ftv(10, 10);
    ft::vector<int> ftv2(ftv.begin(), ftv.end());
    int sizeStd;
    int sizeFt;

    clock_t t = clock();
    sizeStd = stv2.size();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    sizeFt = ftv2.size();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (sizeStd != sizeFt)
    {
        printError("size: fifth test: ", stv2, ftv2, 2);
        return (0);
    }
    return (1);   
}

int execFourthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10000000, 10);
    ft::vector<int> ftv(10000000, 10);
    int sizeStd;
    int sizeFt;

    clock_t t = clock();
    sizeStd = stv.size();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    sizeFt = ftv.size();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (sizeStd != sizeFt)
    {
        printError("size: fourth test: ", stv, ftv, 2);
        return (0);
    }
    return (1);   
}

int execThirdTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);
    int sizeStd;
    int sizeFt;

    clock_t t = clock();
    sizeStd = stv.size();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    sizeFt = ftv.size();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (sizeStd != sizeFt)
    {
        printError("size: third test: ", stv, ftv, 2);
        return (0);
    }
    return (1);   
}

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10);
    ft::vector<int> ftv(10);
    int sizeStd;
    int sizeFt;

    clock_t t = clock();
    sizeStd = stv.size();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    sizeFt = ftv.size();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (sizeStd != sizeFt)
    {
        printError("size: second test: ", stv, ftv, 2);
        return (0);
    }
    return (1);   
}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    ft::vector<int> ftv;
    int sizeStd;
    int sizeFt;

    clock_t t = clock();
    sizeStd = stv.size();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    sizeFt = ftv.size();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (sizeStd != sizeFt)
    {
        printError("size: first test: ", stv, ftv, 2);
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
	result += execFourthTest(&timeFt, &timeStd);
	result += execFifthTest(&timeFt, &timeStd);
	result += execSixthTest(&timeFt, &timeStd);
    result += execSeventhTest(&timeFt, &timeStd);
	if (result == 7)
		flag = 1;
	printResult("size", flag, timeFt, timeStd);
	return (1);
}