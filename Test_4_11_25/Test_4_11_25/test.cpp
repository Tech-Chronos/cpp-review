#define  _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

#define FUNC_PTR_TYPE(RETURN_TYPE, FUNC_PTR_NAME, ...) \
  typedef RETURN_TYPE (*FUNC_PTR_NAME)(__VA_ARGS__)

#define TOSTRING(a) printf(#a " = %d\n", a)

FUNC_PTR_TYPE(int, INTFUNCPTR, int, int);
FUNC_PTR_TYPE(void, VOIDFUNCPTR);
int add(int a, int b)
{
	return a + b;
}

void print()
{
	cout << "void print" << endl;
}

int main()
{
	INTFUNCPTR func1 = add;
	VOIDFUNCPTR func2 = print;
	int a = 29;
	int b = 29;
	TOSTRING(a + b);
	/*int ret = func1(29, 29);
	cout << ret << endl;*/
	func2();
	return 0;
}


//typedef void(*ffptr)(int, string);

//#define DEF_FUNC(RETURN_TYPE, FUNC_PTR_NAME, ...) \
// typedef RETURN_TYPE (*FUNC_PTR_NAME)(__VA_ARGS__)
//
//void func(int a, string str)
//{
//	cout << "void func(int a, string str)" << endl;
//}
//
//int main()
//{
//	int arr[] = { 0, 1, 2 };
//	int(*ptr)[3] = &arr;
//	cout << "typeid(ptr).name() -> " << typeid(ptr).name() << endl;
//	cout << "typeid(arr).name() -> " << typeid(arr).name() << endl;
//	cout << "typeid(&arr).name() -> " << typeid(&arr).name() << endl;
//
//	void (*fptr)(int, string) = func;
//	ffptr ptr = func;
//	cout << "typeid(fptr).name() -> " << typeid(fptr).name() << endl;
//	return 0;
//}

//int main()
//{
//	Stack st;
//	InitStack(st);
//	PushStack(st, 1);
//	PushStack(st, 2);
//	PushStack(st, 3);
//	PushStack(st, 4);
//	PushStack(st, 5);
//	cout << TopStack(st) << endl;
//	PopStack(st);
//	cout << TopStack(st) << endl;
//	PopStack(st);
//	cout << TopStack(st) << endl;
//	PopStack(st);
//	cout << TopStack(st) << endl;
//	PopStack(st);
//	cout << TopStack(st) << endl;
//	DestroyStack(st);
//	return 0;
//}





//#define SWAP(a, b) \
//	do { \
//		int temp = (a);  \
//		(a) = (b);  \
//		(b) = (temp); \
//	} while(0);
//int main()
//{
//	cout << typeid(decltype(1 & 0xFF)).name() << endl;
//	return 0;
//}