#include "vector.h"
void vector_test1()
{
    dsj::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    dsj::print_vector(v);
}

void vector_test2()
{
    dsj::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.insert(v.begin(), 10);
    v.insert(v.begin(), 10);
    v.insert(v.begin(), 10);
    dsj::print_vector(v);
    v.erase(v.begin());
    dsj::print_vector(v);
    v.erase(v.begin());
    dsj::print_vector(v);
    v.erase(v.begin());
    dsj::print_vector(v);
}

void vector_test3()
{
    dsj::vector<double> v;
    v.push_back(1.1);
    v.push_back(2.1);
    v.push_back(3.1);
    std::cout << "size -> " << v.size() << std::endl;
    dsj::print_vector(v);
    v.insert(v.begin(), 4.1);
    v.insert(v.begin(), 5.1);
    v.insert(v.begin(), 6.1);
    v.insert(v.begin(), 7.1);
    v.insert(v.begin(), 8.1);
    v.insert(v.begin(), 9.1);
    std::cout << "size -> " << v.size() << std::endl;
    dsj::print_vector(v);
//    v.erase(v.begin());
//    dsj::print_vector(v);
}

void vector_test4()
{
    dsj::vector<double> v;
    v.push_back(1.1);
    v.push_back(2.1);
    v.push_back(3.1);
    v.push_back(4.1);
    dsj::vector<double> v2(v);
    dsj::print_vector(v2);
}

void vector_test5()
{
    dsj::vector<double> v;
    v.push_back(1.1);
    v.push_back(2.1);
    v.push_back(3.1);
    v.push_back(4.1);
    dsj::vector<double> v2;
    v2 = v;
    dsj::print_vector(v2);
    dsj::print_vector(v);
}

void vector_test6()
{
    std::string str1 = "hello world!";
    // 迭代器区间构造
    std::string::iterator it1 = str1.begin();
    std::string::iterator it2 = str1.end();
    dsj::vector<char> v(it1, it2);
    dsj::print_vector(v);
}

void vector_test7()
{
    // 这里会调用迭代器区间构造，因为括号里两个都是int，所以更方便，不用转换类型，会报错
    //dsj::vector<int> v(10,5);
    dsj::vector<int> v1(10u,5);
    std::cout << "v1 -> " << " ";
    dsj::print_vector(v1);

    // c++ 11 之后多参数类型的构造函数也支持隐式类型转换，只不过要用{}，
    // 构造 + 拷贝构造 -> 优化为直接构造
    dsj::vector<int> v2 = {10u, 2};
    std::cout << "v2 -> " << " ";
    dsj::print_vector(v2);

    // 除此之外，支持initializer_list构造方式
    // initializer_list 支持迭代器
//    dsj::vector<int> v3 = {1,2,3,4,5,6,7,8,9,0};
//    std::cout << "v3 -> " << " ";
//    dsj::print_vector(v3);
}

void vector_test8()
{
    dsj::vector<int> v = {1,2,3,4,5,6,7,8,9,0};
    dsj::vector<int>::iterator it1 = v.begin();
    dsj::vector<int>::iterator it2 = v.end();
    v.insert(it1, 10);
    dsj::print_vector(v);
}

void vector_test9()
{
    dsj::vector<int> v = {1,2,3,4,5};
    dsj::vector<int>::iterator it1 = v.begin();
    dsj::vector<int>::iterator it2 = v.end();
    while (it1 != it2)
    {
        if (*it1 % 2 == 0)
        {
            it1 = v.erase(it1);
        }
        else
        {
            ++it1;
        }
    }
    dsj::print_vector(v);
}

int main()
{
    vector_test9();
//    std::vector<int> v1 = {1,2,3,4,5,6,7};
//    const std::vector<int>& v2 = {1,2,3,4,5,6,7};
    return 0;
}
