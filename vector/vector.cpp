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
    v.push_back("11111"); // 调用 push_back 就是构造 + 拷贝构造
    v.push_back("22222"); // 调用 emplace_back 就是 直接构造
    v.push_back("33333");
    v.push_back("44444");
    v.push_back("55555");
    v.push_back("66666");
    v.push_back("77777");
    v.push_back("88888");
    v.push_back("99999");
    v.push_back("00000");

    dsj::vector<std::string> v2 = std::move(v);
    for (auto& e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test7()
{
    dsj::vector<std::string> v;

    v.emplace_back("hello");
}

// template<typename... Args>
// void print(Args... args)
// {
//     (std::cout << ... <<  args);
// }

void print()
{
    std::cout << "\n";
}

template <class T, class ...Rest>
void print(T first, Rest ...rest)
{
    std::cout << first << " ";
    print(rest ...);
}

template<class ...Args>
void out(Args ...args)
{
    (std::cout << ... << args) << " ";

}

void test8()
{
    dsj::vector<std::pair<std::string, std::string>> v;

    v.push_back(std::make_pair("1111", "1111"));
    v.emplace_back("1111","1111");
}

void test9()
{
    dsj::vector<std::pair<std::string, int>> v;
    // strin构造 和 string移动构造
    v.push_back(std::make_pair(std::string("Tom"), 18));

    // 直接就是 string 的构造
    v.emplace_back("Tom", 18);

}

int main()
{
    // print(1,"hello world", 2.0);
    // out(1,"hello world", 2.0);
    test9();
    return 0;
}

// void g(int&)
// {
//     std::cout << "lvalue\n";
// }
//
// void g(int&&)
// {
//     std::cout << "rvalue\n";
// }
//
// template<class T>
// void f(T&& x)
// {
//     g(x);
//     //g(std::move(x));
//     g(std::forward<T>(x));
// }
//
// int main()
// {
//     int a = 10;
//     f(a);
//     f(20);
//
//     int&& b = 10;
// }