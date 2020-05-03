#include <iostream>
#include <vector>
#include <string>

using namespace std;

//�������У����ң� �������У��ϵ��£� �������У��ҵ��� �������У��µ��ϣ�
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> *ret = new vector<int>();
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return *ret;
		int up = 0;//�ϱ߽�
		int down = matrix.size()-1;//�±߽�
		int left = 0;//��߽�
		int right = matrix[0].size()-1;//�ұ߽�
		int i;
		//�ϱ߽�->�ұ߽� �ϱ߽�+1
		//�ұ߽�->�±߽� �ұ߽�-1
		//�±߽�->��߽� �±߽�+1
		//��߽�->�ϱ߽� ��߽�+1
		//��߽�>�ұ߽� break
		//�ϱ߽�>�±߽� break
		while (1)
		{
			for (i = left; i <= right; i++)
				ret->push_back(matrix[up][i]);
			up++;
			if (up > down)
				break;
			for (i = up; i <= down; i++)
				ret->push_back(matrix[i][right]);
			right--;
			if (left > right)
				break;
			for (i = right; i >= left; i--)
				ret->push_back(matrix[down][i]);
			down--;
			if (up > down)
				break;
			for (i = down; i >= up; i--)
				ret->push_back(matrix[i][left]);
			left++;
			if (left > right)
				break;
		}
		return *ret;
	}
};

int main(void)
{
	Solution s;
	vector<vector<int> >a{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16 } };
	vector<int> b = s.printMatrix(a);
	for (auto i : b)
		cout <<  i;
	return 0;
}
