#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
����һ�������ظ�Ԫ�ص��������顣һ���Դ����鹹�������������������£�

�������ĸ��������е����Ԫ�ء�
��������ͨ�����������ֵ��߲��ֹ����������������
��������ͨ�����������ֵ�ұ߲��ֹ����������������

ͨ�����������鹹�������������������������ĸ��ڵ㡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//recursion 104 ms	41.8 MB �����Ż��ɷǵݹ�ģʽ
class Solution1 {
public:
	vector<int> nums;
	TreeNode *construct(vector<int> *nums, int l, int r) {
		if (l == r)
			return NULL;
		int max_i = l;
		for (int i = l + 1; i < r; i++) {
			if (nums->at(max_i) < nums->at(i))
				max_i = i;
		}
		TreeNode *root = new TreeNode(nums->at(max_i));
		root->left = construct(nums, l, max_i);
		root->right = construct(nums, max_i + 1, r);
		return root;
	}

	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return construct(&nums, 0, nums.size());
	}
};

//����ջ
//https://leetcode-cn.com/problems/maximum-binary-tree/solution/java-dan-diao-zhan-on-by-3kwater/
class Solution2 {
public:

	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		stack<TreeNode> *stk = new stack<TreeNode>();
		for (TreeNode i : nums)
		{
			
		}
	}
};


/*java
class Solution {
	public TreeNode constructMaximumBinaryTree(int[] nums) {
		Stack<TreeNode> stack = new Stack<>();
		for (int n : nums) {
			TreeNode node = new TreeNode(n);
			TreeNode pre = null;
			while (!stack.isEmpty() && stack.peek().val < n) {
				stack.peek().right = pre;
				pre = stack.pop();
			}
			node.left = pre;
			stack.push(node);
		}
		TreeNode pre = null;
		while (!stack.isEmpty()) {
			stack.peek().right = pre;
			pre = stack.pop();
		}
		return pre;
	}
}


���ߣ�3kwater
���ӣ�https ://leetcode-cn.com/problems/maximum-binary-tree/solution/java-dan-diao-zhan-on-by-3kwater/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

int main(void)
{


	return 0;
}
