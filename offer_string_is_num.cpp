#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

	int cnt1 = 0, cnt2 = 0; //cnt1是.计数器，cnt2是'+'和'-计数器'
	bool isNumeric(char* string) {
		for (int i = 0; i < strlen(string); i++)
		{
			if (string[i] == '\0') return true; //截止符号，停止检测，则返回true
			if ((string[i] < '0' || string[i] > '9') && string[i] != '.' && string[i] != '+' && string[i] != 'e' && string[i] != '-' && string[i] != 'E') return false; //情况7
			if (string[i] == '.') cnt1++;
			if (string[i] == '+' || string[i] == '-') if (string[i - 1] != 'E' && string[i - 1] != 'e') cnt2++;
			if (cnt1 == 2 || cnt2 == 2) return false; //情况6
			if (string[i] == 'e') if (string[i - 1] < '0' || string[i - 1] > '9' || string[i + 1] == '\0' || string[i + 3] == '.') return false; //情况4,情况8，情况9
			if (string[i] == '+' || string[i] == '-') if (string[i - 1] > '0' && string[i - 1] < '9') return false;
		}
		return true;
	}

};

//状态机
class Solution2 {
public:
	char arr[10] = "+-n.ne+-n";
	int turn[10][9] = {
		//+  -  n  .  n  e  +  -  n
		{ 1, 1, 1, 0, 0, 0, 0, 0, 0 },    // # start
		{ 0, 0, 1, 1, 0, 0, 0, 0, 0 },    // +
		{ 0, 0, 1, 1, 0, 0, 0, 0, 0 },    // -
		{ 0, 0, 1, 1, 0, 1, 0, 0, 0 },    // n
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0 },    // .
		{ 0, 0, 0, 0, 1, 1, 0, 0, 0 },    // n
		{ 0, 0, 0, 0, 0, 0, 1, 1, 1 },    // e
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1 },    // +
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1 },    // -
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1 }     // n
	};
	bool isNumeric(char* string) {
		int cur = 0;
		for (int j, i = 0; string[i]; i++) {
			for (j = 0; j < 9; j++) {
				if (turn[cur][j]) {
					if (('0' <= string[i] && string[i] <= '9' && arr[j] == 'n') ||
						(string[i] == 'E' && arr[j] == 'e') ||
						string[i] == arr[j]) {
						cur = j + 1;
						break;
					}
				}
			}
			if (j == 9) return false;
		}
		if (cur == 3 || cur == 4 || cur == 5 || cur == 9)
			return true;
		return false;
	}
};

int main(void)
{
	Solution s;
	cout << s.isNumeric("+12e1");

	return 0;
}
