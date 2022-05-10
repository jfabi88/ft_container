#include "utils.hpp"

int execTest(double *timeFt, double *timeStd)
{
    std::vector<int> stv(10, 10);
    ft::vector<int> ftv;

    clock_t t = clock();
    try {
        stv.assign(stv.max_size() - 100, 3);
    }
    catch  (std::exception &e) {}
    t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

    std::cout << printVector(stv) << std::endl;
    t = clock();
    t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC; 

    return (1);
}

int execFirstTest(double *timeFt, double *timeStd)
{

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
	printResult("assign fill", flag, timeFt, timeStd);
	return (1);
}