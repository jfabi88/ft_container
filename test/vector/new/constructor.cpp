#include "utils.hpp"

int execSeventhTest(double *timeFt, double *timeStd)
{
	std::vector<int>			sv1(10, 10);
	std::vector<int>::iterator	sitB;
	std::vector<int>::iterator	sitE;

	sitB = sv1.begin();
	sitE = sv1.end();
	clock_t t = clock();
	std::vector<int>	sv2(sitB, sitE);
	t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

	ft::vector<int>	fv1(10, 10);
	ft::vector<int>::iterator	fitB;
	ft::vector<int>::iterator	fitE;

	fitB = fv1.begin();
	fitE = fv1.end();
	t = clock();
	ft::vector<int>	fv2(fitB, fitE);
	t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC;

	if (!compareVector("constructor: seventh test: ", sv2, fv2))
		return 1;
	return (0);
}

int execSixthTest(double *timeFt, double *timeStd)
{
	std::vector<int>	sv1(10, 10);
	clock_t t = clock();
	std::vector<int>	sv2 = sv1;
	t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

	ft::vector<int>	fv1(10, 10);
	t = clock();
	ft::vector<int>	fv2 = fv1;
	t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC;

	if (!compareVector("constructor: sixth test: ", sv2, fv2))
		return 1;
	return (0);
}

int execFifthTest(double *timeFt, double *timeStd)
{
	std::vector<int>	sv1(10, 10);
	clock_t t = clock();
	std::vector<int>	sv2(sv1);
	t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

	ft::vector<int>	fv1(10, 10);
	t = clock();
	ft::vector<int>	fv2(fv1);
	t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC;

	if (!compareVector("constructor: fifth test: ", sv2, fv2))
		return 1;
	return (0);
}

int execFourthTest()
{
	std::vector<int> sv;
	ft::vector<int> fv;

	try {
		std::vector<int>	sv(-1, 10);
	}
	catch (std::exception &e) {}

	try {
		ft::vector<int>	fv(-1, 10);
	}
	catch (std::exception &e) { return 1; }
	printError("constructor: fourth test: the constructor doesn't throw the exception", sv, fv, 0);
	return (0);
}

int execThirdTest(double *timeFt, double *timeStd)
{
	clock_t t = clock();
	std::vector<int>	sv(100000, 10);
	t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

	t = clock();
	ft::vector<int>	fv(100000, 10);
	t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC;

	if (!compareVector("constructor: third test: ", sv, fv))
		return 1;
	return (0);
}

int execSecondTest(double *timeFt, double *timeStd)
{
	clock_t t = clock();
	std::vector<int>	sv(10);
	t = clock() - t;
	*timeStd += ((double)t) / CLOCKS_PER_SEC;

	t = clock();
	ft::vector<int>	fv(10);
	t = clock() - t;
	*timeFt += ((double)t) / CLOCKS_PER_SEC;

	if (!compareVector("constructor: second test: ", sv, fv))
		return 1;
	return (0);
}

int execFirstTest(double *timeFt, double *timeStd)
{
	std::vector<int>	sv;
	ft::vector<int>		fv;

	*timeFt += 0;
	*timeStd += 0;
	if (!compareVector("constructor: first test: ", sv, fv))
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
	result += execFourthTest();
	result += execFifthTest(&timeFt, &timeStd);
	result += execSixthTest(&timeFt, &timeStd);
	result += execSeventhTest(&timeFt, &timeStd);
	if (result == 7)
		flag = 1;
	printResult("constructor", flag, timeFt, timeStd);
	return (1);
}
