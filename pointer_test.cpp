int main(void)
{

	int i = 0;
	int *p = &i;
	int **pp = (&p);
	cout << &i << endl;//变量i的地址
	cout << p << endl;//指针p指向变量i的地址
	cout << *p << endl;//指针p指向变量i的地址对应的值
	cout << &p << endl;//指针p本身的地址
	cout << pp << endl;//指针pp指向指针p的地址
	cout << *pp << endl;//指针pp指向指针p的地址对应的值，即变量i的地址
	cout << &pp << endl;//指针pp本身的地址
	return 0;
}
