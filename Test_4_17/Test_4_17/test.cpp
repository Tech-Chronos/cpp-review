#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class A
{
public:
	friend ostream operator<<(ostream& out, A& a);
private:
	int _a = 5;
	double _b = 20;
};

ostream operator<<(ostream& out, A& a)
{
	out << a._a << a._b << endl;
	return out;
}

int main()
{

	return 0;
}