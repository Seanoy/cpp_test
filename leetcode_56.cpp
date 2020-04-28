#include <vector>
#include <iostream>
using namespace std;
//https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-by-leetcode/
class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int ret = 0;
		for (int n : nums)
			ret ^= n;//全员异或，结果为两个不同数字的异或
		int div = 1;
		while ((div&ret) == 0)//从最低的不为零的位开始
			div <<= 1;
		int a = 0, b = 0;//将两个数分成两组，对应位为1的数为a组，对应位为0的数为b组
		for (int n : nums)//相同数字分在相同的组，不同数字分在不同的组，这是因为异或的性质，对应位为1代表两个数不同
			if (div&n)
				a ^= n;
			else
				b ^= n;
		return vector<int>{a, b};
	}
};

int main(void)
{
	vector<int>a = { 1,1,7,8 };
	Solution s;
	vector<int>b = s.singleNumbers(a);
	for (auto i : b)
		cout << i << endl;
	return 0;
}
