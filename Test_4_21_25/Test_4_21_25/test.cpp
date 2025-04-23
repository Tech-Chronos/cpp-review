#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass(int a = 0, int b = 0, int c = 0)
	{
		_a = a;
		_b = b;
		_c = c;
		cout << "MyClass() -> _a = " << _a << endl;
		cout << "MyClass() -> _b = " << _b << endl;
		cout << "MyClass() -> _c = " << _c << endl;
	}
	/*~MyClass()s
	{
		cout << "~MyClass()" << endl;
	}*/
private:
	int _a;
	int _b;
	int _c;
};
int main(int argc, char* argv[])
{
	/*cout << argc << endl;
	cout << *argv[0] << endl;*/
	MyClass* obj = new MyClass[3]{ {2,3,4} };
	int* ptr = new int(9);
	cout << *ptr << endl;

	/*MyClass* obj = (MyClass*)operator new(sizeof MyClass * 4);
	new(obj)MyClass({1,2,3});
	new(obj + 1)MyClass({4,3,5});*/
	return 0;
}