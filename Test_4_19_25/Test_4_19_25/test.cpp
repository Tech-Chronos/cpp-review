#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//int main()
//{
//	int* ptr = new int[5] {1,2};
//	return 0;
//}

class MyClass
{
public:
	MyClass()
	{
		cout << "MyClass()" << endl;
	}
private:
};

int main()
{
	MyClass* pmyclass = (MyClass*)operator new(sizeof(MyClass));
	return 0;
}