#include <iostream>
#include <vector>
#include <string>

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
	bool recur(TreeNode* A, TreeNode* B)
	{
		if (B == nullptr)//B等于空，表示已遍历到末尾
			return true;
		if (A == nullptr || A->val != B->val)//A为空或值不相等，表示目前不存在B
			return false;
		return recur(A->left, B->left) && recur(A->right, B->right);//找到匹配项后继续依次遍历
	}

	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//两棵树都不为空，遍历两棵树是否相同，不同则继续遍历他们的的左子树和右子树是否相同
		return (pRoot1 != nullptr && pRoot2 != nullptr) && (recur(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
	}
};

int main(void)
{


	return 0;
}
