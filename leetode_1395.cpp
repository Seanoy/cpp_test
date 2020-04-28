#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
	int numTeams(vector<int>& rating) {
		int i, j, k;
		int count = 0;
		if (rating.size() < 3)
			return 0;
		for (int i = 0; i < rating.size(); i++) {
			for (int j = i + 1; j < rating.size(); j++) {
				for (int k = j + 1; k < rating.size(); k++) {
					if (((rating[i] > rating[j]) && (rating[j] > rating[k])) ||
						((rating[i] < rating[j]) && (rating[j] < rating[k])))
						count++;
				}
			}
		}
		return count;
	}
};

class Solution2 {
public:
	int numTeams(vector<int>& rating) {
		int n = rating.size();
		int ans = 0;
		// 枚举三元组中的 j
		for (int j = 1; j < n - 1; ++j) {
			int iless = 0, imore = 0;
			int kless = 0, kmore = 0;
			for (int i = 0; i < j; ++i) {
				if (rating[i] < rating[j]) {
					++iless;
				}
				// 注意这里不能直接写成 else
				// 因为可能有评分相同的情况
				else if (rating[i] > rating[j]) {
					++imore;
				}
			}
			for (int k = j + 1; k < n; ++k) {
				if (rating[k] < rating[j]) {
					++kless;
				}
				else if (rating[k] > rating[j]) {
					++kmore;
				}
			}
			ans += iless * kmore + imore * kless;
		}
		return ans;
	}
};

int main(void)
{
	vector<int>test = { 2,5,3,4,1 };
	Solution1 s;
	cout << s.numTeams(test) << endl;
	return 0;
}
