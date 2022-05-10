#include "utils.hpp"

std::string computeError(std::string function, int valStd, int valFt)
{
    std::ostringstream os;

    os << "front: " << function;
    os << ": std = " << valStd;
    os << ", ft = " << valFt;
    os << "\n";
    return (os.str());
}

int execFourthTest(double *timeFt, double *timeStd)
{
    const std::vector<int>    stv(10, 10);
    const ft::vector<int>     ftv(10, 10);
    int             retStd;
    int             retFt;

    clock_t t = clock();
    retStd = stv.front();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    retFt = ftv.front();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (retStd != retFt)
    {
        std::string error = computeError("second test", retStd, retFt);
        printError(error, stv, ftv, 4);
        return (0);
    }
    return (1);
}

int execThirdTest(double *timeFt, double *timeStd)
{
    const std::vector<int> stv(2);
    const ft::vector<int> ftv(2);
    int             retStd;
    int             retFt;

    clock_t t = clock();
    retStd = stv.front();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    retFt = ftv.front();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (retStd != retFt)
    {
        std::string error = computeError("third test", retStd, retFt);
        printError(error, stv, ftv, 4);
        return (0);
    }
    return (1);
}

int execSecondTest(double *timeFt, double *timeStd)
{
    std::vector<int>    stv(10, 10);
    ft::vector<int>     ftv(10, 10);
    int             retStd;
    int             retFt;

    clock_t t = clock();
    retStd = stv.front();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    retFt = ftv.front();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (retStd != retFt)
    {
        std::string error = computeError("second test", retStd, retFt);
        printError(error, stv, ftv, 4);
        return (0);
    }
    return (1);
}

int execFirstTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(2);
    ft::vector<int> ftv(2);
    int             retStd;
    int             retFt;

    clock_t t = clock();
    retStd = stv.front();
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    t = clock();
    retFt = ftv.front();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    if (retStd != retFt)
    {
        std::string error = computeError("first test", retStd, retFt);
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
    result += execFourthTest(&timeFt, &timeStd);
	if (result == 4)
		flag = 1;
	printResult("front", flag, timeFt, timeStd);
	return (1);
}
