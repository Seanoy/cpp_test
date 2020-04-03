#include <iostream>
#include <string>

using namespace std;

class Boy
{
private:
	string beloved_girl;
public:
	string name;
	int age;
	void putGirl(string girl);
	friend void printGirl(Boy boy);
};

void Boy::putGirl(string girl)
{
	beloved_girl = girl;
}

//�ú�������Ԫ����
void printGirl(Boy boy)
{
	cout << boy.beloved_girl << endl;
}

class Box
{
public:
	static int objectCount;
	// ���캯������
	Box(double l = 2.0, double b = 2.0, double h = 2.0)
	{
		cout << "Constructor called." << endl;
		length = l;
		breadth = b;
		height = h;
		// ÿ�δ�������ʱ���� 1
		objectCount++;
	}
	double Volume()
	{
		return length * breadth * height;
	}
	static int getCount()
	{
		return objectCount;
	}
private:
	double length;     // ����
	double breadth;    // ���
	double height;     // �߶�
};

// ��ʼ���� Box �ľ�̬��Ա
int Box::objectCount = 0;


int main(int argc, char* argv[])
{
/*	Boy boy;
	string name = "sean";
	string girl = "selina";
	boy.name = name;
	boy.age = 22;
	boy.putGirl(girl);
	printGirl(boy);
	*/
	// �ڴ�������֮ǰ������������
	cout << "Inital Stage Count: " << Box::getCount() << endl;

	Box Box1(3.3, 1.2, 1.5);    // ���� box1
	Box Box2(8.5, 6.0, 2.0);    // ���� box2

								// �ڴ�������֮��������������
	cout << "Final Stage Count: " << Box::getCount() << endl;

	system("pause");
	return 0;
}
