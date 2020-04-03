#include <iostream>
#include <string>

using namespace std;

//overloaded function
class printData
{
public:

	void print(int i)
	{
		cout << "int:" << i << endl;
	}
	void print(double d)
	{
		cout << "double:" << d << endl;
	}
	void print(char c[])
	{
		cout << "char:" << c << endl;
	}
};

//overloaded operator
class Box
{
public:
	int num;
	void setNum(int number)
	{
		num = number;
	}
	int getNum(void)
	{
		return num;
	}
	Box operator+(const Box& b)
	{
		Box box;
		box.num = this->num + b.num;
		return box;
	}
};


int main(int argc, char* argv[])
{
/*	printData pd;
	pd.print(5);
	pd.print(1.23);
	pd.print("Hello");
	system("pause");*/

	Box box1, box2, box3;
	box1.setNum(10);
	box2.setNum(20);
	box3 = box1 + box2;
	cout << box3.getNum() << endl;

	system("pause");
	return 0;
}
