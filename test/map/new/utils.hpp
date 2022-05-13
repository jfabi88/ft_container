#include <iostream>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include <filesystem>
#include <cstdint>
#include <map>
#include "../../../sources/map.hpp"

void printResult(std::string function, int flag, double timeFt, double timeStd)
{
    std::string result = "KO";

    if (flag == 1)
        result = "OK";
    std::cout << std::setw(20) << std::left << function;
    std::cout << std::setw(20) << std::left << result;
    std::cout << std::setw(20) << std::left << (timeFt * 1000);
    std::cout << std::setw(20) << std::left << (timeStd * 1000);
    std::cout << std::endl;
}
