#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int in, result = 0;
	cin >> in;
	int num[10] = {0};

	vector<int> num_vec;
	while (in != 0)
	{
		num_vec.push_back(in % 10);
		in /= 10;
	}

	for (auto i : num_vec)
	{
		if (num[i] == 0)
		{
			result *= 10;
			result += i;
			num[i]++;
		}
	}
	cout << result << endl;
	return 0;
}
