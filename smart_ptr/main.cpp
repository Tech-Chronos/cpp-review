#include "shared_ptr.h"

using namespace std;
//int main()
//{
//    std::shared_ptr<int> ptr1 = std::make_shared<int>(2);
//    std::weak_ptr<int> ptr2(ptr1);
//
//    return 0;
//}

void f() {
    throw std::runtime_error("error");
}

void g() {
    try
    {
        f();  // 这里没有 try
    }
    catch (const std::exception& e) {
        std::cout << e.what();
    }
}

int main()
{

    g();

}


