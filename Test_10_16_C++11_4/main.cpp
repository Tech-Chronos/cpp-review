#include <iostream>
#include <thread>
#include <mutex>
#include <functional>

using namespace std;

//int x = 0;
//mutex mtx;

//void print(int n)
//{
//    mtx.lock();
//    for (int i = 0; i < n; ++i)
//    {
//        ++x;
//    }
//    mtx.unlock();
//}
//
//void thread_test()
//{
//    thread t1(print,100000);
//    cout << "t1.get_id(): " << t1.get_id() << endl;
//
//    thread t2(print,200000);
//    cout << "t2.get_id(): " << t2.get_id() << endl;
//
//    t1.join();
//    t2.join();
//
//    cout << "x: " << x << endl;
//
//}

//int main()
//{
//    //thread_test();
//    return 0;
//}

//void thread_test(int n, int rx, mutex* rmtx)
//{
//    rmtx->lock();
//    for (int i = 0; i < n; ++i)
//    {
//        ++rx;
//    }
//    rmtx->unlock();
//}

//void test_ref(int & i)
//{
//    cout << i << endl;
//}
//
//void t1()
//{
//    int i = 0;
//    test_ref(i);
//}

//int main()
//{
//    mutex mtx;
//    int x = 0;
//
//    thread t1(thread_test, 200000, x, &mtx);
//    //thread t2(thread_test, 200000, x,mtx);
//    //thread t2(thread_test, 300000, ref(x), ref(mtx));
//
//    t1.join();
//    //t2.join();
//
//    cout << x << endl;
//    return 0;
//}

void thread_test(int n, int& rx, mutex& rmtx)
{
    rmtx.lock();
    for (int i = 0; i < n; ++i)
    {
        ++rx;
    }
    rmtx.unlock();
}

int main()
{
    mutex mtx;

    int x = 0;

    thread t1(thread_test, 100000, ref(x), ref(mtx));
    thread t2(thread_test, 200000, ref(x), ref(mtx));


    t1.join();
    t2.join();

    cout << x << endl;

    return 0;
}
