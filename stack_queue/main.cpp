#include <iostream>
#include "stack.h"
#include "queue.h"
#include "algorithm"


void test1()
{
    dsj::priority_queue<int, std::vector<int>, dsj::less<int>> pq;
    std::vector v = {10,9,8,7,6,5,4,3,2,1};
    for (auto e : v)
    {
        if (pq.size() < 3)
            pq.push(e);
        else
        {
            if (e < pq.top())
            {
                pq.pop();
                pq.push(e);
            }
        }
    }
    while (pq.size())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}


class func
{
public:
    bool operator()(const int a, const int b)
    {
        return a % 10 < b % 10;
    }
};
int main()
{
    std::vector v = { 12, 26, 32, 33, 45, 53, 71, 80 };
    std::sort(v.begin(), v.end(), func());
    for (auto e : v)
    {
        std::cout << e << std::endl;
    }
    return 0;
}
