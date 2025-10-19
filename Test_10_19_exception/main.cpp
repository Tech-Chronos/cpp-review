#include <iostream>
#include <string>

using namespace std;

// 1. 普通异常

//double division(double left, double right)
//{
//    if (right == 0)
//    {
//        throw(string("divide zero!"));
//    }
//    else
//    {
//        return left / right;
//    }
//}
//
//void func(double left, double right)
//{
//    try
//    {
//        division(left, right);
//    }
//    catch (string str)
//    {
//        cout << "divide zero fault" << endl;
//    }
//}
//
//int main()
//{
//    try
//    {
//        func(2,0);
//    }
//    catch (string& str)
//    {
//        cout << "divide zero fault!" << endl;
//    }
//    return 0;
//}


// 2. 异常重新抛出

//double division(double left, double right)
//{
//    if (right == 0)
//    {
//        throw ("divide zero fault!");
//    }
//    return left / right;
//}
//
//void func()
//{
//    int *arr = new int[10];
//    double left = 0;
//    double right = 0;
//    try
//    {
//        cin >> left >> right;
//        division(left, right);
//    }
//    catch (...)
//    {
//        delete[] arr;
//        // throw 是获取到什么抛出什么
//        throw;
//    }
//
//    delete[] arr;
//}
//
//int main()
//{
//    try
//    {
//        func();
//    }
//    catch(const char* errmsg)
//    {
//        cout << errmsg << endl;
//    }
//
//    return 0;
//}


//int main()
//{
//    try
//    {
//        vector<int> v(10, 5);
//        // 这里如果系统内存不够也会抛异常
//        v.reserve(1000000000);
//        // 这里越界会抛异常
//        v.at(10) = 100;
//    }
//    catch (const exception& e) // 这里捕获父类对象就可以
//    {
//        cout << e.what() << endl;
//    }
//    catch (...)
//    {
//        cout << "Unkown Exception" << endl;
//    }
//    return 0;
//}