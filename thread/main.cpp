#include <iostream>
#include <thread>
#include <atomic>
#include <condition_variable>

//std::atomic<int> sum = 0;
int sum = 0;
std::mutex mtx;
using namespace std;

int main()
{
    int num = 103;
    bool flag = false;
    condition_variable cv;
    int odd = 1;
    int eve = 0;
    thread t1([&]()
              {
                    while (1)
                    {
                        unique_lock<mutex> lck(mtx);
                        cv.wait(lck, [&]->bool { return flag; });
                        cout << odd << endl;
                        odd += 2;
                        if (odd > num)
                        {
                            flag = false;
                            cv.notify_one();
                            break;
                        }
                        flag = false;
                        cv.notify_one();
                    }
              });

    thread t2([&]()
              {
                  while (1)
                  {
                      unique_lock<mutex> lck(mtx);
                      cv.wait(lck, [&]->bool { return !flag; });
                      cout << eve << endl;
                      eve += 2;
                      if (eve > num)
                      {
                          flag = true;
                          cv.notify_one();
                          break;
                      }

                      flag = true;
                      cv.notify_one();
                  }
              });

    t1.join();
    t2.join();
    return 0;
}
//int main()
//{
//    thread t1([&]()
//    {
//        for (int i = 0; i < 100; ++i)
//        {
//            lock_guard<mutex> lock(mtx);
//            sum++;
//            cout << "thread1: " << sum << std::endl;
//        }
//    });
//
//    thread t2([&]()
//    {
//        for (int i = 0; i < 100; ++i)
//        {
//            lock_guard<mutex> lock(mtx);
//            sum--;
//            cout << "thread2: " << sum << std::endl;
//        }
//    });
//
//    t1.join();
//    t2.join();
//    std::cout << sum;
//
//    return 0;
//}
//void func(int num)
//{
//    for (int i = 0;i < num; ++i)
//    {
//        sum++;
//    }
//}
//
//int main()
//{
//    std::cout << "begin sum: " << sum << std::endl;
//    std::thread thread1(func, 100000);
//    std::thread thread2(func, 200000);
//
//    thread1.join();
//    thread2.join();
//    std::cout << "end sun: " << sum << std::endl;
//    return 0;
//}


//int main()
//{
//    thread t1([]()
//    {
//        for (int i = 0; i < 100000; ++i)
//        {
//            unique_lock<mutex> lock(mtx);
//            ++sum;
//        }
//    } );
//
//    thread t2([]()
//    {
//        for (int i = 0; i < 3000; ++i)
//        {
//            unique_lock<mutex> lock(mtx);
//            ++sum;
//        }
//    });
//
//    t1.join();
//    t2.join();
//
//    std::cout << sum << std::endl;
//    return 0;
//}
