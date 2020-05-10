#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty())
			return false;
		vector<int> vec;
		for (int i = 0, j = 0; i < pushV.size();)
		{
			vec.push_back(pushV[i++]);//压栈
			while (j < popV.size() && vec.back() == popV[j])//查找是否存在匹配项
			{
				vec.pop_back();//存在则将匹配项弹出
				j++;//继续查找下一个数字
			}
		}
		return vec.empty();
	}
};

int main(void)
{
	vector<int> pushV{ 1,2,3,4,5 };
	vector<int> popV{ 4,5,3,2,1 };
	Solution s;
	cout << s.IsPopOrder(pushV, popV);
	return 0;
}
