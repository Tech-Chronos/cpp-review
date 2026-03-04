#include <iostream>
#include <mutex>
class Singleton_lazy
{
public:
    static Singleton_lazy* GetInstance()
    {
        if (_instance == nullptr)
        {
            std::lock_guard<std::mutex> lock(_mtx);
            if (_instance == nullptr)
            {
                _instance = new Singleton_lazy();
            }
        }
        return _instance;
    }

    Singleton_lazy(const Singleton_lazy&) = delete;
    Singleton_lazy& operator=(const Singleton_lazy&) = delete;
private:
    Singleton_lazy() {};
    static Singleton_lazy* _instance;
    static std::mutex _mtx;
};

class Singleton_lazy_v2
{
public:
    static Singleton_lazy_v2& GetInstance()
    {
        static Singleton_lazy_v2 instance;
        return instance;
    }
    Singleton_lazy_v2(const Singleton_lazy_v2&) = delete;
    Singleton_lazy_v2& operator=(const Singleton_lazy_v2&) = delete;
private:
    Singleton_lazy_v2() {};
};

class Singleton_hungry
{
public:
    Singleton_hungry& GetInstance()
    {
        return instance;
    }

    Singleton_hungry(const Singleton_hungry&) = delete;
    Singleton_hungry& operator=(const Singleton_hungry&) = delete;
private:
    Singleton_hungry() {};
    static Singleton_hungry instance;
};

Singleton_hungry Singleton_hungry::instance;

int main()
{
    std::cout << "Singleton_lazy size: " << sizeof(Singleton_lazy) << std::endl;
    std::cout << "Singleton_lazy_v2 size: " << sizeof(Singleton_lazy_v2) << std::endl;
    std::cout << "Singleton_hungry size: " << sizeof(Singleton_hungry) << std::endl;

    return 0;
}
