#include "String.h"

void test_string1()
{
    dsj::string str1;
    dsj::string str2 = "hello world";
    char ch = str2.operator[](0);
    char ch1 = str2[2];
    cout << ch << endl;
    cout << ch1 << endl;
}

void test_string2()
{
    dsj::string str1 = "hello Linux!";
    dsj::string str2 = "hello world";
    dsj::string::iterator it = str1.begin();
    while (it != str1.end())
    {
        --(*it);
        cout << *it;
        ++it;
    }
    cout << endl;
    dsj::string::const_iterator ct_it = str2.begin();
    while (ct_it != str2.end())
    {
        cout << *ct_it;
        ++ct_it;
    }
    cout << endl;

    it = str1.begin();
    for (auto ch : str1)
    {
        cout << *it;
        ++it;
    }
}

void test_string3()
{
    dsj::string str1 = "hello Linux";
    dsj::string str2;
    str1 += " hello";
    str2 += "hello";
    str1.c_str();
    str2.c_str();
}

void test_string4()
{
    dsj::string str1 = "hello Linux";
    dsj::string str2;
    //str1.insert(1,'x');
    str1.insert(0,"o");
    str1.c_str();
}

int main()
{
    test_string4();
    return 0;
}
