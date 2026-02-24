//
// Created by dsj on 2026/2/24.
//

#include "list.h"

using namespace std;
void list_test1()
{
    dsj::list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);
    dsj::list<int>::iterator it = lt.begin();
    while (it != lt.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    lt.pop_back();
    lt.pop_back();
    it = lt.begin();
    while (it != lt.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    lt.push_front(100);
    lt.push_front(200);
    lt.push_front(300);
    it = lt.begin();
    while (it != lt.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    lt.pop_front();
    lt.pop_front();
    it = lt.begin();
    while (it != lt.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void list_test2()
{
    dsj::list<std::pair<std::string, std::string>> lt;
    lt.push_back({"hello","world"});

    for (auto it = lt.begin(); it != lt.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

struct A
{
    int a1;
    int a2;
    int a3;
    A(int a, int b, int c)
        :a1(a)
        ,a2(b)
        ,a3(c)
    {}

    A() {}
};

void list_test3()
{
    dsj::list<A> tmp;
    tmp.push_back({1,2,3});
}

void list_test4()
{
    dsj::list<std::string> other({"hello"," ", "world",", ", "hello", " ", "Linux!"});
    dsj::list<std::string> tmp(std::move(other));
    int i = 0;

//    for (auto& e : other)
//    {
//        std::cout << e;
//    }
//    std::cout << "\n";
    for (auto& e : tmp)
    {
        std::cout << e;
    }
}

int main()
{
    list_test4();
    return 0;
}
