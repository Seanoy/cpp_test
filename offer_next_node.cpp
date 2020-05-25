#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		/* 有左子树，下一节点是右子树中的最左结点 */
		if (nullptr != pNode->right)
		{
			TreeLinkNode* pRight = pNode->right;
			while (nullptr != pRight->left)
			{
				pRight = pRight->left;
			}
			return pRight;
		}
		/* 无右子树，且结点是该结点父节点的左子树，则下一结点是该结点的父结点 */
		if (nullptr != pNode->next && pNode->next->left == pNode)
		{
			return pNode->next;
		}
		/* 无右子树，且结点是该结点父结点的右子树，则我们一直沿着父结点追朔，直到找到某个结点是其父结点的左子树，
		如果存在这样的结点，那么这个结点的父结点就是我们要找的下一结点。 */
		if (nullptr != pNode->next)
		{
			TreeLinkNode* pNext = pNode->next;
			while (nullptr != pNext->next && pNext->next->right == pNext)
			{
				pNext = pNext->next;
			}
			return pNext->next;
		}
		return nullptr;
	}
};

int main(void)
{


	return 0;
}
