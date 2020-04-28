#include <iostream>

using namespace std;

struct a {
	int x : 1;
	int y : 4;
	int z : 32;
};


int main(void)
{
	char *p = "a";
	int i = (int)"a";
	int i2 = (int)p;
	int i5 = reinterpret_cast<int>(&p);
	cout << p << endl;
	cout << &p << endl;
	cout << i << endl;
	cout << i2 << endl;
	cout << (int)"a" << endl;
	cout << i5 << endl;
	return 0;
}
