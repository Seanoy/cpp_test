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

前序遍历 pre{ 1, 2, 3, 4, 5, 6 };
后序遍历 vin{ 3, 2, 1, 5, 4, 6 };
前序第一个值是root的，然后在后序中查找它的位置
根据该位置将前序和后序拆成两份，递归进行
	  ↓
1, 2, 3, 4, 5, 6   ->    {2, 3}    {4, 5, 6}
3, 2, 1, 5, 4, 6   ->    {3, 2}    {5, 4, 6}
	  ↑
*/

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() && vin.empty())//两者都为空时
			return nullptr;
		TreeNode * root = new TreeNode(pre[0]);//根据前序遍历确定根的位置
		//然后根据root的值确定它在中序的位置，从而获取左子树/右子树的前序和中序
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
