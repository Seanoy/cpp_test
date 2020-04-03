#include <iostream>

using namespace std;
/*
struct MyException :public exception
{
	const char* what()const throw()
	{
		return "C++ Exception";
	}
};

double division(int a, int b)
{
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (a / b);
}
*/
class Box
{
public:
	Box() {
		cout << "constructor" << endl;
	}
	~Box() {
		cout << "destructor" << endl;
	}
};
int main()
{
/*	int x = 10;
	int y = 20;
	double z;
	try {
		z = division(1, 0);
		cout << z << endl;
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}*/

	
/*	try
	{
		throw MyException();
	}
	catch (MyException& e)
	{
		std::cout << "MyException caught" << std::endl;
		std::cout << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		//其他的错误
	}
	*/

/*	char* pvalue = NULL;   // 初始化为 null 的指针
	pvalue = new char[20]; // 为变量请求内存
	delete[] pvalue;        // 删除 pvalue 所指向的数组
	*/

/*	int i, j;
	int **array;
	array = new int *[10];
	for (i = 0; i < 10; i++)
	{
		array[i] = new int[20];
	}

	for (i = 0; i<10; i++) {
		for (j = 0; j<20; j++) {
			array[i][j] = j*i;
		}
	}
	//打印数据   
	for (i = 0; i<10; i++) {
		for (j = 0; j<20; j++)
		{
			if (j == 0) cout << endl;
			cout << array[i][j] << "\t";
		}
	}

	for (i = 0; i < 10; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	*/

/*	int i, j, k;
	int ***p;
	p = new int **[2];
	for (i = 0; i < 2; i++)
	{
		p[i] = new int *[3];
		for (j = 0; j < 3; j++)
		{
			p[i][j] = new int[4];
		}
	}
	//输出 p[i][j][k] 三维数据
	for (i = 0; i<2; i++)
	{
		for (j = 0; j<3; j++)
		{
			for (k = 0; k<4; k++)
			{
				p[i][j][k] = i + j + k;
				cout << p[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			delete[]p[i][j];
		}
	}

	for (i = 0; i < 2; i++)
	{
		delete[]p[i];
	}
	delete[]p;
	*/

	Box *boxarray = new Box[4];
	delete[]boxarray;


	system("pause");
	return 0;
}
