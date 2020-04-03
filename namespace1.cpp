#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>

using namespace std;

namespace first_space {
	void foo() {
		cout << "within first place" << endl;
	}
}
namespace second_space {
	void foo() {
		cout << "within second place" << endl;
	}
}

template <typename T>
inline T const& Max(T const& a, T const& b)
{
	return a < b ? b : a;
}

template <class T>
class Stack {
private:
	vector<T> elems;//elements
public:
	void push(T const& elem);//��ջ
	void pop();//��ջ
	T top() const;//����ջ��Ԫ��
	bool empty() const {
		return elems.empty();
	}
};

template <class T>
void Stack<T>::push(T const &elem)
{
	//׷�Ӵ���Ԫ�صĸ���
	elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
	if (elems.empty()) {
		throw out_of_range("Stack<>::pop: empty stack");
	}
	//ɾ�����һ��Ԫ��
	elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
	if (elems.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	//����ջ��Ԫ��
	return elems.back();
}


#define MKSTR(x) #x
#define CONCAT(x,y) x ## y

int main()
{
/*	first_space::foo();
	second_space::foo();

	int i = 39;
	int j = 20;
	cout << "Max(i, j): " << Max(i, j) << endl;

	double f1 = 13.5;
	double f2 = 20.7;
	cout << "Max(f1, f2): " << Max(f1, f2) << endl;

	string s1 = "Hello";
	string s2 = "World";
	cout << "Max(s1, s2): " << Max(s1, s2) << endl;
	*/

/*
	try {
		Stack<int> intStack;
		Stack<string> stringStack;

		intStack.push(6);
		cout << intStack.top() << endl;
		intStack.pop();

		stringStack.push("Hello");
		cout << stringStack.top() << endl;
		stringStack.pop();
		stringStack.pop();
	}
	catch (exception const &ex) {
		cerr << "Exception: " << ex.what() << endl;
		system("pause");
		return -1;
	}
	*/
	string helloworld = "hello, world";
	cout << MKSTR(hello) << endl;
	cout << CONCAT(hello, world) << endl;

	cout << "current line:" << __LINE__ << endl;
	cout << "current date:" << __DATE__ << endl;
	cout << "current file:" << __FILE__ << endl;
	cout << "current time:" << __TIME__ << endl;

	system("pause");
	return 0;
}
