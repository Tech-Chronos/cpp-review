#include "my_shared_ptr.h"

int x = 0;
mutex _mtx;
//void func(my_shared_ptr<int> sptr, int n)
//{
//
//    for (size_t i = 0; i < n; ++i)
//    {
//        my_shared_ptr<int> sptr1(sptr);
//        my_shared_ptr<int> sptr2(sptr);
//        my_shared_ptr<int> sptr3(sptr);
//
//        _mtx.lock();
//        ++x;
//        _mtx.unlock();
//    }
//
//
//}
//
//int main()
//{
//    my_shared_ptr<int> sptr(new int(0));
//    thread t1(func, sptr, 10000000);
//
//    thread t2(&func, sptr, 20000000);
//
//    t1.join();
//    t2.join();
//
//    cout << x << endl;
//    return 0;
//}


// 循环引用引发的问题，析构不会调用，内存会泄漏
//struct Node
//{
//    ~Node()
//    {
//        cout << "destruct" << endl;
//    }
//public:
//    my_shared_ptr<Node> _prev;
//    my_shared_ptr<Node> _next;
//    int _val;
//
//};
//
//int main()
//{
//
//    my_shared_ptr<Node> p1(new Node);
//    my_shared_ptr<Node> p2(new Node);
//
//    p1->_next = p2;
//    p2->_prev = p1;
//    return 0;
//}

// 定制删除器
int main()
{
    my_shared_ptr<int> sptr1(new int[10],[](int* ptr){delete[] ptr;});
    my_shared_ptr<int> sptr3(new int[10]);
    my_shared_ptr<FILE> sptr2(fopen("a.txt", "w"), fclose);
    return 0;
}