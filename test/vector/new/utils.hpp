#include <iostream>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include "../../../sources/vector.hpp"

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

std::string printVector(ft::vector<int> vec)
{
    std::ostringstream oss;
    std::string ret = "[";
    ft::vector<int>::iterator it;

    it = vec.begin();
    if (it != vec.end())
    {
        oss << *it;
        ret += oss.str();
        oss.str("");
        it++;
    }
    for (; it < vec.end(); it++)
    {
        ret += ", ";
        oss << *it;
        ret += oss.str();
        oss.str("");
    }
    ret += "]\n";
    oss << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << "\n";
    ret += oss.str();
    return ret;
}

std::string printVector(std::vector<int> vec)
{
    std::ostringstream oss;
    std::string ret = "[";
    std::vector<int>::iterator it;

    it = vec.begin();
    if (it != vec.end())
    {
        oss << *it;
        ret += oss.str();
        it++;
    }
    for (; it < vec.end(); it++)
    {
        ret += ", ";
        oss.str("");
        oss << *it;
        ret += oss.str();
    }
    ret += "]\n";
    oss.str("");
    oss << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << "\n";
    ret += oss.str();
    return ret;
}

int printError(std::string position, std::vector<int> sv, ft::vector<int> fv, int eid)
{
    std::string toWrite;
    int fd = open("log.txt", O_RDWR | O_CREAT | O_APPEND, 0777);

    toWrite = position;
    if (eid == 1)
        toWrite += "vector differs\n";
    else if (eid == 2)
        toWrite += "size differs\n";
    else if (eid == 3)
        toWrite += "capacity differs\n";
    toWrite += "STD: ";
    toWrite += printVector(sv);
    toWrite += "FT: ";
    toWrite += printVector(fv);
   if (eid == 0)
        toWrite = position + "\n";
    write(fd, toWrite.c_str(), toWrite.size());
    close(fd);
    return (1);
}

int sameVector(std::vector<int> sv, ft::vector<int> fv)
{
    std::vector<int>::iterator  sit;
    ft::vector<int>::iterator  fit;

    sit = sv.begin();
    fit = fv.begin();
    for (; sit < sv.end(); sit++)
    {
        if (*sit != *fit)
            return (1);
        fit++;
    }
    return (0);
}

int compareVector(std::string function, std::vector<int> sv, ft::vector<int> fv)
{
    if (sv.size() != fv.size())
		return (printError(function, sv, fv, 2));
	else if (sv.capacity() != fv.capacity())
		return (printError(function, sv, fv, 3));
	else if (sameVector(sv, fv))
		return (printError(function, sv, fv, 1));
    return (0);
}
