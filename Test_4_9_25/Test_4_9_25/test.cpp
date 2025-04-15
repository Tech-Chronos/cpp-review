#define  _CRT_SECURE_NO_WARNINGS 1
#define SQUARE(x) (x)*(x)
#define ADD(a, b) a+b
#define POOR_MACRO(a, b) do \
{	int _tmp = (a); \
	(a) = (b); \
	(b) = (_tmp); \
} while(0)

#define DEBUG_PRINT(expr) printf(#expr " = %d\n", expr)
//#define SAFE_MACRO(a, b) do \
//	{ int _tmp = (a); (a) = (b); (b) = _tmp; } while(0)


#define LOG_VAR(var) printf(#var " = %d\n", var##_value)

#include <iostream>

int add(int a, int b)
{
	return a + b;
}
using namespace std;

int main()
{
	int age_value = 25;
	LOG_VAR(age);
	DEBUG_PRINT(3 + 3);
	/*int ret = SQUARE(1 + 2);
	cout << ret << endl;
	int ret2 = add(ret + ret, ret^2);
	cout << ret2;*/
	return 0;
}

//int main()
//{
//	/*int num1 = 10;
//	int num2 = 20;
//	int ret = ADD(num1, num2);
//
//	cout << typeid(ret).name() << endl;
//
//	cout << ret << endl;*/
//	int x = 1, y = 2;
//	POOR_MACRO(x , y);
//	add(x + 2, 4);
//	return 0;
//}
//class A
//{
//public:
//	void func()
//	{
//		std::cout << "void func()" << std::endl;
//	}
//};
//
//int main()
//{
//	A* ptr = nullptr;
//	ptr->func();
//	(*ptr).func();
//	return 0;
//}


//#define DEBUG 0
//#ifdef DEBUG
//int main()
//{
//	int x = 2;
//	printf("Debug info: x=%d\n", x);  // 仅调试时输出
//	return 0;
//}
//#endif // DEBUG


//#ifdef _WIN32
//    // Windows 平台专用代码
//int main()
//{
//    printf("Running on Windows\n");
//    return 0;
//}
//#elif __linux__
//    // Linux 平台专用代码
//int main()
//{
//    printf("Running on Linux\n");
//    return 0;
//}
//#endif
//inline int square(int x)
//{
//	return x * x;
//}
//
//int main()
//{
//	int a = 2;
//	int b = SQUARE(a++); // a++ * a++
//	int c = 2;
//	int d = square(++c);
//	/*int c = 3;
//	int d = (c++) * (++c);*/
//
//	std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
//	std::cout << "c = " << c << std::endl << "d = " << d << std::endl;
//	return 0;
//}


//class Date
//{
//public:
//	
//private:
//	int _day;
//	int _month;
//	int _year;
//};
//int main()
//{
//	/*const char* str_array[] = { "Hello", "World", "!" };
//	const char** row = str_array;
//	for (int i = 0; i < 3; ++i)
//	{
//		std::cout << *row[i] << std::endl;
//		printf("%c\n", row[i]);
//	}*/
//	/*int a = 10;
//	int b = 20;
//	int c = 30;
//	int* cnt_arr[] = { &a, &b, &c };
//	int** row = cnt_arr;
//	for (int i = 0; i < 3; ++i)
//	{
//		std::cout << row[i] << std::endl;
//	}*/
//
//	const char* str = "hello";
//	std::cout << *str << std::endl;
//	return 0;
//}
