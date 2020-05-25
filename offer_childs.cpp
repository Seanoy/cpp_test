#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n <= 0 || m <= 0)
		{
			return -1;
		}
		int ans = 0;
		for (int i = 2; i < n+1 ; i++)
		{
			ans = (ans + m) % i;
		}
		return ans;
	}
};

int main(void)
{
	Solution s;
	cout << s.LastRemaining_Solution(5, 3);

	return 0;
}
