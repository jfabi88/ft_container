#include "utils.hpp"

int execFifthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);
    std::vector<int> stv2(100000000, 3);
    ft::vector<int> ftv2(100000000, 3);

    clock_t t = clock();
    stv.swap(stv2);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.swap(ftv2);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("swap: fifth test: ", stv, ftv))
		return 1;
    if (!compareVector("push_back: first test: ", stv2, ftv2))
		return 1;
    return (0);   
}

int execFourthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);
    std::vector<int> stv2(2, 3);
    ft::vector<int> ftv2(2, 3);

    clock_t t = clock();
    stv.swap(stv2);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.swap(ftv2);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("swap: fourth test: ", stv, ftv))
		return 1;
    if (!compareVector("push_back: first test: ", stv2, ftv2))
		return 1;
    return (0);   
}

int execThirdTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);
    std::vector<int> stv2;
    ft::vector<int> ftv2;

    clock_t t = clock();
    stv.swap(stv2);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.swap(ftv2);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("swap: third test: ", stv, ftv))
		return 1;
    if (!compareVector("push_back: first test: ", stv2, ftv2))
		return 1;
    return (0);   
}

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    ft::vector<int> ftv;
    std::vector<int> stv2(10, 10);
    ft::vector<int> ftv2(10, 10);

    clock_t t = clock();
    stv.swap(stv2);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.swap(ftv2);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("swap: second test: ", stv, ftv))
		return 1;
    if (!compareVector("push_back: first test: ", stv2, ftv2))
		return 1;
    return (0);   
}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    ft::vector<int> ftv;
    std::vector<int> stv2;
    ft::vector<int> ftv2;

    clock_t t = clock();
    stv.swap(stv2);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.swap(ftv2);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("push_back: first test: ", stv, ftv))
		return 1;
    if (!compareVector("push_back: first test: ", stv2, ftv2))
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
	if (result == 5)
		flag = 1;
	printResult("swap", flag, timeFt, timeStd);
	return (1);
}