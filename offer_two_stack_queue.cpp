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
		if (stack1.empty() && stack2.empty())//����ջ��Ϊ��
		{
			cerr << "the stack is empty" << endl;
			return -1;
		}
		if (stack2.empty())//ջ2Ϊ��
		{
			//��ջ1��Ϊ�գ��������ջ1��Ԫ��push��ջ2
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
