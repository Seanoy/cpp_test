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
		/* ������������һ�ڵ����������е������� */
		if (nullptr != pNode->right)
		{
			TreeLinkNode* pRight = pNode->right;
			while (nullptr != pRight->left)
			{
				pRight = pRight->left;
			}
			return pRight;
		}
		/* �����������ҽ���Ǹý�㸸�ڵ��������������һ����Ǹý��ĸ���� */
		if (nullptr != pNode->next && pNode->next->left == pNode)
		{
			return pNode->next;
		}
		/* �����������ҽ���Ǹý�㸸������������������һֱ���Ÿ����׷˷��ֱ���ҵ�ĳ��������丸������������
		������������Ľ�㣬��ô������ĸ�����������Ҫ�ҵ���һ��㡣 */
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
