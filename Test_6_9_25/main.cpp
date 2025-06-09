#include <iostream>
#include <string>
#include <vector>
class Person
{
public:
    Person() = default;
    Person(int age, std::string name, double height)
      :_age(age)
      ,_name(name)
      ,_height(height)
    {
        std::cout << "Person(int age, std::string name, double height)" << std::endl;
    }
    void func()
    {
        std::cout << _height << std::endl;
    }
public:
    int _age = 22;
protected:
    std::string _name = "有趣的中国人";
private:
    double _height = 180.3;
};

class Student : public Person
{
public:
    Student() = default;
    Student(std::string stdid, int classnum, int grade)
      :_stdid(stdid)
      ,_classnum(classnum)
      ,_grade(grade)
      ,Person(18,"王陈",178)
    {
        std::cout << "Student(std::string stdid, int classnum, int grade)" << std::endl;
    }
    void func()
    {
        // 父类的 privete 成员不管是在什么继承方式下 在派生类中 都不能访问
        // 但是在派生类中是有 父类的private成员的 只是不能访问
        //_height = 190;

        // protected 成员是可以的  但是在外部不能访问， 这是private和protected的区别
        _name = "Alan";

        // 但是可以间接访问
        // 子类和父类函数名相同会构成隐藏 在不同的类域
        Person::func();
    }
public:
    std::string _stdid = "2100400208";
protected:
    int _classnum = 215;
private:
    int _grade = 4;
};

void extend_test1()
{
    // 公有继承 只有基类的public成员能在外部访问
    Student st;
    st.func();
//    std::cout << "_age -> " << st._age << std::endl;
//    std::cout << "_age -> " << st._name << std::endl;
//    std::cout << "_age -> " << st._height << std::endl;
}

void extend_test2()
{
    Person p(22,"Alan",181);
    Student st;
    // 切割
    // 把子类对象的父类部分赋值给父类对象
    // 引用是引用的子类对象中父类的部分
    // 指针也是一样
    p = st;
    Person& rp = st;
    rp._age = 18;

    Person* pp = &st;
    pp->_age = 20;
}


void extend_test3()
{
    Person p;
    Student st;
    // 直接调用会栈溢出 要指定类作用限定符
    st.func();
}

void extend_test4()
{
    //Person p(18,"wc",178);
    Student st("2100160310",215,4);
}

int main()
{
    extend_test4();
    return 0;
}
