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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* head = new ListNode(0);
		ListNode* head_ret = head;
		//比较大小放数据
		while (pHead1 != nullptr && pHead2 != nullptr)
		{
			if (pHead1->val > pHead2->val)
			{
				head->next = new ListNode(pHead2->val);
				pHead2 = pHead2->next;
			}
			else
			{
				head->next = new ListNode(pHead1->val);
				pHead1 = pHead1->next;
			}
			head = head->next;
		}
		//继续放剩下的元素
		while (pHead1 != nullptr)
		{
			head->next = new ListNode(pHead1->val);
			pHead1 = pHead1->next;
			head = head->next;
		}
		while (pHead2 != nullptr)
		{
			head->next = new ListNode(pHead2->val);
			pHead2 = pHead2->next;
			head = head->next;
		}
		return head_ret->next;
	}
};

int main(void)
{
	ListNode a(1);
	a.next = new ListNode(8);
	a.next->next = new ListNode(9);
	ListNode b(2);
	b.next = new ListNode(5);
	b.next->next = new ListNode(6);
	b.next->next->next = new ListNode(10);
	b.next->next->next->next = new ListNode(13);

	Solution s;
	ListNode *p = s.Merge(&a, &b);
	while (p != nullptr)
	{
		cout << p->val;
		p = p->next;
	}
	return 0;
}
