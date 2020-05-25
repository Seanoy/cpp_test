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
			//��xor1���ҵ���һ����ͬ��λ�����ݽ��з��࣬����Ϊ�������ж����ݽ����������ҵ�������Ҫ�Ľ��
			xor1 = xor1^data[i];
		}
		int index = 1;
		while ((index & xor1) == 0)
		{
			index = index << 1;//��Ϊ�����ж��λΪ1������Ҫ��һ��λ��
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
