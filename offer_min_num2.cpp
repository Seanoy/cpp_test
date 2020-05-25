#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		if (numbers.empty() == true)
		{
			return "";
		}
		for (int i = 0; i < numbers.size(); i++)
		{
			for (int j = i + 1; j < numbers.size(); j++)
			{
				char num1[80];
				int sum1;
				sprintf_s(num1, "%d%d", numbers[i], numbers[j]);
				sscanf_s(num1, "%x", &sum1);
				char num2[80];
				int sum2;
				sprintf_s(num2, "%d%d", numbers[j], numbers[i]);
				sscanf_s(num2, "%x", &sum2);

				if (sum1 > sum2) {
					int temp = numbers[j];
					numbers[j] = numbers[i];
					numbers[i] = temp;
				}
			}
		}
		string str("");
		for (int i = 0; i < numbers.size(); i++)
		{
			str += to_string(numbers[i]);
		}
		return str;
	}
};

int main(void)
{
	Solution s;
	vector<int> a{ 3,32,321 };
	cout<<s.PrintMinNumber(a);
	return 0;
}
