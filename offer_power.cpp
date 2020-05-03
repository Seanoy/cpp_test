#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0)
			return 1.0;
		if (exponent == 1)
			return base;
		else if (exponent == -1)
			return 1 / base;

		if (exponent % 2 == 0)
		{
			return Power(base*base, exponent / 2);
		}
		else
		{
			if (exponent > 0)
				return Power(base*base, exponent / 2)*base;
			else
				return Power(base*base, exponent / 2) / base;
		}
	}
};

int main(void)
{
	Solution s;
	cout << s.Power(2, -4);

	return 0;
}
