#include <iostream>
using namespace std;
int main(char argc, char** argv)
{
	int a;
	char b;
	float c;
	double d;
	short int e;
	long long int f;
	char *p1;
	char *p2;
	char k[10] = { 0 };
	p2 = k;
	cout << sizeof(int) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(short int) << endl;
	cout << sizeof(long long int) << endl;
	cout << sizeof(char *) << endl;
	cout << sizeof(int *) << endl;
	cout << sizeof(NULL) << endl;
	cout << sizeof(*p2) << endl;

	system("pause");

	return 0;
}
