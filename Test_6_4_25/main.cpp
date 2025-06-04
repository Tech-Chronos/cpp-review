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

int main()
{
    vector_test5();
    return 0;
}
