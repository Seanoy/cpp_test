#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
	vector<int> nums;

public:
	void Insert(int num)
	{
		int i = 0;
		int size = nums.size();
		if (size != 0) {
			for (i = 0; i < size; i++)
			{
				if (nums[i] >= num) {
					nums.insert(nums.begin() + i, num);
					break;
				}
			}
		}
		if (size == 0 || i == size)
			nums.push_back(num);
	}

	double GetMedian()
	{
		int mid = nums.size() / 2;
		return (nums.size() % 2 == 1) ? nums[mid] : ((double)(nums[mid - 1] + nums[mid]) / 2);
	}

};

int main(void)
{
	Solution s;
	s.Insert(5);
	cout << s.GetMedian() << endl;
	s.Insert(2);
	cout << s.GetMedian() << endl;
	s.Insert(3);
	cout << s.GetMedian() << endl;
	s.Insert(4);
	cout << s.GetMedian() << endl;
	s.Insert(1);
	cout << s.GetMedian() << endl;
	s.Insert(6);
	cout << s.GetMedian() << endl;
	s.Insert(7);
	cout << s.GetMedian() << endl;
	s.Insert(0);
	cout << s.GetMedian() << endl;
	s.Insert(8);
	cout << s.GetMedian() << endl;
	return 0;
}
