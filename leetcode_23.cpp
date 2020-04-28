#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//朴素法/顺序合并 时间复杂度O(k^2*n) 空间复杂度O(1) 36ms 10.9MB
class Solution1 {
public:
	void insert_num(ListNode** lists, int value){
		ListNode* tempCell;
		tempCell = new ListNode(value);
		if (tempCell == NULL)
			exit(OVERFLOW);
		(*lists)->next = tempCell;
		*lists = (*lists)->next;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<int>temp;
		for (unsigned int i = 0; i < lists.size(); i++){
			while (lists[i] != NULL)
			{
				temp.push_back(lists[i]->val);
				lists[i] = lists[i]->next;
			}
		}
		sort(temp.begin(), temp.end());
		ListNode* result = new ListNode(0);
		ListNode* head = result;
		for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++){
			//insert_num(&result, *it);
			result->next = new ListNode(*it);
			result = result->next;
		}

		return head->next;
	}
};


//分治策略 时间复杂度O(knlogk) 空间复杂度O(logk) 28ms 9.8MB
class Solution2 {
public:
	ListNode* mergeTwoLists(ListNode *a, ListNode*b) {
		if (a == NULL || b == NULL) return (a != NULL ? a : b);
		ListNode head(0), *tail = &head, *aPtr = a, *bPtr = b;
		while (aPtr != NULL && bPtr != NULL) {
			if (aPtr->val < bPtr->val) {
				tail->next = aPtr;
				aPtr = aPtr->next;
			}
			else {
				tail->next = bPtr;
				bPtr = bPtr->next;
			}
			tail = tail->next;
		}
		tail->next = (aPtr ? aPtr : bPtr);
		return head.next;
	}

	//递归
	ListNode*merge(vector<ListNode*>&lists, int left, int right) {
		if (left == right)return lists[left];
		if (left > right)return nullptr;
		int mid = (left + right) >> 1;//长度除以2
		return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return merge(lists, 0, lists.size() - 1);
	}
};


//优先队列 时间复杂度O(knlogk) 空间复杂度O(k) 48ms 10.8MB
class Solution3 {
public:
	struct Status {
		int val;
		ListNode *ptr;
		bool operator < (const Status &rhs)const {
			return val > rhs.val;
		}
	};

	priority_queue <Status> q;
	//维护每个链表第一个元素
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		for (auto node : lists) {
			if (node) q.push({ node->val,node });
		}
		ListNode head(0), *tail = &head;
		while (!q.empty()) {
			auto f = q.top(); q.pop();
			tail->next = f.ptr;
			tail = tail->next;
			if (f.ptr->next)q.push({ f.ptr->next->val, f.ptr->next });
		}
		return head.next;
	}
};

int main(void)
{
	Solution3 s;
	ListNode *a = new ListNode(1);
	a->next = new ListNode(4);
	a->next->next = new ListNode(5);

	ListNode *b = new ListNode(1);
	b->next = new ListNode(3);
	b->next->next = new ListNode(4);

	vector<ListNode*> list;
	list.push_back(a);
	list.push_back(b);

	ListNode* head = s.mergeKLists(list);
	while (head != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}
