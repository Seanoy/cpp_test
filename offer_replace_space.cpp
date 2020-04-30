#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	void moveRight(char* str, int length, int position)
	{
		for (int i = length - 1; i > position; i--)
		{
			str[i + 2] = str[i];
		}
	}
	void replaceSpace(char *str, int length) {
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
			{
				moveRight(str, length, i);
				length += 2;
				memcpy(str + i , "%20",3);
			}
		}
	}
};

int main(void)
{
	Solution s;
	char a[10] = "1 2 3";
	s.replaceSpace(a, 5);
	cout << a << endl;
	return 0;
}
