#include <iostream>
#include <vector>
#include <string>

using namespace std;

//n=1 f(1)=1
//n=2 f(2)=2
//n=3 第一条横有f(n-2)种 第一条竖有f(n-1)种 

class Solution {
public:
	int rectCover(int number) {
		if (number <= 2)
			return number;
		int fn_1 = 2;//f(n-1) f(2)
		int fn_2 = 1;//f(n-2) f(1)
		int cur;
		for (int i = 3; i <= number; i++)
		{
			cur = fn_1 + fn_2;
			fn_2 = fn_1;
			fn_1 = cur;
		}
		return cur;
	}
};

int main(void)
{
	Solution s;
	cout<<s.rectCover(4);


	return 0;
}
