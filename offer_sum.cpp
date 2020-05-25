#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int num[2] = { 0,0 };
		int min_mul = INT_MAX;
		int temp;
		vector<int> ret;
		if (array.empty())
		{
			return ret;
		}
		for (int i = 0; i < array.size(); i++)
		{
			for (int j = i + 1; j < array.size(); j++)
			{
				if ((array[i] + array[j]) == sum)
				{
					temp = array[i] * array[j];
					if (temp< min_mul)
					{
						min_mul = temp;
						num[0] = array[i];
						num[1] = array[j];
					}
				}
			}
		}
		if (min_mul != INT_MAX)
		{
			ret.push_back(num[0]);
			ret.push_back(num[1]);

		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<int> a{ 1,2,3,4,5,6 };
	vector<int>ret;
	ret = s.FindNumbersWithSum(a,5);
	for (auto i : ret)
		cout << i << endl;
	return 0;
}
