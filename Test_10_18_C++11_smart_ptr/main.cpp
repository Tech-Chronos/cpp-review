#include "my_shared_ptr.h"

class A
{
public:
    A(int a1 = 1, int a2 = 1)
    :_a1(a1)
    ,_a2(a2)
    {
        std::cout << "construct A" << std::endl;
    }

    ~A()
    {
        std::cout << "delete A" << std::endl;
    }
private:
    int _a1;
    int _a2;
};

//int main()
//{
//    A* ptra = new A;
//    dsj::shared_ptr<A> sptr1(ptra);
//    dsj::shared_ptr<A> sptr2 = sptr1;
//
//
//    dsj::shared_ptr<A> sptr3(new A(2,2));
//
//    sptr3 = sptr2;
//
//    return 0;
//}

std::mutex mtx;

void func(dsj::shared_ptr<std::list<int>> sptr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        dsj::shared_ptr<std::list<int>> sptr1(sptr);
        dsj::shared_ptr<std::list<int>> sptr2(sptr);
        dsj::shared_ptr<std::list<int>> sptr3(sptr);

        mtx.lock();
        sptr->push_back(i);
        mtx.unlock();
    }
    std::cout << sptr.size() << std::endl;
}

int main()
{
    dsj::shared_ptr<std::list<int>> sptr(new std::list<int>);
    std::thread t1(func, sptr, 10000);
    std::thread t2(func, sptr, 20000);

    t1.join();
    t2.join();
    std::cout << "链表size：" << sptr->size() << std::endl;
    std::cout << sptr.size() << std::endl;

    return 0;
}
