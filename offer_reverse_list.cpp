#include<iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

//Recursion
class Solution1 {
public:
	vector<int> *ret = new vector<int>(0);
	vector<int> printListFromTailToHead(ListNode* head) {
		if (head != nullptr) {
			printListFromTailToHead(head->next);
			ret->push_back(head->val);
		}
		return *ret;
	}
};

//Non-Recursion
class Solution2 {
public:
	vector<int> *ret = new vector<int>(0);
	vector<int> printListFromTailToHead(ListNode* head) {
		while (head != nullptr) {
			ret->insert(ret->begin(),head->val);
			head = head->next;
		}
		return *ret;
	}
};

int main(void)
{
	vector<int> vec;
	ListNode*head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	Solution2 s;
	vec = s.printListFromTailToHead(head);
	for (auto i : vec)
		cout << i << endl;
	return 0;
}
