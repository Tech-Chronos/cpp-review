#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <vector>
#include <condition_variable>

using namespace std;

////////////////////////////////
////// 1. 加锁方式 mutex /////////
////////////////////////////////

//void Print(int n, int& x, mutex& mtx)
//{
//    mtx.lock();
//    for (int i = 0; i < n; ++i)
//    {
//        ++x;
//    }
//    mtx.unlock();
//}
//
//int main()
//{
//    mutex mtx;
//    int x = 0;
//
//    int n1 = 10000;
//    int n2 = 30000;
//    thread t1(Print, n1, ref(x), ref(mtx));
//    thread t2(Print, n2, ref(x), ref(mtx));
//
//    t1.join();
//    t2.join();
//
//    cout << x << endl;
//
//    return 0;
//}

/////////////////////////////////////////////////
////// 2. unique_lock & lock_guard更安全 /////////
/////////////////////////////////////////////////

//void Print(int n, int& x, mutex& mtx)
//{
//    //unique_lock<mutex> lck(mtx);
//    lock_guard lck(mtx);
//    for (int i = 0; i < n; ++i)
//    {
//        ++x;
//    }
//}
//
//int main()
//{
//    int x = 0;
//    mutex mtx;
//
//    thread t1(Print, 10000, ref(x), ref(mtx));
//    thread t2(Print, 40000, ref(x), ref(mtx));
//
//    t1.join();
//    t2.join();
//    cout << x << endl;
//    return 0;
//}

/////////////////////////////////////////////////
////// 3. Lambda + 构造 + 移动赋值    /////////
/////////////////////////////////////////////////

//int main()
//{
//    int x = 0;
//    mutex mtx;
//    int n1 = 10000;
//    int n2 = 30000;
//
//    thread t1([&]()mutable -> void
//              {
//                  unique_lock<mutex> lck(mtx);
//                  for (int i = 0; i < n1; ++i)
//                  {
//                      ++x;
//                  }
//              });
//
//    thread t2([&]()mutable -> void
//              {
//                  unique_lock<mutex> lck(mtx);
//                  for (int i = 0; i < n2; ++i)
//                  {
//                      ++x;
//                  }
//              });
//
//    t1.join();
//    t2.join();
//
//    cout << x << endl;
//    return 0;
//}

//int main()
//{
//    int x = 0;
//    mutex mtx;
//    int n1 = 10000;
//    int n2 = 30000;
//
//    vector<thread> vth;
//    vth.resize(10);
//
//    auto func1 = [&]()mutable -> void
//                  {
//                      unique_lock<mutex> lck(mtx);
//                      for (int i = 0; i < n1; ++i)
//                      {
//                          ++x;
//                      }
//                  };
//
//    auto func2 = [&]()mutable -> void
//                  {
//                      unique_lock<mutex> lck(mtx);
//                      for (int i = 0; i < n2; ++i)
//                      {
//                          ++x;
//                      }
//                  };
//
//    for (auto& th : vth)
//    {
//        th = thread(func1);
//    }
//
//    for (auto& th : vth)
//    {
//        th.join();
//    }
//
//    for (auto& th : vth)
//    {
//        th = thread(func2);
//    }
//
//    for (auto& th : vth)
//    {
//        th.join();
//    }
//
//    cout << x << endl;
//
//    return 0;
//}


/////////////////////////////////////////////////
////// 4. atomic 原子操作   /////////
/////////////////////////////////////////////////

//void Print(int n, int& x, atomic<int>& ato)
//{
//    for (int i = 0; i < n; ++i)
//    {
//        ++ato;
//    }
//}
//
//int main()
//{
//    mutex mtx;
//    int n1 = 10000;
//    int n2 = 40000;
//
//    int x = 0;
//
//    atomic ato(x);
//
//    auto func1 = [&]()mutable ->void {
//        for (int i = 0; i < n1; ++i)
//        {
//            ++ato;
//        }
//    };
//
//    thread t1 {func1};
//    thread t2 {func1};
//
//
//    t1.join();
//    t2.join();
//
//    cout << ato << endl;
//    printf("%d\n", ato.load());
//    return 0;
//}

/////////////////////////////////////////////////
////// 5.  wait 条件变量（race）   /////////
/////////////////////////////////////////////////

//bool flag = false;
//condition_variable cv;
//
//void func1(mutex& mtx, int id)
//{
//    unique_lock<mutex> lck(mtx);
//    while (!flag)
//        cv.wait(lck);
//
//    cout << "thread " << id  << " has arrived!" << endl;
//}
//
//void go(mutex& mtx)
//{
//    unique_lock<mutex> lck(mtx);
//    cv.notify_all();
//    flag = true;
//}
//
//int main()
//{
//    mutex mtx;
//
//    vector<pair<thread, int>> v;
//    v.resize(10);
//    for (int i = 0; i < 10; ++i)
//    {
//        v[i].second = i;
//    }
//
//    for (auto& th : v)
//    {
//        th.first = thread(func1, ref(mtx), th.second) ;
//    }
//
//    cout << "10 threads wait for racing!" << endl;
//
//    go(ref(mtx));
//
//    for (auto& th : v)
//    {
//        th.first.join();
//    }
//
//    return 0;
//}
//

/////////////////////////////////////////////////
////// 6.  双线程交替打印奇偶数   /////////
/////////////////////////////////////////////////

int main()
{
    mutex mtx;
    condition_variable cv;
    bool flag = false;
    int n = 101;

    thread t1([&]()mutable -> void
              {
                  int i = 0;
                  while (1)
                  {
                      unique_lock<mutex> lck(mtx);

                      while (flag)
                          cv.wait(lck);

                      if (i < n)
                      {
                          cout << i << endl;
                          i += 2;
                          cv.notify_one();
                          flag = true;
                      }

                      if (i >= n)
                          break;
                  }
              });

    //this_thread::sleep_for(std::chrono::microseconds(3000));

    thread t2([&]()mutable -> void
              {
                  int j = 1;
                  while (1)
                  {
                      unique_lock<mutex> lck(mtx);

                      while (!flag)
                          cv.wait(lck);

                      if (j < n)
                      {
                          cout << j << endl;
                          j += 2;
                          cv.notify_one();
                          flag = false;
                      }

                      if (j >= n)
                          break;
                  }
              });

    t1.join();
    t2.join();


    return 0;
}

