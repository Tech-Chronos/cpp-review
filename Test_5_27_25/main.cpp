#include "string.h"

void string_test1()
{
    dsj::string str1;
    dsj::string str2("hello world");
    dsj::string const str3("hello Linux");
    for (size_t i = 0; i < str2.size(); ++i)
    {
        std::cout << str2[i];
    }
    std::cout << std::endl;

    dsj::string::iterator it = str2.begin();
    while (it != str2.end())
    {
        (*it)++;
        std::cout << *it;
        ++it;
    }
    std::cout << std::endl;

    dsj::string::const_iterator cit = str3.begin();
    while (cit != str3.end())
    {
        std::cout << *cit;
        ++cit;
    }
    std::cout << std::endl;
}

void string_test2()
{
    dsj::string str1;
    dsj::string str2("hello world");
    dsj::string const str3("hello Linux");
    std::cout << str1.capacity() << std::endl;
    std::cout << str2.capacity() << std::endl;
    str1.reserve(15);
    str2.reserve(30);
    std::cout << str1.capacity() << std::endl;
    std::cout << str2.capacity() << std::endl;

    str2.resize(2);
    std::cout << str2.capacity() << std::endl;
    std::cout << str2.size() << std::endl;
    std::cout << str2.c_str() << std::endl;
}

void string_test3()
{
    dsj::string str1;
    dsj::string str2("hello world");
//    str1.append("hello Linux");
//    std::cout << str1.c_str() << std::endl;
//
//    str2.append(" hello Linux");
//    std::cout << str2.c_str() << std::endl;
    str2.insert(0,"hello Linux ");
    std::cout << str2.c_str() << std::endl;
    str2.erase(1, 10);
    std::cout << str2.c_str() << std::endl;
}

void string_test4()
{
    dsj::string str1;
    dsj::string str2("hello world");
    dsj::string str3(str2);
    std::cout << str3.c_str() << std::endl;

    str3.append(",hello Linux!");

    dsj::string str4 = str3;
    std::cout << str4.c_str() << std::endl;
}

void string_test5()
{
    dsj::string str1;
    dsj::string str2("hello world");
    str1 += "hello Linux";
    std::cout << "str1 -> " << str1.c_str() << std::endl;
    std::cout << "str2 -> " << str2.c_str() << std::endl;
    dsj::swap(str1, str2);
    std::cout << "str1 -> " << str1.c_str() << std::endl;
    std::cout << "str2 -> " << str2.c_str() << std::endl;
}

void string_test6()
{
    dsj::string str1;
    dsj::string str2("hello world");
    str1 += "hello Linux";
    std::cout << str1.find("Linux") << std::endl;
}

void string_test7()
{
    dsj::string str1;
    dsj::string str2("hello world");
    str1 += "hello Linux";
    std::cout << str1.substr(10).c_str() << std::endl;
}

void string_test8()
{
    dsj::string str1;
    dsj::string str2("hello world");
    str1 += "hello Linux";

    //dsj::operator<<(std::cout, str1);
    std::cout << str1 << std::endl << str2 << std::endl;
}

void string_test9()
{
    dsj::string str1;
    dsj::string str2("hello world");
    str1 += "hello Linux";

    std::cin >> str1 >> str2;

    std::cout << "str1 -> " << str1 << std::endl;
    std::cout << "str2 -> " << str2 << std::endl;
}

int main()
{
    string_test9();
    return 0;
}
