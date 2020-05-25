#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		bool *nums = new bool [length] {0};
		for (int i = 0; i < length; i++) {
			if (nums[numbers[i]] == true) {
				*duplication = numbers[i];
				return true;
			}
			nums[numbers[i]] = true;
		}
		return false;
	}

	bool duplicate1(int numbers[], int length, int* duplication) {
		for (int i = 0; i != length; ++i) {
			int index = numbers[i] % length;
			if (numbers[index] >= length) {
				*duplication = index;
				return 1;
			}
			numbers[index] += length;
		}
		return 0;
	}
};

int main(void)
{
	Solution s;
	int i;
	int num[] = { 2,3,1,0,2,5,3 };
	cout << boolalpha << s.duplicate1(num, 7, &i) << endl;
	cout << i << endl;
	return 0;
}
