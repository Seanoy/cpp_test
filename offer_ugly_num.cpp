#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_NUM 1700

class Solution {
private:
	long long num[MAX_NUM];
public:
	Solution()
	{
		num[0] = 1;
		long long ugly, i2 = 0, i3 = 0, i5 = 0;

		for (int i = 1; i < MAX_NUM; i++)
		{
			ugly = min(min(num[i2] * 2, num[i3] * 3), num[i5] * 5);
			num[i] = ugly;

			if (ugly == num[i2] * 2)++i2;
			if (ugly == num[i3] * 3)++i3;
			if (ugly == num[i5] * 5)++i5;
		}
	}

	long long GetUglyNumber_Solution(int index) {
		if (index == 0)
			return 0;
		return num[index - 1];
	}

};

int main(void)
{


	return 0;
}
