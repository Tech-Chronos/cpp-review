//
// Created by dsj on 2026/2/15.
//

#include "mystring.h"
#include <unistd.h>
#include <string>

void TestIterator()
{
    mystring str("abcdefghijklmnopqrstuvwxyz");
    mystring::iterator it = str.begin();
    while (it != str.end())
    {
        *it += 1;
        std::cout << *it << " ";
        it++;
    }

    std::cout << std::endl;

    for (auto& e : str)
    {
        e -= 1;
        std::cout << e << " ";
    }
}

void TestConstIterator()
{
    const mystring str("abcdefghijklmnopqrstuvwxyz");
    mystring::const_iterator it = str.begin();

    while (it != str.end())
    {
        std::cout << *it << " ";
        it++;
    }
}

void TestCapacity()
{
    mystring str("hello world!");
    std::cout << "开始时的capacity: " << str.capacity() << std::endl;

    for (int i = 0; i < 1000; ++i)
    {
        int oldcapacity = str.capacity();
        str.push_back(' ');
        int newcapacity = str.capacity();
        if (newcapacity > oldcapacity)
        {
            std::cout << "扩容后的capacity: " << newcapacity << std::endl;
        }
    }
}

void TestReserveBasic()
{
    mystring s("hello");

    std::cout << "初始:\n";
    std::cout << "size: " << s.size() << std::endl;
    std::cout << "capacity: " << s.capacity() << std::endl;

    s.reserve(20);

    std::cout << "\nreserve(20) 后:\n";
    std::cout << "size: " << s.size() << std::endl;
    std::cout << "capacity: " << s.capacity() << std::endl;
    std::cout << "content: " << s.c_str() << std::endl;
}

void TestReserveNoShrink()
{
    mystring s("hello");
    s.reserve(20);

    size_t oldcap = s.capacity();

    s.reserve(5);

    std::cout << "\nreserve(5) 测试:\n";
    std::cout << "capacity 应该不变: " << s.capacity() << std::endl;
    std::cout << "是否等于原容量: " << (oldcap == s.capacity()) << std::endl;
}

void TestReserveIntegrity()
{
    mystring s("abcdef");

    s.reserve(50);

    std::cout << "\n数据完整性测试:\n";
    std::cout << s.c_str() << std::endl;

    for (size_t i = 0; i < s.size(); ++i)
    {
        std::cout << s.c_str()[i] << " ";
    }
    std::cout << std::endl;
}

void TestReserveWithPushBack()
{
    mystring s;
    s.reserve(100);

    for (int i = 0; i < 50; ++i)
    {
        s.push_back('a');
    }

    std::cout << "\npush_back 后:\n";
    std::cout << "size: " << s.size() << std::endl;
    std::cout << "capacity: " << s.capacity() << std::endl;
}

void TestReserveAddress()
{
    mystring s("hello");

    const char* oldptr = s.c_str();

    s.reserve(100);

    const char* newptr = s.c_str();

    std::cout << "\n地址是否变化: " << (oldptr != newptr) << std::endl;
}

int main()
{
    // TestIterator();
    // std::cout << "\n";
    //
    // TestConstIterator();
    // std::cout << "\n";
    //
    // TestCapacity();
    // std::cout << "\n";

    // TestReserveBasic();
    //
    // TestReserveNoShrink();

    // TestReserveIntegrity();

    // TestReserveWithPushBack();
    // TestReserveAddress();

    mystring str;

    Getline(std::cin, str);
    std::cout << str << std::endl;
    return 0;
}
