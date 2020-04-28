#include <iostream>
using namespace std;
/*class B
{
public:
	virtual int shift(int n = 2) const { return n << 2; }
};

class D :public B
{
public:
	int shift(int n) const { return n << 3; }
};
int main()
{
	const D d;
	const B *b = &d;
	std::cout << b->shift() << std::endl;
	system("pause");
	return 0;
}*/
int main()
{
	char a[] = {"HELLO"};
	char b[] = {"HELLO"};
	cout << a << endl;
	cout << b << endl;
	if (a == b)
		printf("equal");
	else
		printf("not equal");

	cout << strcmp(a, b) << endl;

	system("pause");
	return 0;
}



