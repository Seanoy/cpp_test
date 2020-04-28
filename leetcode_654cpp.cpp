#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。

通过给定的数组构建最大二叉树，并且输出这个树的根节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//recursion 104 ms	41.8 MB 可以优化成非递归模式
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

//单调栈
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


作者：3kwater
链接：https ://leetcode-cn.com/problems/maximum-binary-tree/solution/java-dan-diao-zhan-on-by-3kwater/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int main(void)
{


	return 0;
}
