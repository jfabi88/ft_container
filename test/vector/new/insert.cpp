#include "utils.hpp"

int execTenthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);
    ft::vector<int>::iterator it = ftv.begin();

    stv.pop_back();
    stv.pop_back();
    stv.pop_back();
    clock_t t = clock();
    stv.insert(stv.begin(), stv.begin() + 2, stv.begin() + 4);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    ftv.pop_back();
    ftv.pop_back();
    ftv.pop_back();
    t = clock();
    ftv.insert(ftv.begin(), ftv.begin() + 2, ftv.begin() + 4);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (it != ftv.begin())
    {
        printError("insert range: tenth test: realoccation unnecessary", stv, ftv, 0);
        return (0);
    }
    if (!compareVector("insert range: tenth test: ", stv, ftv))
		return 1;
    return (0);   
}

int execNinthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);
    ft::vector<int>::iterator it = ftv.begin();

    stv.pop_back();
    stv.pop_back();
    stv.pop_back();
    clock_t t = clock();
    stv.insert(stv.begin(), 3, 2);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    ftv.pop_back();
    ftv.pop_back();
    ftv.pop_back();
    t = clock();
    ftv.insert(ftv.begin(), 3, 2);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (it != ftv.begin())
    {
        printError("insert fill: ninth test: realoccation unnecessary", stv, ftv, 0);
        return (0);
    }
    if (!compareVector("insert fill: ninth test: ", stv, ftv))
		return 1;
    return (0);   
}

int execEigthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);
    ft::vector<int>::iterator it = ftv.begin();

    stv.pop_back();
    clock_t t = clock();
    stv.insert(stv.begin(),2);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    ftv.pop_back();
    t = clock();
    ftv.insert(ftv.begin(), 2);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (it != ftv.begin())
    {
        printError("insert single element: eigth test: realoccation unnecessary", stv, ftv, 0);
        return (0);
    }
    if (!compareVector("insert single element: eigth test: ", stv, ftv))
		return 1;
    return (0);   
}

int execSeventhTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    clock_t t = clock();
    stv.insert(stv.begin() + 3, stv.begin() + 6, stv.begin() + 8);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.insert(ftv.begin() + 3, ftv.begin() + 6, ftv.begin() + 8);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("insert range: seventh test: ", stv, ftv))
		return 1;
    return (0);   
}

int execSixthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    clock_t t = clock();
    stv.insert(stv.begin() + 3, stv.begin() + 3, stv.begin() + 5);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.insert(ftv.begin() + 3, ftv.begin() + 3, ftv.begin() + 5);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("insert range: sixth test: ", stv, ftv))
		return 1;
    return (0);   
}

int execFifthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    clock_t t = clock();
    stv.insert(stv.begin() + 3, 4, 2);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.insert(ftv.begin() + 3, 4, 2);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("insert fill: fifth test: ", stv, ftv))
		return 1;
    return (0);   
}

int execFourthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    clock_t t = clock();
    stv.insert(stv.begin(), 0, 2);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.insert(ftv.begin(), 0, 2);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("insert fill: fourth test: ", stv, ftv))
		return 1;
    return (0);   
}

int execThirdTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    clock_t t = clock();
    stv.insert(stv.begin(), 4, 2);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.insert(ftv.begin(), 4, 2);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("insert fill: third test: ", stv, ftv))
		return 1;
    return (0);   
}

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    clock_t t = clock();
    stv.insert(stv.end(), 1);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.insert(ftv.end(), 1);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("insert single element: second test: ", stv, ftv))
		return 1;
    return (0);   
}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    ft::vector<int> ftv;

    clock_t t = clock();
    stv.insert(stv.begin(), 1);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.insert(ftv.begin(), 1);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("insert single element: first test: ", stv, ftv))
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
	result += execSixthTest(&timeFt, &timeStd);
	result += execSeventhTest(&timeFt, &timeStd);
    result += execEigthTest(&timeFt, &timeStd);
    result += execNinthTest(&timeFt, &timeStd);
    result += execTenthTest(&timeFt, &timeStd);
	if (result == 10)
		flag = 1;
	printResult("insert", flag, timeFt, timeStd);
	return (1);
}