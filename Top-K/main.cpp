#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <unistd.h>

void TopK(const std::vector<int>& orignal, std::vector<int>* ret, int k)
{
    std::priority_queue<int, std::vector<int>, std::less<int>> top_queue;
    for (auto e : orignal)
    {
        if (top_queue.size() < k)
        {
            top_queue.push(e);
        }
        else if (e < top_queue.top())
        {
            top_queue.pop();
            top_queue.push(e);
        }
    }
    while (top_queue.size() != 0)
    {
        ret->emplace_back(top_queue.top());
        top_queue.pop();
    }
}

void TopKFromFile(const std::string& filename, std::vector<int>* ret, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    std::ifstream fin(filename);
    if (!fin.is_open())
    {
        std::cout << "file open error!";
        exit(-1);
    }
    long long x;
    while (fin >> x)
    {
        if (min_heap.size() < k)
        {
            min_heap.push(x);
        }
        else if (x > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(x);
        }
    }
    while (!min_heap.empty())
    {
        ret->emplace_back(min_heap.top());
        min_heap.pop();
    }
}

void TestTopK()
{
    std::vector<int> original {7, 2, 9, 4, 1, 5, 8, 3, 6};
    int k = 3;
    std::vector<int> ret;
    TopK(original, &ret, k);

    for (auto e : ret)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void TestTopKFromFile()
{
    std::string filename = "../data.txt";
    std::vector<int> ret;
    int k = 3;
    TopKFromFile(filename, &ret, k);
    for (auto e : ret)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main()
{
    TestTopKFromFile();
//    char buf[1024];
//    getcwd(buf, sizeof(buf));
//    std::cout << buf << std::endl;
    return 0;
}
