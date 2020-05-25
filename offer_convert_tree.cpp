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
	TreeNode* pre = nullptr;
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr) {
			return nullptr;
		}
		Convert(pRootOfTree->right);
		if (pre != nullptr) {
			pRootOfTree->right = pre;
			pre->left = pRootOfTree;
		}
		pre = pRootOfTree;
		Convert(pRootOfTree->left);
		return pre;
	}
};

int main(void)
{


	return 0;
}
