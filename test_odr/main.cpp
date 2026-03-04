#include "util.h"

extern int x;

#define ADD(a, b)  ((a) + (b))

#define SQUARE(x) x*x

int main()
{
    std::cout << SQUARE(1+2);
}


//void test()
//{
//    int a = 1;
//
//    char* ch = (char*)&a;
//    if (*ch == 1)
//        std::cout << "little" << "\n";
//    else
//        std::cout << "big" << "\n";
//}
//
//union Test
//{
//    int a;
//    char ch;
//};
//
//int main()
//{
//    Test t;
//    t.a = 1;
//    if (t.ch == 1)
//        std::cout << "little" << "\n";
//    else
//        std::cout << "big" << "\n";
//    return 0;
//}
//class Base {};
//class Derive : public Base {};
//
//Derive d;
//Base pb = static_cast<Base>(d);
//
//int sub(int* a, int* b)
//{
//    return  *a - *b;
//}
//
//void test()
//{
////    const int a = 10;
////    sub(const_cast<int*>(&a), const_cast<int*>(&a));
////    int* a = new int(2);
////    double* b = new double(2.9);
////    b = static_cast<double*>(a);
//}
//
//int main()
//{
//    const int a = 10;
//    std::cout << &a << std::endl;
//
//    int *p = const_cast<int*>(&a);
//
//    *p = 20;
//    std::cout << p << std::endl;
////    int y = ADD(1 << 2,3 << 2);
////    std::cout << (1 << 5 << 2) << std::endl;
////    std::cout << y << std::endl;
//    return 0;
//}
