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
//        MyClass* ptr = this;  // �� this ��ֵ���Ƶ� ptr ����
//        std::cout << "�����ַ��this��ֵ��: " << this << std::endl;
//        std::cout << "ptr�����ĵ�ַ����this�ĵ�ַ��: " << &ptr << std::endl;
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
		cout << "                                **********  ��ӭ�������ڼ�����  ****************" << endl;
		cout << "                                **********  1.���������ڲ��  ****************" << endl;
		cout << "                                **********  2.����ĳ������n��   ****************" << endl;
		cout << "                                **********  3.����ĳ����ǰn��   ****************" << endl;
		cout << "                                **********  0.  �˳�ϵͳ       ****************" << endl;
		printf("\n\n\n");
		cout << "��ѡ��";
		cin >> input;
		if (input == 1)
		{
			Date d1;
			Date d2;
			cout << "�������һ�����ڣ�";
			cin >> d1;
			cout << "������ڶ������ڣ�";
			cin >> d2;
			cout << d1 << "��" << d2 << "���" << (d2 - d1) << "��" << endl;
			printf("\n\n\n");
		}
		else if (input == 2)
		{
			Date d1;
			int day = 0;
			cout << "������ĳ�����ڣ�";
			cin >> d1;
			cout << "��������������죺";
			cin >> day;
			cout << d1 << "����" << day << "����" << (d1 + day) << endl;
			printf("\n\n\n");
		}
		else if (input == 3)
		{
			Date d1;
			int day = 0;
			cout << "������ĳ�����ڣ�";
			cin >> d1;
			cout << "��������ǰ�����죺";
			cin >> day;
			cout << d1 << "��ǰ" << day << "����" << (d1 - day) << endl;
			printf("\n\n\n");
		}
		else if (input == 0)
		{
			break;
		}
		else
		{
			cout << "��������ȷ��ѡ��" << endl;
			printf("\n\n\n");
		}

	} while (input);*/

	Date d1(2003, 6, 22);
	Date d2(2004, 6, 22);
	cout << (d1 - d2) << endl;
	return 0;
}