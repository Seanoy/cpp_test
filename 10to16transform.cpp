#include <iostream>
#include <string>

using namespace std;
long int pow(int x, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;

	if (n % 2 == 0)
		return pow(x*x, n / 2);
	else
		return pow(x*x, n / 2)*x;
}

int main(void)
{
	//string str;
	//while (cin >> str)
	//{
	//	int bit = 0;
	//	int result = 0;
	//	for (int i = str.length() - 1; i > 1; i--)
	//	{
	//		if (str[i] >= '0'&&str[i] <= '9')
	//		{
	//			result += (str[i] - '0') * pow(16, bit++);
	//		}
	//		else if (str[i] >= 'A'&&str[i] <= 'F')
	//		{
	//			result += (str[i] - 'A' + 10) * pow(16, bit++);
	//		}
	//		else if (str[i] >= 'a'&&str[i] <= 'f')
	//		{
	//			result += (str[i] - 'a' + 10) * pow(16, bit++);
	//		}
	//	}
	//	cout << result << endl;
	//}

	//Лђеп
	//int num;
	//while (cin >> hex >> num)
	//	cout << num << endl;

	return 0;
}
