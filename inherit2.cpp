#include <iostream>
#include <string>
using namespace std;

class Shape
{
protected:
	int width, height;
public:
	Shape(int a = 0, int b = 0)
	{
		width = a;
		height = b;
	}
	virtual int area(void)
	{
		cout << "Parent class area :" << endl;
		return 0;
	}
};

class Rectangle :public Shape
{
public:
	Rectangle(int a = 0, int b = 0) :Shape(a, b) {}
	int area(void)
	{
		int v = width*height;
		cout << "Rectangle class area :" << v << endl;
		return v;
	}
};

class Triangle :public Shape
{
public:
	Triangle(int a=0,int b=0):Shape(a,b){}
	int area(void)
	{
		int v = width*height / 2;
		cout << "Triangle class area :" << v << endl;
		return v;
	}
};

int main()
{
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle tri(10, 5);

	shape = &rec;
	shape->area();

	shape = &tri;
	shape->area();

	return 0;
}
