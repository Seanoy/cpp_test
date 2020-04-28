#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	int num = 0;
	int length;
	
	getline(cin, str);
	length = str.length();
	while (str[length - 1] != ' ' && length != 0)
	{
		num++;
		length--;
	}
	cout << num;
	return 0;
}
