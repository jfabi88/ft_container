#include "utils.hpp"

int execTenthTest()
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    try {
        stv.resize(stv.max_size() + 10);
    }
    catch (std::exception &e) {}

    try {
        ftv.resize(ftv.max_size() + 10);
        printError("resize: tenth test: exception doesn't throw", stv, ftv, 0);
        return (0);
    }
    catch (std::exception &e) {}

    if (!compareVector("resize: tenth test: ", stv, ftv))
		return 1;
    return (0);
}

int execNinthTest()
{
    std::vector<int> stv;
    ft::vector<int> ftv;

    try {
        stv.resize(-9);
    }
    catch (std::exception &e) {}

    try {
        ftv.resize(-9);
        printError("resize: ninth test: exception doesn't throw", stv, ftv, 0);
        return (0);
    }
    catch (std::exception &e) {}

    if (!compareVector("resize: ninth test: ", stv, ftv))
		return 1;
    return (0);
}

int execEighthTest()
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    try {
        stv.resize(-9);
    }
    catch (std::exception &e) {}

    try {
        ftv.resize(-9);
        printError("resize: eighth test: exception doesn't throw", stv, ftv, 0);
        return (0);
    }
    catch (std::exception &e) {}

    if (!compareVector("resize: eighth test: ", stv, ftv))
		return 1;
    return (0);
}

int execSeventhTest()
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    try {
        stv.resize(-9, 9);
    }
    catch (std::exception &e) {}

    try {
        ftv.resize(-9, 9);
        printError("resize: seventh test: exception doesn't throw", stv, ftv, 0);
        return (0);
    }
    catch (std::exception &e) {}

    if (!compareVector("resize: seventh test: ", stv, ftv))
		return 1;
    return (0);
}

int execSixthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    clock_t t = clock();
    stv.resize(10000000, 9);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.resize(10000000, 9);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("resize: sixth test: ", stv, ftv))
		return 1;
    return (0);
}

int execFifthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    clock_t t = clock();
    stv.resize(0);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.resize(0);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("resize: fifth test: ", stv, ftv))
		return 1;
    return (0);
}

int execFourthTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    clock_t t = clock();
    stv.resize(5);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.resize(5);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("resize: fourth test: ", stv, ftv))
		return 1;
    return (0);
}

int execThirdTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    clock_t t = clock();
    stv.resize(11);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.resize(11);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("resize: third test: ", stv, ftv))
		return 1;
    return (0);
}

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    clock_t t = clock();
    stv.resize(10);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.resize(10);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("resize: second test: ", stv, ftv))
		return 1;
    return (0);
}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv;
    ft::vector<int> ftv;

    clock_t t = clock();
    stv.resize(3, 2);
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.resize(3, 2);
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (!compareVector("resize: first test: ", stv, ftv))
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
    result += execSeventhTest();
    result += execEighthTest();
    result += execNinthTest();
    result += execTenthTest();
	if (result == 10)
		flag = 1;
	printResult("resize", flag, timeFt, timeStd);
	return (1);
}