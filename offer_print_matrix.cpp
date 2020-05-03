#include <iostream>
#include <vector>
#include <string>

using namespace std;

//最上面行（左到右） 最右面列（上到下） 最下面行（右到左） 最左面列（下到上）
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> *ret = new vector<int>();
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return *ret;
		int up = 0;//上边界
		int down = matrix.size()-1;//下边界
		int left = 0;//左边界
		int right = matrix[0].size()-1;//右边界
		int i;
		//上边界->右边界 上边界+1
		//右边界->下边界 右边界-1
		//下边界->左边界 下边界+1
		//左边界->上边界 左边界+1
		//左边界>右边界 break
		//上边界>下边界 break
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
