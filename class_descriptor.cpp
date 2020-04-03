#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Box
{
	public:
		double length;
		double breadth;
		double height;
		double volumn;
		double getVolumn1(void);
		double getVolumn2(void)
		{
			return length*breadth*height;
		}
		double getVolumn3(void);
		Box();
		 ~Box();
};

 Box::Box(void): volumn(0)//初始化字段，只存在于构造函数
{
	cout << "Calling the Box constructor" << endl;
}

 Box::~Box(void)
{
	cout << "Calling the Box destructor" << endl;
}


double Box::getVolumn1(void)
{
	return length * breadth * height;
}

class Family
{
	protected:
		int members;
	private:
		char *treasure;
	public:
		char *first_name[10];
		char *last_name;
		void setTreasure(char *treasure)
		{
			this->treasure = treasure;
		}
		char* getTreasure(void)
		{
			return this->treasure;
		}
};

class FamilyData :Family
{
	public:
		void setFamilyMember(int menbers);
		int getFamilyMember(void);
};

int FamilyData::getFamilyMember(void)
{
	return members;
}

void FamilyData::setFamilyMember(int menbers)
{
	members = menbers;
}
int count1=0;
int count2 = 0;
int flag1 = 0;
int flag2 = 0;
class Line
{
public:
	int getLength(void);
	Line(int len);			//简单的构造函数
	Line(const Line &obj);	//拷贝的构造函数
	~Line();

private:
	int *length;
};

Line::Line(int len)
{
	count1 += 1;
	flag1 += 1;
	cout << "Calling Line constructor " << "count1:" << count1 << " count2:" << count2 << endl;

	length = new int;
	*length = len;
}

Line::Line(const Line &obj)
{
	count2 += 1;
	flag2 += 1;
	cout << "Calling the Line copy constructor " << "count1:" << count1 << " count2:" << count2 << endl;

	length = new int;
	*length = *obj.length;
}

Line::~Line(void)
{
/*	if (flag1)
	{
		count1 -= 1;
		flag1 -= 1;
	}
	if (flag2)
	{
		count2 -= 1;
		flag2 -= 1;
	}*/
	cout << "Calling destructor " << "count1:"<< count1 << " count2:" << count2 << endl;
	delete length;
}

int Line::getLength()
{
	return *length;
}

void display(Line obj)
{
	cout << "Line size is " << obj.getLength() << endl;
}

int main(int argc, char* argv[])
{
/*	Box box1;
	cout << sizeof(box1) << endl;
	box1.breadth = 1.0;
	box1.height = 2.0;
	box1.length = 2.5;
	cout << box1.getVolumn1() << endl;
	cout << box1.getVolumn2() << endl;

	Family family;
	family.first_name[0] = "sean";
	family.last_name = "Ouyang";
	family.setTreasure("Knowledge");
	printf("%s %s %s\r\n", family.first_name[0], family.last_name, family.getTreasure());
	
	FamilyData fdata;
	fdata.setFamilyMember(4);
	cout << fdata.getFamilyMember() << endl;
	*/
	Line line1(10);
	cout << "create line1" << endl;
	Line line2 = line1;
	cout << "create line2" << endl;

	cout << "display line1" << endl;

	display(line1);
	cout << "display line2" << endl;

	display(line2);

//	system("pause");
	return 0;
}

