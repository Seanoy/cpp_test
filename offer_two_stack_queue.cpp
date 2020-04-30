#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int node;
		if (stack1.empty() && stack2.empty())//两个栈都为空
		{
			cerr << "the stack is empty" << endl;
			return -1;
		}
		if (stack2.empty())//栈2为空
		{
			//若栈1不为空，则持续将栈1的元素push到栈2
			while (stack1.size() > 0) {
				stack2.push(stack1.top()); 
				stack1.pop();
			}
		}
		node = stack2.top();
		stack2.pop();
		return node;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main(void)
{

	return 0;
}
