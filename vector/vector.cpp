//
// Created by dsj on 2026/2/21.
//

#include "vector.h"

void test1()
{
    dsj::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(3);

    dsj::vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

void test2()
{
    const dsj::vector<int> v(10u, 6);
    dsj::vector<int>::const_iterator it = v.begin();
    while (it != v.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void test3()
{
    dsj::vector<int> v(10u,2);
    v.reserve(10);
    std::cout << "size() -> " << v.size() << std::endl;
    std::cout << "capacity() -> " << v.capacity() << std::endl;
}

void test4()
{
    dsj::vector<int> v(5u,2);
    v.insert(1, 10);
    v.insert(0, 10);

    v.resize(10, 21);

    v.erase(0);
    v.erase(8);
    for (auto e : v)
    {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

void test5()
{
    dsj::vector<int> v  {1,2,3,4,5,6,7,8};
    for (auto e : v)
    {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

void test6()
{
    dsj::vector<std::string> v;
    v.push_back("11111");
    v.push_back("22222");
    v.push_back("33333");
    v.push_back("44444");
    v.push_back("55555");
    v.push_back("66666");
    v.push_back("77777");
    v.push_back("88888");
    v.push_back("99999");
    v.push_back("00000");

    for (auto& e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test7()
{
    
}

int main()
{
    test6();
    return 0;
}