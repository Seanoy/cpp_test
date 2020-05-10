#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int buffer[1000] = { 0 };
		for (int i = 0; i < numbers.size(); i++)
		{
			buffer[numbers[i]]++;
		}
		for (int i = 0; i < 1000; i++)
		{
			if (buffer[i] > numbers.size() / 2)
				return i;
		}
		return 0;
	}
};

int main(void)
{
	float a = 1.0f;
	cout << (int)a << endl;
	cout << &a << endl;
	cout << (int&)a << endl;
	cout << boolalpha << ((int)a == (int&)a) << endl;
	return 0;
}
