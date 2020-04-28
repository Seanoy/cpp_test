#include <vector>
#include <iostream>
using namespace std;
//https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-by-leetcode/
class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int ret = 0;
		for (int n : nums)
			ret ^= n;//ȫԱ��򣬽��Ϊ������ͬ���ֵ����
		int div = 1;
		while ((div&ret) == 0)//����͵Ĳ�Ϊ���λ��ʼ
			div <<= 1;
		int a = 0, b = 0;//���������ֳ����飬��ӦλΪ1����Ϊa�飬��ӦλΪ0����Ϊb��
		for (int n : nums)//��ͬ���ַ�����ͬ���飬��ͬ���ַ��ڲ�ͬ���飬������Ϊ�������ʣ���ӦλΪ1������������ͬ
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
