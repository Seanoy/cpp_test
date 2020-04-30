#include <iostream>

using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		unsigned int temp = n;
		while (temp)
		{
			if (temp & 0x01)
				count++;
			temp >>= 1;
		}
		return count;
	}
};

int main(void)
{
	Solution s;
	cout<<s.NumberOf1(-1);
	return 0;
}
