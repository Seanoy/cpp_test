#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int temp;
		vector<int> result;
		if (k > input.size())
			return result;
		for (int i = 0; i < input.size(); i++) {
			for (int j = i + 1; j < input.size(); j++) {
				if (input[i] > input[j]) {
					temp = input[i];
					input[i] = input[j];
					input[j] = temp;
				}
			}
		}

		for (int i = 0; i < k; i++) {
			result.push_back(input[i]);
		}
		return result;
	}
};

int main(void)
{


	return 0;
}
