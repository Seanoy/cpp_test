#include <string>
#include <iostream>
#include <algorithm>

int count1(std::string str, char ch)//612 3ms
{
	int char_num = 0;
	transform(str.begin(), str.end(), str.begin(), tolower);
	ch = tolower(ch);
	for (int i = 0; i < str.length(); i++)
		if (str[i] == ch)
			char_num++;
	return char_num;
}


int count2(std::string str, char ch)//504k 3ms
{
	int char_num = 0;
	ch = tolower(ch);
	for (int i = 0; i < str.length(); i++)
	{
		if (tolower(str[i]) == ch)
			char_num++;
	}

	return char_num;
}

int main(void)
{
	std::string in_str;
	char in_char;
	std::cin >> in_str;
	std::cin >> in_char;

//	std::cout << count1(in_str, in_char);

	return 0;
}
