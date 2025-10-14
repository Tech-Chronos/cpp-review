#include <iostream>
#include <string>
#include "string.h"
#include "List.h"

using namespace std;

//template <class T>
//int Print(T t)
//{
//    cout << t << " ";
//    return 0;
//}
//
//template<class ...Args>
//void PrintArg(Args ...args)
//{
//    int arr[] = {Print(args)...};
//}
//
//void ShowList()
//{
//    cout << endl;
//}
//
//template <class T, class ...Args>
//void ShowList(T t, Args ...args)
//{
//    cout << t << " ";
//    ShowList(args...);
//}

//int main()
//{
//    cout << "PrintArg: ";
//    PrintArg(1,"string",3);
//
//    cout << endl;
//
//    cout << "ShowList: ";
//    ShowList(1,"string",3);
//    return 0;
//}



//void PrintArg()
//{
//    cout << endl;
//}
//
//template <class T, class ...Args>
//void PrintArg(T t, Args ...args)
//{
//    cout << t << endl;
//    PrintArg(args...);
//}

//template<class T, class ...Args>
//void ShowPrint(T t, Args ...args)
//{
//    int arr = { (PrintArgs(args...),0) };
//}

//int main()
//{
//    //ShowPrint(1,"string",3);
//    return 0;
//}
//
//// 可变参数
//void CPP_Printf()
//{
//    cout << endl;
//}
//
//template <class T, class ...Args>
//void CPP_Printf(T t, Args ...args)
//{
//    cout << t << endl;
//    CPP_Printf(args...);
//}
//
//
//int main()
//{
//    CPP_Printf(1);
//    CPP_Printf(1,"sort");
//    CPP_Printf(1,"string",3);
//}




//int main()
//{
//    dsj::list<dsj::string> ls;
//
//
//    dsj::string str = "111111";
//
//    ls.push_back(str);
//
//    ls.push_back(dsj::string("22222"));
//
//
//    return 0;
//}

//void test1()
//{
//    cout << "test1" << endl;
//
//    dsj::list<pair<dsj::string, int>> ls;
//    cout << endl;
//    ls.push_back({"董思妍", 6});
//
//    cout << endl;
//    ls.emplace_back("董思杰", 22);
//
//    cout << "---------------------------" << endl;
//}
//
//void test2()
//{
//    cout << "test2" << endl;
//    cout << "构造list对象" << endl;
//    dsj::list<dsj::string> ls;
//    cout << endl;
//
//    cout << "插入左值" << endl;
//    dsj::string str("111111");
//    ls.push_back(str);
//    cout << endl;
//
//
//    cout << "插入右值" << endl;
//    ls.push_back("2222222");
//    cout << endl;
//
//    cout << "可变参数" << endl;
//    ls.emplace_back("333333");
//    cout << endl;
//
//}
//
//int main()
//{
//    test1();
//    test2();
//    return 0;
//}

struct Goods
{
    string _name; // 名字
    double _price; // 价格
    int _evaluate; // 评价
    Goods(const char* str, double price, int evaluate)
            :_name(str)
            , _price(price)
            , _evaluate(evaluate)
    {}
};

void test() {
    vector<Goods> v = {
            {"苹果", 2.1, 5},
            {"香蕉", 3,   4},
            {"橙子", 2.2, 3},
            {"菠萝", 1.5, 4}
    };

    auto compare = [](const Goods &g1, const Goods &g2)mutable -> bool {
        return g1._price < g2._price;
    };

    sort(v.begin(), v.end(), compare);

    int i = 0;
}

int main()
{
    test();
    return 0;
}