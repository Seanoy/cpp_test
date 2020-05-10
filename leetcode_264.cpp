#include <iostream>
#include <queue>
#include <functional>
#include <unordered_set>
#include <fstream>
using namespace std;
#define MAX_VALUE 1700

//https://leetcode-cn.com/problems/ugly-number-ii/solution/chou-shu-ii-by-leetcode/

class Solution1 {
private:
	long long num[MAX_VALUE];
public:

	Solution1()
	{
		unordered_set<long long> seen;
		priority_queue<long long, vector<long long>, greater<long long>>heap;
		seen.insert(1L);
		heap.push(1L);

		long long curUgly, newUgly;
		int primes[] = { 2,3,5 };
		for (int i = 0; i < MAX_VALUE; i++)
		{
			curUgly = heap.top(); heap.pop();
			num[i] = curUgly;
			for (int j : primes)
			{
				newUgly = curUgly*j;
				if (!seen.count(newUgly)) {
					seen.insert(newUgly);
					heap.push(newUgly);
				}
			}
		}
		//开挂方法，直接放数组
		ofstream fs;
		fs.open("ugly_num_array.txt");
		fs << "#define MAX_VALUE 1700\n";
		fs << "long long ugly[MAX_VALUE] = {";
		for (int i = 0; i < MAX_VALUE; i++)
		{
			fs << num[i] << ", ";
		}
		fs << '}';
		fs.close();
	}

	long long nthUglyNumber(int n) {
		return num[n - 1];
	}
};

//三指针方法 动态规划
class Solution2 {
private:
	long long num[MAX_VALUE];
public:

	Solution2()
	{
		num[0] = 1;
		long long ugly, i2 = 0, i3 = 0, i5 = 0;

		for (int i = 1; i < MAX_VALUE; i++)
		{
			ugly = min(min(num[i2] * 2, num[i3] * 3), num[i5] * 5);
			num[i] = ugly;

			if (ugly == num[i2] * 2)++i2;
			if (ugly == num[i3] * 3)++i3;
			if (ugly == num[i5] * 5)++i5;
		}
	}
	long long nthUglyNumber(int n) {
		return num[n - 1];
	}
};


int main(void)
{
	Solution2 s;
	cout << s.nthUglyNumber(10) << endl;
	return 0;
}
