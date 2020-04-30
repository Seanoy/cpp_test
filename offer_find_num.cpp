#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row, col;//ппап
		row = array.size();
		col = array[0].size();
		int i, j;
		for (i = 0, j = col-1; i <= row && j >= 0;)
		{
			if (target == array[i][j])
				return true;
			else if (target < array[i][j])
			{
				j--;
				continue;
			}
			else
			{
				i++;
				continue;
			}
		}
		return false;
	}
};

int main(void)
{
	vector<vector<int> > array = { {1, 2, 8, 9},{2, 4, 9, 12},{4, 7, 10, 13},{6, 8, 11, 15 } };
	Solution s;
	s.Find(7,array);
	return 0;
}
