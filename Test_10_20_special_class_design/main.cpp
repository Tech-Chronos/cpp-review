#include <iostream>
#include <memory>
#include <functional>

class CanNotCopy
{
public:
    CanNotCopy() = default;
    CanNotCopy(const CanNotCopy& copy) = delete;
private:
    int _a1;
    int _a2;
};

class HeapOnly1
{
public:
    static HeapOnly1* CreateHeapOnly()
    {
        HeapOnly1* hp_ptr = new HeapOnly1;
        return hp_ptr;
    }

    HeapOnly1(const HeapOnly1& hp) = delete;

private:
    HeapOnly1(int a1 = 1, int a2 = 2)
      :_a1(a1)
      ,_a2(a2)
    {}

private:
    int _a1;
    int _a2;
};

class StackOnly
{
public:
    static StackOnly CreateStackOnly()
    {
        return StackOnly();
    }
private:
    explicit StackOnly(int a1 = 1, int a2 = 1)
        :_a1(a1)
        ,_a2(a2)
    {}
private:
    int _a1;
    int _a2;
};


// 单例模式
// 1. 饿汉模式实现单例
// 天然保证线程的安全
class SingleInstance
{
public:
    static SingleInstance* CreateOnlyInstance()
    {
        return& single;
    }
private:
    SingleInstance(int a1)
        :_a1(a1)
    {}

    SingleInstance(const SingleInstance&) = delete;
    SingleInstance operator=(const SingleInstance&) = delete;

private:
    int _a1;
    static SingleInstance single;// 声明
};

// 虽然在静态成员变量在类外定义，但是还是属于这个类的作用域，因此可以访问私有的构造函数
SingleInstance SingleInstance::single(2);


// 2. 懒汉模式实现单例
// 方法一：返回局部的静态
//class singleton
//{
//public:
//    static singleton* CreateOnlyInstance()
//    {
//        static singleton* instance = new singleton(55);
//
//        return instance;
//    }
//private:
//    singleton(int a1 = 22)
//        :_a1(a1)
//    {}
//    singleton(const singleton&) = delete;
//    singleton& operator=(const singleton&) = delete;
//
//private:
//    int _a1;
//};

//方法2:
class singleton
{
public:
    static singleton* CreateOnlyInstance()
    {
        // 无法保证线程安全
        if (_sta_data == nullptr) // 保证效率
        {
            //_mtx->lock();
            std::unique_lock<std::mutex> lck(*_mtx);
            if (_sta_data == nullptr) // 保证线程安全
            {
                _sta_data = new singleton(44);
            }
            //_mtx->unlock();
        }

        return _sta_data;
    }

private:
    singleton(int a1)
        :_a1(a1)
    {}

    singleton(const singleton&) = delete;
    singleton& operator=(const singleton&) = delete;

private:
    int _a1;
    static std::mutex* _mtx;
    static singleton* _sta_data; // 声明
};

//定义
std::mutex* singleton::_mtx = new std::mutex;
singleton* singleton::_sta_data = nullptr;


int main()
{
    //CanNotCopy cnp;
    //CanNotCopy cnp1 = cnp;

    //HeapOnly* hp_ptr1 = HeapOnly::CreateHeapOnly();
    /// 不能禁掉拷贝构造
    //HeapOnly hp_ptr2 = *hp_ptr1;

    //StackOnly st = StackOnly::CreateStackOnly();
//    std::cout << SingleInstance::CreateOnlyInstance() << std::endl;
//    std::cout << SingleInstance::CreateOnlyInstance() << std::endl;
//    std::cout << SingleInstance::CreateOnlyInstance() << std::endl;

//    singleton* sin = singleton::CreateOnlyInstance();
//    std::cout << singleton::CreateOnlyInstance() << std::endl;
//    std::cout << singleton::CreateOnlyInstance() << std::endl;
//    std::cout << singleton::CreateOnlyInstance() << std::endl;

    std::cout << singleton::CreateOnlyInstance() << std::endl;
    std::cout << singleton::CreateOnlyInstance() << std::endl;
    std::cout << singleton::CreateOnlyInstance() << std::endl;
    return 0;
}
