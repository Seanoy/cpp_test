#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
string num_reverse(unsigned int num);
static int atoi1(char* num_str);

int main(int argc, char* argv[])
{
	//int num;
	//cin >> num;
	////std::cout << num_reverse(num);
	//while (num)
	//{
	//	printf("%d", num % 10);
	//	num /= 10;
	//}
	cout << atoi1("123456") << endl;
	return 0;
}

string num_reverse(unsigned int num)
{
	std::string num_str = std::to_string(num);
	std::string reverse_str;
	int length = num_str.length();
	for (int i = length - 1; i >= 0; i--)
		reverse_str.append(1, num_str[i]);
	return reverse_str;
}

static int atoi1(char* num_str)
{
	int num = 0;
	int length = 0;
	while (num_str[length] != '\0')
		length++;
	for (int i = 0; i < length; i++)
	{
		num *= 10;
		num += num_str[i]-'0';
	}
	return num;
}