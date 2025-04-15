#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

// 1. 空类的大小
//class A
//{
//public:
//	void Print()
//	{
//		cout << "void Print() " << endl;
//	}
//};
//
//int main()
//{
//	A a;
//	cout << "sizeof(A)->" << sizeof(A) << endl;
//	cout << "sizeof(a)->" << sizeof(a) << endl;
//	return 0;
//}

// 2. 内存对齐
//	1. 第一个元素存放在第一个位置
//	2. 后面的元素存放在编译器默认对其数和自己的对其数较小的那个的整数倍的位置
//				vs 默认对其数是 8，Linux 没有默认对其数
//  3. 整体的大小是自身最大对其数的整数倍（不算编译器自身的对其数）
#pragma pack(7)
struct B
{
public:
	char ch;
	int i;
	int j;
	double d;
};

int main()
{
	cout << "sizeof(B) -> " << sizeof(B) << endl;
	return 0;
}