#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class A
{
public:
	A() = default;
	A(int a, double b)
		:_a(a),
		_b(b)
	{}

	friend ostream& operator<<(ostream& out, A& a);
private:
	int _a = 5;
	double _b = 20;
};

ostream& operator<<(ostream& out, A& a)
{
	out << a._a << " " << a._b;
	return out;
}

int main()
{
	A a = { 2, 3.0 };
	A b;
	cout << a << b << endl;
	return 0;
}