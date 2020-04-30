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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		vector<ListNode*> address;

		while (pListHead != nullptr)
		{
			address.push_back((pListHead));
			pListHead = pListHead->next;
		}
		if (k > address.size())
			return nullptr;
		return address[address.size() - k];
	}
};

int main(void)
{
	Solution s;
	ListNode *head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(4);


	cout<<s.FindKthToTail(head, 2)->val;
	return 0;
}
