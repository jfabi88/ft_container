#include "utils.hpp"

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(1, 8);
    ft::vector<int> ftv(1, 8);

    clock_t t = clock();
    stv.pop_back();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.pop_back();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("pop_back: second test: ", stv, ftv))
		return 1;
    return (0);    
}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 2);
    ft::vector<int> ftv(10, 2);

    clock_t t = clock();
    stv.pop_back();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.pop_back();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("pop_back: first test: ", stv, ftv))
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
	if (result == 2)
		flag = 1;
	printResult("pop_back", flag, timeFt, timeStd);
	return (1);
}
