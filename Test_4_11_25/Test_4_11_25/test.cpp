#define  _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

class Person  
{
public:
	void func();

};
int main()
{
	cout << "sizeof(Person) = " << sizeof(Person) << endl;
	return 0;
}

//#define FUNC_PTR_TYPE(RETURN_TYPE, FUNC_PTR_NAME, ...) \
//typedef RETURN_TYPE (*FUNC_PTR_NAME)(__VA_ARGS__);
//
//#define ARRAY_PTR_TYPE(ARRAY_TYPE, ARRAY_PTR_NAME, ARRAY_NUM) \
//typedef ARRAY_TYPE (*ARRAY_PTR_NAME)[ARRAY_NUM];
//
//
//int multiply(int a, int b)
//{
//    return a * b;
//}
//
//typedef int(*aptr)[4];
//int main()
//{
//	auto fpt = multiply;
//	cout << "typeid(fpt).name()" << typeid(fpt).name() << endl;
//	int arr1[4] = {1,2,3,4};
//	aptr ptr1 = &arr1;
//	auto auptr = &arr1;
//	cout << "typeid(auptr).name()" << typeid(auptr).name() << endl;
//	cout <<"ptr1 = " << ptr1 << endl;
//	cout << "*ptr1 = " << *(*ptr1) << endl;
//	cout << "ptr1 + 1 = " << ptr1 + 1 << endl;
//	cout << "typeid(ptr1).name() : " << typeid(ptr1).name() << endl;
//	cout << "typeid(*ptr1).name() : " << typeid(*ptr1).name() << endl;
//	cout << "typeid(*(*ptr1)).name() : " << typeid(*(*ptr1)).name() << endl;
//
//	int arr2[5] = { 2,3,6,9,10 };
//	ARRAY_PTR_TYPE(int, aptr2, 5);
//	aptr2 ptr2 = &arr2;
//	cout << typeid(ptr2).name() << endl;
//	return 0;
//}

//int multiply(int a, int b)
//{
//    return a * b;
//}
//
//void print()
//{
//    cout << "void print()" << endl;
//}
//
//FUNC_PTR_TYPE(int, INT_FUNC_PTR, int, int);
//FUNC_PTR_TYPE(void, VOID_FUNC_PTR);
//
//int main()
//{
//    INT_FUNC_PTR func1 = multiply;
//    VOID_FUNC_PTR func2 = print;
//    func1(2, 4);
//    func2();
//    cout << typeid(func1).name() << endl;
//    return 0;
//}

//#define FUNC_PTR_TYPE(RETURN_TYPE, FUNC_PTR_NAME, ...) \
//  typedef RETURN_TYPE (*FUNC_PTR_NAME)(__VA_ARGS__)
//
//#define TOSTRING(a) printf(#a " = %d\n", a)
//
//FUNC_PTR_TYPE(int, INTFUNCPTR, int, int);
//FUNC_PTR_TYPE(void, VOIDFUNCPTR);
//
//typedef int(*ffptr)(int, int);
//
//int add(int a, int b)
//{
//    return a + b;
//}
//
//int main()
//{
//    //正常写的函数指针
//    int (*fptr)(int, int) = add;
//    // typedef 的格式
//    ffptr func1 = add;
//}

//int add(int a, int b)
//{
//	return a + b;
//}
//
//void print()
//{
//	cout << "void print" << endl;
//}
//
//int main()
//{
//	INTFUNCPTR func1 = add;
//	VOIDFUNCPTR func2 = print;
//	int a = 29;
//	int b = 29;
//	TOSTRING(a + b);
//	/*int ret = func1(29, 29);
//	cout << ret << endl;*/
//	func2();
//	return 0;
//}


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