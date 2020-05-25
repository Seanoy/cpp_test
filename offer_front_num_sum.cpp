#include <iostream>
#include <vector>
#include <string>

using namespace std;

//前n个和为100
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> result;
		if (sum <= 0)
			return result;
		int left = 1;
		int right = 2;
		int sumTemp = left + right;
		while (sum > right) {
			if (sumTemp < sum) {
				right++;
				sumTemp += right;
			}
			else if (sumTemp > sum) {
				sumTemp -= left;
				left++;
			}
			else {
				vector<int> list;
				for (int i = left; i <= right; i++) {
					list.push_back(i);
				}
				result.push_back(list);
				right++;
				sumTemp += right;
			}
		}
		return result;
	}
};

int main(void)
{


	return 0;
}
