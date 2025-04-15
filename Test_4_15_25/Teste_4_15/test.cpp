#define  _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"
//class A
//{
//	char ch;
//	int i;
//	int j;
//	double d;
//};
//int main()
//{
//	A a;
//	cout << "sizeof(a) -> " << sizeof(a) << endl;
//	return 0;
//}

//int main()
//{
//	double d = 1.1;
//	const int &i = d;
//	
//	return 0;
//}

//class A
//{
//public:
//	void print()
//	{
//		cout << this << endl;
//	}
//private:
//	int a;
//};
//
//int main()
//{
//	A a;
//	a.print();
//	return 0;
//}


//class MyClass 
//{
//public:
//    void showThisBehavior() 
//    {
//        MyClass* ptr = this;  // 将 this 的值复制到 ptr 变量
//        std::cout << "对象地址（this的值）: " << this << std::endl;
//        std::cout << "ptr变量的地址（非this的地址）: " << &ptr << std::endl;
//    }
//};
//int main() 
//{
//    MyClass obj;
//    obj.showThisBehavior();
//    return 0;
//}

//class MyClass
//{
//public:
//	MyClass()
//	{
//
//	}
//	MyClass(const MyClass& obj)
//	{
//		cout << "MyClass(const MyClass& obj)" << endl;
//	}
//};
//
//int main()
//{
//	MyClass obj1;
//	MyClass obj2(obj1);
//	return 0;
//}

//class A
//{
//public:
//	A(int i = 1)
//	{
//		_i = i;
//	}
//	~A()
//	{
//		cout << "~A() -> " << _i << endl;
//	}
//private:
//	int _i;
//};
//
//static A a7(7);
//static A a8(8);
//A a9(9);
//A a10(10);
//
//void func()
//{
//	static A a4(4);
//	A a5(5);
//	static A a6(6);
//}
//
//int main()
//{
//	A a1(1);
//	A a2(2);
//	func();
//	static A a3(3);
//	return 0;
//}


//class A
//{
//public:
//	void func()
//	{
//		cout << "func()" << endl;
//	}
//private:
//	int _a;
//};
//
//typedef void (A::*pfunc)();
//
//int main()
//{
//	pfunc p = &A::func;
//	A tmp;
//	(tmp.*p)();
//	return 0;
//}

int main()
{
	/*int input = 0;
	do {
		cout << "                                **********  欢迎进入日期计算器  ****************" << endl;
		cout << "                                **********  1.计算两日期差几天  ****************" << endl;
		cout << "                                **********  2.计算某日往后n天   ****************" << endl;
		cout << "                                **********  3.计算某日往前n天   ****************" << endl;
		cout << "                                **********  0.  退出系统       ****************" << endl;
		printf("\n\n\n");
		cout << "请选择：";
		cin >> input;
		if (input == 1)
		{
			Date d1;
			Date d2;
			cout << "请输入第一个日期：";
			cin >> d1;
			cout << "请输入第二个日期：";
			cin >> d2;
			cout << d1 << "和" << d2 << "相差" << (d2 - d1) << "天" << endl;
			printf("\n\n\n");
		}
		else if (input == 2)
		{
			Date d1;
			int day = 0;
			cout << "请输入某日日期：";
			cin >> d1;
			cout << "请输入往后多少天：";
			cin >> day;
			cout << d1 << "往后" << day << "天是" << (d1 + day) << endl;
			printf("\n\n\n");
		}
		else if (input == 3)
		{
			Date d1;
			int day = 0;
			cout << "请输入某日日期：";
			cin >> d1;
			cout << "请输入往前多少天：";
			cin >> day;
			cout << d1 << "往前" << day << "天是" << (d1 - day) << endl;
			printf("\n\n\n");
		}
		else if (input == 0)
		{
			break;
		}
		else
		{
			cout << "请输入正确的选项" << endl;
			printf("\n\n\n");
		}

	} while (input);*/

	Date d1(2003, 6, 22);
	Date d2(2004, 6, 22);
	cout << (d1 - d2) << endl;
	return 0;
}