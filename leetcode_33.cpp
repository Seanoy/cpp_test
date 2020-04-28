//https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-leetcode-solut/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		if (!n)return -1;//空容器
		if (n == 1)return target == nums[0] ? 0 : -1;//只有一个元素
		int left = 0, right = n - 1, mid;

		while (left <= right) {
			mid = (left + right) / 2;
			if (nums[mid] == target) return mid;
			if (nums[0] <= nums[mid]) {//左面是升序的
				//target在左半边
				if (nums[0] <= target && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else {//target右半边
				if (nums[mid] < target && target <= nums[n - 1])
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
		return -1;
	}
};

int main(void)
{




	return 0;
}
