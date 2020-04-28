#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string.h>
using namespace std;

/*
void foo(int *p)
{
	*p = 10;
}
void foo1(int *p)
{
	cout << "foo:" <<&p << endl;
	p = (int *)malloc(100);
}*/


int main()
{
/*	int a;
	cout << &a << endl;
	*(int* const)(&a) = 1234;
	cout << a << endl;*/

/*	int *p2 = (int *)0x123;
	printf("%x", p2);*/


/*	auto a = 1234567891;
	cout << a <<"  "<< sizeof(a) << endl;
	auto p = new auto('9');
	printf("0x%X ", *p);
	cout << "  " << sizeof(p) << endl;
	*/

/*	register int count;
	cout << &count<< "    " << sizeof(count) << endl;
	*/

	/*	int a = 1, b = 1;

	auto foo1 = [](int x, int y) { return x < y; };
	auto foo2 = [](int x, int y) mutable-> int { int z = x + y; return z + x; };
	auto foo3 = [=, &a, &b]() {return a + b; };
		cout << foo1(1, 2) << endl;
	cout << foo2(1, 2) << endl;
	cout << foo3() << endl;*/

/*	if (typeid(0.123f) == typeid(float))
		printf("float\r\n");

	if (typeid(0.123) == typeid(double))
		printf("double\r\n");

	if (typeid(0.123l) == typeid(long double))
		printf("long double\r\n");

	cout << hypot(3.0, 4.0) << endl;*/

/*	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++)
	{
		cout << rand()%10 << endl;
	}*/

/*	int a = 20;
	int *p = &a;
	cout << "main1:" <<&p << endl;

	foo1(p);
	cout << "main2:" << &p << endl;

	cout << a << endl;*/

/*	string str = "Hello";
	int *p = NULL;
	cout << sizeof(str) << endl;//28
	cout << str.size() << endl;//5
	*/

/*	struct tm *info;
	time_t tim;
	time(&tim);
	cout << ctime(&tim) << endl;
	info = gmtime(&tim);
	printf("ÖÐ¹ú£º%2d:%02d\n", (info->tm_hour + 8) % 24, info->tm_min);
	*/


	system("pause"); 
	return 0;
}
