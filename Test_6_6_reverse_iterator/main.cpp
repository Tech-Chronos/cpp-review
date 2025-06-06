#include "list.h"
#include <list>

void list_test1()
{
    std::list<int> ls = {1,2,3,4,5,6,7};
    std::list<int>::reverse_iterator rit = ls.rbegin();
    while (rit != ls.rend())
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
}

void list_test2()
{
    dsj::list<int> ls = {0,1,2,3,4,5,6,7};
    dsj::list<int>::reverse_iterator rit = ls.rbegin();
    while (rit != ls.rend())
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
}
int main()
{
    list_test2();
    return 0;
}
