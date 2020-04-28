#include <iostream>
#include <string>
using namespace std;

void process_str(string str)
{
	int length = str.length();
	int addzero;
	int start = 0;
	while (start!=length)
	{
		if ((length - start)<8)
		{
			addzero = 8-(length - start);
			cout << str.substr(start, length-start);
			for(int i =0;i<addzero;i++)
				cout << 0;
			cout << endl;
			return;
		}
		else
		{
			cout << str.substr(start, 8) << endl;;
			start += 8;
		}
	}
}

int main(void)
{
	string str;
	for (int i = 0; i<2; i++)
	{
		getline(cin, str);
		process_str(str);
	}
	return 0;
}
