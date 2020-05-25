#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
链接：https://www.nowcoder.com/questionTerminal/bd7f978302044eee894445e244c7eee6?answerType=1&f=discussion
来源：牛客网

思路是分别计算个位、十位、百位........上出现 1 的个数。
以  n = 216为例：
个位上： 1 ，11，21，31，.....211。个位上共出现（216 / 10） + 1个 1 。因为除法取整，210~216间个位上的1取不到，所以我们加8进位。你可能说为什么不加9，n = 211怎么办，这里把最后取到的个位数为1的单独考虑，先往下看。
十位上：10~19，110~119，210~216.   十位上可看成 求（216 / 10） = 21 个位上的1的个数然后乘10。这里再次把最后取到的十位数为1的单独拿出来，即210~216要单独考虑 ，个数为（216 % 10） + 1.这里加8就避免了判断的过程。
后面以此类推。
时间复杂度 O(logN)
*/
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		int temp = 0;

		for (int m = 1; m <= n; m *= 10)
		{
			int a = n / m;//余
			int b = n % m;//商
			count += (a + 8) / 10 * m + (a % 10 == 1 ? b + 1 : 0);
		}
		return count;
	}
};

int main(void)
{
	Solution s;
	cout<<s.NumberOf1Between1AndN_Solution(21);

	return 0;
}
