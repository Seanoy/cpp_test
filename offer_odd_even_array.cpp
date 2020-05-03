#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	//不改变次序，奇前偶后
	void reOrderArray(vector<int> &array) {
		vector<int> temp;
		int odd = 0;
		for (unsigned int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 0)//偶数，放在后面
			{
				temp.push_back(array[i]);
			}
			else//奇数，放在前面
			{
				temp.insert(temp.begin() + odd, array[i]);
				odd += 1;
			}
		}
		array.assign(temp.begin(), temp.end());
	}
};

int main(void)
{
	vector<int>a{ 1, 8, 5, 7, 2 };
	Solution s;
	s.reOrderArray(a);

	return 0;
}
