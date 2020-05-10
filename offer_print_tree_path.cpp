#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <numeric>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<vector<int>>  FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>>  result;
		if (root == nullptr)
			return result;
		stack<TreeNode*> stk1;
		stack<vector<int>> stk2;
		stk1.push(root);
		stk2.push({ root->val });
		while (!stk1.empty())
		{
			TreeNode* node;
			vector<int> path;
			node = stk1.top();
			stk1.pop();
			path = stk2.top();
			stk2.pop();
			if (node->left == nullptr && node->right == nullptr&& expectNumber == accumulate(path.begin(), path.end(), 0))
				result.push_back(path);
			if (node->right != nullptr)
			{
				stk1.push(node->right);
				path.push_back(node->right->val);
				stk2.push(path);
				path.erase(path.end() - 1);
			}
			if (node->left != nullptr)
			{
				stk1.push(node->left);
				path.push_back(node->left->val);
				stk2.push(path);

			}
		}
		return result;
	}
};

int main(void)
{
	TreeNode a(0);
	a.left = new TreeNode(1);
	a.right = new TreeNode(2);
	a.left->left = new TreeNode(3);
	a.left->right = new TreeNode(4);
	a.right->left = new TreeNode(5);
	Solution s;
	vector<vector<int>> ret;
	ret = s.FindPath(&a, 5);
	for (auto i : ret)
		for (auto j : i)
			cout << j << endl;
	return 0;
}
