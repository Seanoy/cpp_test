#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*

ǰ����� pre{ 1, 2, 3, 4, 5, 6 };
������� vin{ 3, 2, 1, 5, 4, 6 };
ǰ���һ��ֵ��root�ģ�Ȼ���ں����в�������λ��
���ݸ�λ�ý�ǰ��ͺ��������ݣ��ݹ����
	  ��
1, 2, 3, 4, 5, 6   ->    {2, 3}    {4, 5, 6}
3, 2, 1, 5, 4, 6   ->    {3, 2}    {5, 4, 6}
	  ��
*/

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() && vin.empty())//���߶�Ϊ��ʱ
			return nullptr;
		TreeNode * root = new TreeNode(pre[0]);//����ǰ�����ȷ������λ��
		//Ȼ�����root��ֵȷ�����������λ�ã��Ӷ���ȡ������/��������ǰ�������
		for (unsigned int i = 0; i < vin.size(); i++)
		{
			if (pre[0] == vin[i])
			{
				vector<int> pre_left_new(pre.begin() + 1, pre.begin() + i + 1);
				vector<int> pre_right_new(pre.begin() + i + 1, pre.end());
				vector<int> vin_left_new(vin.begin(), vin.begin() + i);
				vector<int> vin_right_new(vin.begin() + i + 1, vin.end());

				root->left = reConstructBinaryTree(pre_left_new, vin_left_new);
				root->right = reConstructBinaryTree(pre_right_new, vin_right_new);
				break;
			}
		}
		return root;
	}
};

int main(void)
{
	vector<int> pre{ 1, 2, 3, 4, 5, 6 };
	vector<int> vin{ 3, 2, 1, 5, 4, 6 };
	Solution s;
	TreeNode *root = new TreeNode(0);
	root = s.reConstructBinaryTree(pre, vin);
	return 0;
}
