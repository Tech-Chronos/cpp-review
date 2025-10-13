#include <iostream>
#include <vector>
#include <string>

#include "mystring.h"
using namespace std;
namespace dsj
{
    dsj::string to_string(int i)
    {
        dsj::string str;
        bool flag = true;

        if (i < 0)
        {
            flag = false;
            i = -i;
        }

        while (i)
        {
            int tmp = i % 10;
            str.push_back(tmp + '0');
            i /= 10;
        }

        if (!flag)
        {
            str.push_back('-');
        }

        std::reverse(str.begin(), str.end());

        return std::move(str);
    }
}


int main()
{

    string&& str1 = string("111111111111");


    str1.push_back('1');
    string str2 = str1;


    string str3 = string("3435");
    cout << str1 << endl;

//    dsj::string str = dsj::to_string(10);
//
//    cout << str << endl;

//    dsj::string&& ss = dsj::string("111");
//
//    dsj::string str;
//
//    str = ss;
//
//    cout << str << endl;
    return 0;
}





//class MyClass
//{
//public:
//    MyClass() { std::cout << "Default Constructor\n"; }
//    MyClass(const MyClass&) { std::cout << "Copy Constructor\n"; }
//    MyClass(MyClass&&) { std::cout << "Move Constructor\n"; }
//    ~MyClass() { std::cout << "Destructor\n"; }
//};

//int main()
//{
//    const auto& my = MyClass();
//
//
//    return 0;
//}

//int main()
//{
//    vector<pair<string, string>> v = {
//            {"insert", "插入"},
//            {"delete", "删除"}
//    };
//
//
//    return 0;
//}
