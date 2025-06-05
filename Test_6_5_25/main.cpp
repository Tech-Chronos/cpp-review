#include "list.h"

void list_test1()
{
    dsj::list<int> ls;
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);
    dsj::list<int>::iterator it1 = ls.begin();
    //dsj::list<int>::iterator it2 = ls.end();
    while (it1 != ls.end())
    {
        std::cout << *it1 << " ";
        it1++;
    }
    std::cout << std::endl;
}

void list_test2()
{
    dsj::list<int> ls;
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);
    ls.push_back(5);
    for (auto e : ls)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    ls.push_front(10);
    ls.push_front(20);
    ls.push_front(30);
    ls.push_front(40);
    for (auto e : ls)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    ls.pop_back();
    ls.pop_back();
    ls.pop_back();
    ls.pop_front();
    ls.pop_front();
    ls.pop_front();
    for (auto e : ls)
    {
        std::cout << e << " ";
    }
}

struct A
{
public:
    A(int num1 = 0, int num2 = 0)
            :_num1(num1)
            ,_num2(num2)
    {}

    int _num1;
    int _num2;
};

void list_test3()
{
    A aa1 = {1,2};
    dsj::list<A> ls;
    ls.push_back(aa1);
    dsj::list<A>::iterator it1 = ls.begin();
    std::cout << (*it1)._num1 << std::endl;
    std::cout << it1.operator->()->_num1 << std::endl;
    std::cout << it1->_num1 << std::endl;
    //std::cout << typeid(*(it1)._node).name() << std::endl;
    std::cout << std::endl;
}

void list_test4()
{
    const dsj::list<int> ls = {1,2,3,4,5,5,6};

    dsj::list<int>::const_iterator cit1 = ls.begin();
    while (cit1 != ls.end())
    {
        std::cout << *cit1 << std::endl;
        ++cit1;
    }
}

void list_test5()
{
    dsj::list<int> ls;
    ls.push_back(1);
    ls.push_back(1);
    ls.push_back(1);
    for (auto& e : ls)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void list_test6()
{
    dsj::list<int> ls;
    ls.push_back(1);
    ls.push_back(1);
    ls.push_back(1);
    for (auto& e : ls)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    dsj::list<int> ls2 = {1,2,3,4,5,6,7};
    ls = ls2;
    for (auto& e : ls)
    {
        std::cout << e << " ";
    }
}
int main()
{
    list_test6();
    return 0;
}
