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
			vec.push_back(pushV[i++]);//ѹջ
			while (j < popV.size() && vec.back() == popV[j])//�����Ƿ����ƥ����
			{
				vec.pop_back();//������ƥ�����
				j++;//����������һ������
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
