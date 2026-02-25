#include <iostream>
#include <string>

class Person
{
public:
    Person()
    {}

    virtual void func()
    {
        std::cout << "I am a person!" << std::endl;
    }

    void SetName(const std::string& name)
    {
        _name = name;
    }

    const std::string& GetName()
    {
        return _name;
    }
private:
    std::string _name;
    static int _count;
};

int Person::_count = 0;

class Student : public Person
{
public:
    void func()
    {
        std::cout << "I am a Student!!!" << std::endl;
    }
private:
    static int _count;
};
int Student::_count = 0;// 隐藏


void test_dynamin()
{
    Person* stu1 = new Student;

    Student st;
    Person& stu2 = st;

    stu1->func();
    stu2.func();
}

class A
{
public:
    void fun()
    {
        std::cout << "func()" << std::endl;
    }
};
class B : public A
{
public:
    void fun(int i)
    {
        A::fun();
        std::cout << "func(int i)->" << i << std::endl;
    }
};

void Test()
{
    B b;
    b.fun(10);
};

class C
{
public:
    int _c;
};

class D : virtual public C
{
public:
    int _d;
};

class E : virtual public C
{
public:
    int _e;
};

class F : public D, public E
{
public:
    int _f;
};

void TEST()
{
    F f;
    f._d = 10;
    f._e = 20;
    f.D::_c = 3;
    f.E::_c = 4;
    f._f = 30;
}

int main()
{
    test_dynamin();
    return 0;
}
