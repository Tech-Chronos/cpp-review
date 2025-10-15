#include <iostream>
#include <functional>

#include <string>
using namespace std;

int sub(int left, int right)
{
    return left - right;
}

void print(const string& str, double blood_val, double magic_val)
{
    cout << "name：" << str << "，blood: " << blood_val << "，magic: " << magic_val << endl;
}

class Test
{
public:
    void myprint(const string& str, double blood_val, double magic_val)
    {
        cout << "name：" << str << "，blood: " << blood_val << "，magic: " << magic_val << endl;
    }
};

struct Sub
{
    static int sub(int left, int right)
    {
        return left - right;
    }

    int add(int left, int right)
    {
        return left + right;
    }
};

void function_test()
{
    // 1. 函数指针
    function<int(int, int)> func1 = sub;
    cout << "函数指针：" << func1(10,2) << endl;

    // 2. 类中的函数
    // 2.1 静态成员函数
    function<int(int, int)> func2 = Sub::sub;
    cout << "类的静态成员函数：" << func2(10,2) << endl;

    // 2.2 普通成员函数
    // 普通成员函数有this指针，所以不可以只穿两个参数
    // 这个在function内部是直接用第一个参数调用类中的函数，因此传入指针和普通对象都可以
    // 因为this指针本身规定就是不可以外部显示传入
    // 如果要取出类中的普通成员函数，要加&符号
    // 这个是普通对象
    function<int(Sub, int, int)> func3 = &Sub::add;
    cout << "普通成员函数：" << func3(Sub(), 10,2) << endl;

    // 这个传入指针
    function<int(Sub*, int, int)> func4 = &Sub::add;
    Sub sub;
    cout << "普通成员函数：" << func4(&sub, 10,2) << endl;

    // 3. Lambda表达式
    function<int(int, int)> func5 = [](int left, int right) mutable -> int {return left - right;};
    cout << "Lambda 表达式：" << func5(10,2) << endl;
}

void bind_test()
{
    // 1. 改变参数的顺序
    // placeholders::_1 接收第一个参数，placeholders::_2 接收第二个参数
    auto func1 = bind(sub, placeholders::_1, placeholders::_2);
    cout << func1(10,2) << endl;

    auto func2 = bind(sub, placeholders::_2, placeholders::_1);
    func2(10,2);
    cout << func2(10,2) << endl;


    // 2. 改变参数的数量
    // 2.1 绑定普通函数
    //string str = "snake";
    auto func3 = bind(print, "大蛇丸", placeholders::_1, placeholders::_2);
    func3(100, 80);

    auto func4 = bind(print, placeholders::_1, 100, placeholders::_2);
    func4("千手柱间", 90);


    // 2.2 绑定类中的非静态成员函数：this指针的处理
    auto func5 = bind(&Test::myprint, placeholders::_1, placeholders::_2, placeholders::_3, placeholders::_4);
    func5(Test(), "宇智波带土", 90, 80);

    auto func6 = bind(&Test::myprint, placeholders::_1, placeholders::_2, placeholders::_3, placeholders::_4);
    Test test;
    func6(&test, "长十郎", 90, 80);
    func6(test, "水门", 90, 80);

    auto func7 = bind(&Test::myprint, placeholders::_1, "白面具" ,placeholders::_2, placeholders::_3);
    func7(Test(), 50, 50);

    function<void(Test, string, double, double)> func8 = bind(&Test::myprint, placeholders::_1, placeholders::_2 ,placeholders::_3, placeholders::_4);
    func8(Test(), "长门", 90, 60);

    function<void(Test*, double, double)> func9 = bind(&Test::myprint, placeholders::_1, "鸣人" ,placeholders::_2, placeholders::_3);
    Test t1;
    func9(&t1, 100, 80);
}

int main()
{
    //function_test();

    bind_test();

    return 0;
}
