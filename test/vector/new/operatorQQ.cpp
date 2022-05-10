#include "utils.hpp"

std::string computeError(std::string function, int valStd, int valFt, int index)
{
    std::ostringstream os;

    os << "operator[]: " << function;
    os << ": std[" << index << "] = " << valStd;
    os << ", ft[" << index << "] = " << valFt;
    os << "\n";
    return (os.str());
}

int execThirdTest(double *timeFt, double *timeStd)
{
    const std::vector<int>  stv(10, 10);
    const ft::vector<int>   ftv(10, 10);
    int                     index = 9;
    int                     retStd;
    int                     retFt;

    clock_t t = clock();
    retStd = stv[index];
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    retFt = ftv[index];
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (retStd != retFt)
    {
        std::string error = computeError("thirdtest", retStd, retFt, index);
        printError(error, stv, ftv, 4);
        return (0);
    }
    return (1);
}

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int>    stv(10, 10);
    ft::vector<int>     ftv(10, 10);
    int             index = 9;
    int             retStd;
    int             retFt;

    clock_t t = clock();
    retStd = stv[index];
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    retFt = ftv[index];
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (retStd != retFt)
    {
        std::string error = computeError("second test", retStd, retFt, index);
        printError(error, stv, ftv, 4);
        return (0);
    }
    return (1);
}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(2);
    ft::vector<int> ftv(2);
    int             index = 0;
    int             retStd;
    int             retFt;

    clock_t t = clock();
    retStd = stv[index];
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    retFt = ftv[index];
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (retStd != retFt)
    {
        std::string error = computeError("first test", retStd, retFt, index);
        printError(error, stv, ftv, 4);
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
	if (result == 3)
		flag = 1;
	printResult("operator[]", flag, timeFt, timeStd);
	return (1);
}
