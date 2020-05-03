#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode*head = new ListNode(0);

		while (pHead != nullptr)
		{
			ListNode*temp = new ListNode(pHead->val);
			temp->next = head->next;
			head->next = temp;
			pHead = pHead->next;
		}
		return head->next;
	}
};

int main(void)
{
	ListNode*head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(4);
	Solution s;
	ListNode *ret = s.ReverseList(head);
	while (ret != nullptr)
	{
		cout << ret->val << endl;
		ret = ret->next;
	}
	return 0;
}
