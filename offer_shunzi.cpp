#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		int buf[14] = { 0 };
		buf[0] = -5;
		int max = -1;
		int min = 14;
		if (numbers.size() == 0)
			return false;
		for (int i = 0; i < numbers.size(); i++) {
			buf[numbers[i]]++;
			if (numbers[i] ==0)
				continue;
			if (buf[numbers[i]] > 1)
				return false;
			if (numbers[i] > max)
				max = numbers[i];
			if (numbers[i] < min)
				min = numbers[i];
		}
		if (max - min < 5)
			return true;
		
		return false;
	}
};

int main(void)
{
	Solution s;
	vector<int> a{ 0,3,2,6,4 };
	cout << boolalpha << s.IsContinuous(a);

	return 0;
}
