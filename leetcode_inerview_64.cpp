#include <iostream>

using namespace std;

class Solution {
private:
	int sum = 0;
public:
	int sumNums(int n) {
		sum += n;
		n==0 || sumNums(--n);//n>0 && sumNum(--n)
		return sum;
	}
};

int main(void)
{
	Solution so;
	cout << so.sumNums(3) << endl;
	return 0;
}
