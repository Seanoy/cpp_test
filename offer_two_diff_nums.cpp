#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int xor1 = 0;
		for (int i = 0; i < data.size(); i++)
		{
			//在xor1中找到第一个不同的位对数据进行分类，分类为两个队列对数据进行异或求和找到我们想要的结果
			xor1 = xor1^data[i];
		}
		int index = 1;
		while ((index & xor1) == 0)
		{
			index = index << 1;//因为可能有多个位为1所以需要求一下位置
		}
		int result1 = 0;
		int result2 = 0;
		for (int i = 0; i < data.size(); i++)
		{
			if ((index & data[i]) == 0)
			{
				result1 = result1 ^ data[i];
			}
			else
			{
				result2 = result2^data[i];
			}
		}
		*num1 = result1;
		*num2 = result2;
	}
};

int main(void)
{


	return 0;
}
