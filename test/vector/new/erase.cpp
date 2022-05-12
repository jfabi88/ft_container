#include "utils.hpp"

int execFifthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 2);
    ft::vector<int> ftv(10, 2);

    clock_t t = clock();
    stv.erase(stv.begin(), stv.begin() + 10);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.erase(ftv.begin(), ftv.begin() + 10);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("erase range: fourth test: ", stv, ftv))
		return 1;
    return (0);
}

int execFourthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 2);
    ft::vector<int> ftv(10, 2);

    clock_t t = clock();
    stv.erase(stv.begin(), stv.begin() + 3);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.erase(ftv.begin(), ftv.begin() + 3);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("erase range: fourth test: ", stv, ftv))
		return 1;
    return (0);    
}

int execThirdTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(1, 2);
    ft::vector<int> ftv(1, 2);

    clock_t t = clock();
    stv.erase(stv.end() - 1);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.erase(ftv.end() -1);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("erase fill: third test: ", stv, ftv))
		return 1;
    return (0);    
}

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 2);
    ft::vector<int> ftv(10, 2);

    clock_t t = clock();
    stv.erase(stv.begin());
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.erase(ftv.begin());
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("erase fill: second test: ", stv, ftv))
		return 1;
    return (0);    
}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 2);
    ft::vector<int> ftv(10, 2);

    clock_t t = clock();
    stv.erase(stv.begin() + 5);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.erase(ftv.begin() + 5);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("erase fill: first test: ", stv, ftv))
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
	printResult("erase", flag, timeFt, timeStd);
	return (1);
}