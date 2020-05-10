#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
private:
	int _min, _top;
	stack<int> _stack;
public:
	void push(int value) {
		if (_stack.empty())
			_min = value;

		_stack.push(value - _min);
		if (value < _min)
			_min = value;

		_top = value;
	}
	void pop() {
		if (!_stack.empty())
		{
			if (_stack.top() < 0)
				_min -= _stack.top();
			_stack.pop();

			if (!_stack.empty())
			{
				_top = _min + (_stack.top() > 0 ? _stack.top() : 0);
			}
		}
	}
	int top() {
		if (!_stack.empty())
			return _top;
		else
		{
			exit(UNDERFLOW);
			return 0;
		}
	}
	int min() {
		if (!_stack.empty())
			return _min;
		else
		{
			exit(UNDERFLOW);
			return 0;
		}
	}
};

int main(void)
{
	Solution s;

	s.push(2);
	cout << s.min() << endl;
	s.push(1);
	cout << s.min() << endl;

	s.pop();
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;

	return 0;
}
