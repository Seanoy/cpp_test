#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
f(k),k=1,2,...,n 代表剩下k级台阶时有几种跳法

f(1) = 1
f(2) = f(2-1) + f(2-2)
f(3) = f(3-1) + f(3-2) + f(3-3)
...
f(n) = f(n-1) + f(n-2) + ... + f(n-n)
*/
class Solution {
public:
	int jumpFloorII(int number) {
		if (number <= 0)
			return -1;
		return 1 << (number - 1);
	}
};

int main(void)
{


	return 0;
}
