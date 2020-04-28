#include <iostream>
#include <string>

using namespace std;

class Shape
{
protected:
	int num1=10;
	int num2=20;
};

class Paint
{
public:	
int showPrice(void)
{
	return price;
}
protected:
	int price = 20;

};


class Rectangle:public Shape, public Paint
{
public:
	int getArea()
	{
		return num1*num2;
	}
};

int main(int argc, char* argv[])
{
	Rectangle Rect;
	cout << Rect.getArea() << endl;
	cout << Rect.showPrice() << endl;
	system("pause");
	return 0;
}
