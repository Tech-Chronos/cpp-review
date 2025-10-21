#include <iostream>
#include <string>

using namespace std;

//void func()
//{
//    size_t i = 0;
//    while ((int)i >= 0)
//    {
//        cout << i << endl;
//        --i;
//    }
//}

//void func()
//{
////    size_t i = 10;
////    int j = -20;
////    int k = i + j;
////    cout << k << endl;
//
//}

//void func()
//{
//    int i = 10;
//    //double j = static_cast<double>(i);
//    double j = 3.14;
//
//    int k = static_cast<int>(j);
//}

//class Base {
//public:
//    virtual ~Base() = default;
//    virtual void show() { std::cout << "Base" << std::endl; }
//};
//
//class Derived : public Base {
//public:
//    void show() override { std::cout << "Derived" << std::endl; }
//    void specific() { std::cout << "Derived specific" << std::endl; }
//};
//
//void func()
//{
//    Derived derive;
////    Base* bptr = &derive;
////    bptr->show();
//    Base* bptr = static_cast<Base*>(&derive);
//    bptr->show();
//}


//void func()
//{
//    volatile const int a = 10;
//
//    int *ptr = (int*)&a;
//
//    ++(*ptr);
//
//    cout << &a << endl;
//    cout << ptr << endl;
//
//    cout << a << endl;
//    cout << *ptr << endl;
//}

//void modifystring(string& str)
//{
//    str += " world!";
//}
//
//void func()
//{
//    const string str = "hello";
//    modifystring(const_cast<string&>(str));
//    cout << str << endl;
//}

void func()
{
//    string str = "hello";
//    const string& s = const_cast<const string&>(str);
//    volatile int sensor_data = 100;
//    int* normal_ptr = const_cast<int*>(&sensor_data);
//    *normal_ptr = 200;
//    //sensor_data = 200;
//
//    std::cout << "传感器数据: " << sensor_data << std::endl;

}

int main()
{
    func();
//    unsigned int i = 20;
//    int j = -10;
//    cout << i + j << endl;

    return 0;
}
