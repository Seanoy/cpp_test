#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int left, right, mid;
		int min = INT16_MAX;
		const int n = rotateArray.size();
		left = 0;
		right = n - 1;
		if (n == 0) return 0;
		if (n == 1) return rotateArray[0];

		while (left <= right) {
			mid = (left + right) / 2;

			if (rotateArray[mid] < min) min = rotateArray[mid];
			//在左半边，最小数必定不在那里

			if (rotateArray[mid] >= rotateArray[0]) {
				left = mid + 1;
			}
			//在右半边
			else if (rotateArray[mid]<=min)
			{
				right = mid - 1;
			}			
		}
		return min;
	}
};


int main(void)
{
	Solution s;
	vector<int> a{ 3,4,5,1,2 };
	cout << s.minNumberInRotateArray(a);
	return 0;
}

