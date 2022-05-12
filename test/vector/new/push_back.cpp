#include "utils.hpp"

int execThirdTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 8);
    ft::vector<int> ftv(10, 8);
    ft::vector<int>::iterator   it = ftv.begin();

    stv.pop_back();
    clock_t t = clock();
    stv.push_back(9);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    ftv.pop_back();
    t = clock();
    ftv.push_back(9);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (ftv.begin() != it)
    {
        printError("push back: third test: reallocation unnecessary", stv, ftv, 1);
        return (0);
    }
    if (!compareVector("push_back: third test: ", stv, ftv))
		return 1;
    return (0);    
}

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(8, 8);
    ft::vector<int> ftv(8, 8);

    clock_t t = clock();
    stv.push_back(9);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.push_back(9);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("push_back: second test: ", stv, ftv))
		return 1;
    return (0);    
}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    ft::vector<int> ftv;

    clock_t t = clock();
    stv.push_back(9);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.push_back(9);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("push_back: first test: ", stv, ftv))
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
	if (result == 3)
		flag = 1;
	printResult("push_back", flag, timeFt, timeStd);
	return (1);
}
