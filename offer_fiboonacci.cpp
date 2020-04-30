#include <iostream>

using namespace std;

class Solution {
public:
	int Fibonacci(int n) {
		int x1 = 0, x2 = 1, temp = x1;
		if (n == 0) return 0;
		if (n == 1) return 1;
		while (n>1)
		{
			temp = x2;
			x2 += x1;
			x1 = temp;
			n--;
		}
		return x2;
	}
};

int main(void)
{
	Solution s;
	cout<<s.Fibonacci(7);
	return 0;
}

