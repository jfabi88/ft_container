#include "utils.hpp"

int execThirdTest()
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv(10, 10);

    try {
        stv.assign(stv.max_size(), 3);
    }
    catch  (std::exception &e) {}

    try {
        ftv.assign(ftv.max_size(), 3);
    }
    catch  (std::exception &e) {}

    if (!compareVector("assign fill: third test: ", stv, ftv))
        return (1);
    return (0);
}

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int>    stv(12, 12);
    ft::vector<int>     ftv(12, 12);

    clock_t t = clock();
    stv.assign(100000000, 3);
    t = clock() - t;
    *timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.assign(100000000, 3);
    t = clock() - t;
    *timeFt += ((double)t) / CLOCKS_PER_SEC;

    if (!compareVector("assign fill: second test: ", stv, ftv))
        return (1);
    return (0);

}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int>    stv(12, 12);
    ft::vector<int>     ftv(12, 12);
    std::vector<int>    stv2(2, 3);
    ft::vector<int>     ftv2(2, 3);

    clock_t t = clock();
    t = clock() - t;
    stv.assign(2, 3);
    *timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.assign(2, 3);
    t = clock() - t;
    *timeFt += ((double)t) / CLOCKS_PER_SEC;

    if (!compareVector("assign fill: first test: ", stv, ftv))
        return (1);
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
    result += execThirdTest();
	if (result == 3)
		flag = 1;
	printResult("assign fill", flag, timeFt, timeStd);
	return (1);
}