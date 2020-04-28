//https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-leetcode-solut/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		if (!n)return -1;//������
		if (n == 1)return target == nums[0] ? 0 : -1;//ֻ��һ��Ԫ��
		int left = 0, right = n - 1, mid;

		while (left <= right) {
			mid = (left + right) / 2;
			if (nums[mid] == target) return mid;
			if (nums[0] <= nums[mid]) {//�����������
				//target������
				if (nums[0] <= target && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else {//target�Ұ��
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
