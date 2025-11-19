#include <iostream>
#include <unistd.h>
#include <signal.h>

int sum(int begin, int end)
{
    int ret = 0;
    while (begin <= end)
    {
        ret += begin;
        ++begin;
    }
    ret /= 0;
    return ret;
}

int main()
{
    int pid = fork();

    if (pid == 0)
    {
        int ret = sum(0,100);
        std::cout << ret << std::endl;
        exit(0);
    }

    int status = 0;
    waitpid(pid, &status, 0);

    std::cout << "exit code = " << ((status >> 8) & 0xff) << std::endl;
    std::cout << "exit signal = " << (status & 0x7f) << std::endl;

    std::cout << "core dump = " << ((status >> 7) & 0x1) << std::endl;
    return 0;
}
