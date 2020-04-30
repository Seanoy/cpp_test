#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string in_str;
	int diff = 0;
	int num_count[128] = {0};
	getline(cin, in_str);

	for (auto i : in_str)
	{
		num_count[i]++;
	}
	for (int i = 0; i < sizeof(num_count) / sizeof(num_count[0]); i++)
		if(num_count[i]!=0)
			diff++;
	cout << diff << endl;
	return 0;
}
