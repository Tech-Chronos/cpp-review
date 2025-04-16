#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//class A
//{
//public:
//	A()
//	{
//		_a = 0;
//	}
//	void print() const// 这里接收的指针类型是 A* 类型的
//	{
//		cout << "void print() -> _a = " << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	const A a;
//	cout << typeid(&a).name() << endl;
//	a.print(); // 传的指针是 const A* 类型的
//
//	const int b = 0;
//	cout << typeid(&b).name() << endl;
//	return 0;
//}


class A
{
public:
	A* operator&()
	{
		return this;
	}
	const A* operator&() const
	{
		return this;
	}
private:
	const int i = 0;
};

int main()
{
	A aa1;
	const A* aa2;
	aa2 = aa2 + 1;
}