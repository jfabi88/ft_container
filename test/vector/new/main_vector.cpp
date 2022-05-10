#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <map>

typedef std::map<std::string, std::string> testMap;
testMap setMap()
{
    testMap ret;


    ret.insert(testMap::value_type("constructor.cpp", "constructor"));
    ret.insert(testMap::value_type("size.cpp", "size"));
    ret.insert(testMap::value_type("capacity.cpp", "capacity"));
    ret.insert(testMap::value_type("resize.cpp", "resize"));
    ret.insert(testMap::value_type("empty.cpp", "empty"));
    ret.insert(testMap::value_type("reserve.cpp", "reserve"));
    ret.insert(testMap::value_type("operatorQQ.cpp", "operator[]"));
    ret.insert(testMap::value_type("at.cpp", "at"));
    ret.insert(testMap::value_type("front.cpp", "front"));
    ret.insert(testMap::value_type("back.cpp", "back"));
    ret.insert(testMap::value_type("assign_fill.cpp", "assign fill"));
    return (ret);
}

void compileTest(int *status, char *path, char *env[])
{
    int fd = open("log.txt", O_RDWR | O_CREAT | O_APPEND, 0777);
    pid_t   pid;
    char    **command = (char **)malloc(sizeof(char *) * 9);

    command[0] = strdup("/usr/bin/clang++");
    command[1] = strdup("-std=c++98");
    command[2] = strdup("-Wall");
    command[3] = strdup("-Wextra");
    command[4] = strdup("-Werror");
    command[5] = strdup(path);
    command[6] = strdup("-o");
    command[7] = strdup("exec");
    command[8] = NULL;
    pid = fork();
    if (!pid) {
        dup2(fd, 2);
        close(fd);
        execve(command[0], command, env);
        std::string error = "execve: error: ";
        error += strerror(errno);
        error += "\n";
        write(2, error.c_str(), error.size());
        exit(errno);
    }
    close(fd);
    waitpid(pid, status, 0);
    for (int i = 0; i < 8; i++)
        free(command[i]);
    free (command);
}

void execTest(char *env[])
{
    int *status;
    pid_t pid;
    char **command = (char **)malloc(sizeof(char *) * 2);

    command[0] = strdup("./exec");
    command[1] = NULL;
    pid = fork();
    if (!pid)
    {
        execve(command[0], command, env);
    }
    waitpid(pid, status, 0);
    free(command[0]);
    free(command);
}

void runTest(char *path, char *env[], testMap map)
{
    int status = 0;

    compileTest(&status, path, env);
    if (status == 0) {
        execTest(env);
    }
    else if (status == 256) {
        std::cout << std::setw(20) << std::left << map.at(path);
        std::cout << std::setw(20) << std::left << "NOT COMPILED";
        std::cout << std::endl;
    }
    else
    {
        std::cout << std::setw(20) << std::left << map.at(path);
        std::cout << std::setw(20) << std::left << "UNKOWN";
        std::cout << std::endl;
    }
    
}

int main(int argc, char *argv[], char *env[])
{
    testMap map = setMap();
    int fd = open("log.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
    close (fd);

	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|                                          VECTOR                                          |" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;

    std::cout << std::setw(20) << std::left << "FUNCTION";
    std::cout << std::setw(20) << std::left << "RESULT";
    std::cout << std::setw(20) << std::left << "FT_TIME";
    std::cout << std::setw(20) << std::left << "STD_TIME";
    std::cout << std::endl;

    for (int i = 1; i < argc; i++)
        runTest(argv[i], env, map);
}