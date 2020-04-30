#include <iostream>

using namespace std;

class Solution1 {
public:
	int jumpFloor(int number) {
		int count = 0;
		if (number == 1)//Base Case
			return 1;
		if (number == 2)//Base Case
			return 2;
		return jumpFloor(number-1)+ jumpFloor(number-2);
	}
};

class Solution2 {
public:
	int jumpFloor(int number) {
		int a = 1, b = 1;
		for (int i = 1; i < number; i++)
		{
			a = a + b;
			b = a - b;
		}
		return a;
	}
};

int main(void)
{
	Solution2 s;
	cout<<s.jumpFloor(3);
	return 0;
}

