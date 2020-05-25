#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int thisSum, maxSum;
		thisSum = 0;
		maxSum = INT_MIN;
		for (int i = 0; i < array.size(); i++) {
			thisSum += array[i];
			if (thisSum > maxSum)
				maxSum = thisSum;
			if (thisSum < 0)
				thisSum = 0;
		}
		return maxSum;
	}
};

int main(void)
{
	vector<int>a{ -2,-8,-1,-5,-9 };
	Solution s;
	cout << s.FindGreatestSumOfSubArray(a);

	return 0;
}
