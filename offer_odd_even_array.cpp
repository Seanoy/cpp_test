#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	//���ı������ǰż��
	void reOrderArray(vector<int> &array) {
		vector<int> temp;
		int odd = 0;
		for (unsigned int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 0)//ż�������ں���
			{
				temp.push_back(array[i]);
			}
			else//����������ǰ��
			{
				temp.insert(temp.begin() + odd, array[i]);
				odd += 1;
			}
		}
		array.assign(temp.begin(), temp.end());
	}
};

int main(void)
{
	vector<int>a{ 1, 8, 5, 7, 2 };
	Solution s;
	s.reOrderArray(a);

	return 0;
}
