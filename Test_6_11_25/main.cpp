#include <iostream>
using namespace std;
typedef void (*fp) (); // 定义函数指针

class Base {
public :
    virtual void func1() { cout<<"Base::func1" <<endl;}
    virtual void func2() {cout<<"Base::func2" <<endl;}

    virtual ~Base()
    {
        cout << "~Base()" << endl;
    }
private :
    int a = 1;
};
class Derive :public Base {
public :
    virtual void func1() {cout<<"Derive::func1" <<endl;}
    virtual void func3() {cout<<"Derive::func3" <<endl;}
    virtual void func4() {cout<<"Derive::func4" <<endl;}

    ~Derive() override
    {
        cout << "~Derive()" <<endl;
    }
private :
    int b = 2;
};


void print_VTB(fp* vfptr)
{
    for (size_t i = 0; i < 4; ++i)
    {
        fp vf = vfptr[i];
        (*vf)();
    }
}

int main()
{
    Base* b1 = new Base;
    Base* b2 = new Derive;

//    cout << sizeof(uint64_t) << endl;
//    fp* vfptr1 = (fp*)((*((uint64_t *)b1)));
//    print_VTB(vfptr1);
//
//    fp* vfptr2 = (fp*)((*((uint64_t *)b2)));
//    print_VTB(vfptr2);

    delete b1;
    delete b2;
    return 0;
}

//class People
//{
//public:
//    virtual void buy_ticket()
//    {
//        std::cout << "成人->全价票" << std::endl;
//    }
//
//    void func1()
//    {
//        std::cout << "People:void func1()" << std::endl;
//    }
//
//    virtual ~People()
//    {
//        std::cout << "~People()" << std::endl;
//    }
//private:
//    int _i = 1;
//    int _k = 2;
//};
//
//class Student : public People
//{
//public:
//    void buy_ticket () override
//    {
//        std::cout << "学生->半价票" << std::endl;
//    }
//
//    // 不构成多态
//    void func1()
//    {
//        People::func1();
//        std::cout << "Student:void func1()" << std::endl;
//    }
//
//    ~Student() override
//    {
//        std::cout << "~Student()" << std::endl;
//    }
//public:
//    int _j = 2;
//};
//
//void test1(People* people)
//{
//    people->buy_ticket();
//}
//
//int main()
//{
//    People* p1 = new People;
//    People* p2 = new Student;
//
////    p2->func1();
//    test1(p1);
//    test1(p2);
//    delete p1;
//    delete p2;
//    return 0;
//}
