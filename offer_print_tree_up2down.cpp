#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

/*
				0
			1		2
		3	   4 5		6

*/
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ret;
		if (root == nullptr)
			return ret;
		queue<TreeNode*> que;//存放指针的队列
		que.push(root);//将根放入队列
		while (!que.empty())//当队列不为空时一直执行
		{
			TreeNode *node = que.front();//获取队列第一个数据
			que.pop();//获取到值之后弹出数据
		
			ret.push_back(node->val);
			if(node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
		return ret;
	}
};

int main(void)
{
	TreeNode a(0);
	TreeNode b(1);
	TreeNode c(2);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(5);
	TreeNode g(6);

	a.left = &b;
	a.right = &c;
	a.left->left = &d;
	a.left->right = &e;
	a.right->left = &f;
	a.right->right = &g;

	Solution s;
	vector<int> vec;
	vec = s.PrintFromTopToBottom(&a);
	for (auto i : vec)
		cout << i << endl;
	return 0;
}
