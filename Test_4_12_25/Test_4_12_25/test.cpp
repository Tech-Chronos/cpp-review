#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

// 1. ����Ĵ�С
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

// 2. �ڴ����
//	1. ��һ��Ԫ�ش���ڵ�һ��λ��
//	2. �����Ԫ�ش���ڱ�����Ĭ�϶��������Լ��Ķ�������С���Ǹ�����������λ��
//				vs Ĭ�϶������� 8��Linux û��Ĭ�϶�����
//  3. ����Ĵ�С�������������������������������������Ķ�������
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