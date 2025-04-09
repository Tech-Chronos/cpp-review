#define  _CRT_SECURE_NO_WARNINGS 1
//#define SQUARE(x) x*x
#include <iostream>

class A
{
public:
	void func()
	{
		std::cout << "void func()" << std::endl;
	}
};

int main()
{
	A* ptr = nullptr;
	ptr->func();
	(*ptr).func();
	return 0;
}

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
