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
		if (B == nullptr)//B���ڿգ���ʾ�ѱ�����ĩβ
			return true;
		if (A == nullptr || A->val != B->val)//AΪ�ջ�ֵ����ȣ���ʾĿǰ������B
			return false;
		return recur(A->left, B->left) && recur(A->right, B->right);//�ҵ�ƥ�����������α���
	}

	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//����������Ϊ�գ������������Ƿ���ͬ����ͬ������������ǵĵ����������������Ƿ���ͬ
		return (pRoot1 != nullptr && pRoot2 != nullptr) && (recur(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
	}
};

int main(void)
{


	return 0;
}
