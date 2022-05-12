#include "utils.hpp"

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int>    stv(12, 12);
    ft::vector<int>     ftv(12, 12);
    std::vector<int>    stv2(100000000, 3);
    ft::vector<int>     ftv2(100000000, 3);

    clock_t t = clock();
    stv.assign(stv2.begin(), stv2.end());
    t = clock() - t;
    *timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.assign(ftv2.begin(), ftv2.end());
    t = clock() - t;
    *timeFt += ((double)t) / CLOCKS_PER_SEC;

    if (!compareVector("assign range: second test: ", stv, ftv))
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
    stv.assign(stv2.begin(), stv2.end());
	t = clock() - t;
    *timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    ftv.assign(ftv2.begin(), ftv2.end());
    t = clock() - t;
    *timeFt += ((double)t) / CLOCKS_PER_SEC;

    if (!compareVector("assign range: first test: ", stv, ftv))
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
	if (result == 2)
		flag = 1;
	printResult("assign range", flag, timeFt, timeStd);
	return (1);
}
