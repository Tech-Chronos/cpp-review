#include "template_test.h"
#include <algorithm>
void test_priority_queue()
{
    std::priority_queue<dsj::Date, std::vector<dsj::Date>, dsj::CompareDateGreater> pq;
    dsj::Date d1(2001,1,1);
    pq.push(d1);
    pq.push(dsj::Date(2018,2,18));
    pq.push({2025,4,20});

    while (!pq.empty())
    {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }
}

void test_my_priority_queue1()
{
    dsj::priority_queue<dsj::Date, std::vector<dsj::Date>, dsj::CompareDateGreater> pq;
    dsj::Date d1(2001,1,1);
    pq.push(d1);
    pq.push(dsj::Date(2018,2,18));
    pq.push({2025,4,20});

    std::cout << "this is my priority_queue " << std::endl;
    while (!pq.empty())
    {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }
}

void test_my_priority_queue2()
{
    dsj::priority_queue<dsj::Date*, std::vector<dsj::Date*>, dsj::CompareDateLessPtr> pq;
    auto d3 = new dsj::Date(2025,4,20);
    auto d1 = new dsj::Date(2001,1,1);
    auto d2 = new dsj::Date(2027,2,18);


    pq.push(d1);
    pq.push(d2);
    pq.push(d3);
    std::cout << "this is my priority_queue " << std::endl;
    while (!pq.empty())
    {
        std::cout << *pq.top() << std::endl;
        pq.pop();
    }
}


int main()
{
    std::vector<int>  v = {1,5,2,3,4,5,8,9};
    std::sort(v.begin(), v.end(), std::greater());
    auto it = v.begin();
    while (it != v.end())
    {
        std::cout << *it  << std::endl;
        ++it;
    }
//    test_priority_queue();
//    test_my_priority_queue1();
//    test_my_priority_queue2();
    return 0;
}
