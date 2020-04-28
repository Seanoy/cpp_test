#include <iostream>
#include <algorithm>
using namespace std;

void swap(int &num1, int &num2)
{
	int tmp;
	tmp = num1;
	num1 = num2;
	num2 = tmp;
}

//求最大子序列之和
int maxSubsequence(const int A[], int N)
{
	int thisSum, maxSum, j;
	thisSum = maxSum = 0;
	for (j = 0; j < N; j++)
	{
		thisSum += A[j];
		if (thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum < 0)
			thisSum = 0;
	}
	return maxSum;
}

//求最小子序列之和
int minSubsequence(const int A[], int N)
{
	int thisSum, minSum, j;
	thisSum = minSum = 0;
	for (j = 0; j < N; j++)
	{
		thisSum += A[j];
		if (thisSum < minSum)
			minSum = thisSum;
		else if (thisSum > 0)
			thisSum = 0;
	}
	return minSum;
}

//求最小正子序列之和
//鸡尾酒排序
void CocktailSort(int A[], int N) {
	int left = 0;										//初始化左边界
	int right = N - 1;									//初始化右边界
	while (left < right)
	{
		for (int i = left; i < right; i++)				//前半部分，将最大元素放在后面
		{
			if (A[i] > A[i + 1])
			{
				swap(A[i + 1], A[i]);
			}
		}
		right--;
		for (int i = right; i > left; i--)				//后半部分,将最小元素放到前面
		{
			if (A[i - 1] > A[i])
			{
				swap(A[i - 1], A[i]);
			}
		}
		left++;
	}
}

//基本思路：先逐项求和（A[i] += A[i+1]），然后排序，从后往前相减并动态获取最小值
//参考链接：http://blog.sina.com.cn/s/blog_6abc30e501012yhr.html
int minPositiveSubsequence(const int A[], const int N)
{
	int *temp = new int[N + 1];
	int min = (unsigned int)(-1)>>1;//取int类型最大值
	int sum = 0;
	int first_zero = 1;
	if (N == 0)
		return 0;

	temp[0] = 0;

	//从头逐项累加 注意第一项是0
	for (int i = 0; i < N; i++)
		temp[i+1] = temp[i] + A[i];
	
	//排序
	CocktailSort(temp, N + 1);

	//寻找排序后最先出现零的地方
	for (int i = 0; i < N + 1; i++)
	{
		if (temp[i]!=0)
			first_zero++;
		else
			break;
	}

	if (temp[N] == 0 && first_zero == N + 1)//如果全部元素都是零的话返回
		return 0;

	//从后往前减
	for (int i = N - 1; i > first_zero; i--)
	{
		sum = temp[i + 1] - temp[i];
		if (sum > 0 && sum < min)
		{
			min = sum;
		}
	}
	delete [] temp;
	return min;
}


//最大子序列乘积 动态规划DP，遍历数组获取最大值和最小值，
//如果遇到负数，则当前最大值变成当前最小值，当前最小值变当前最大值，
//然后进行比较并更新数值，获取最大值。
int maxSubsequenceMultiply(const int A[], int N)
{
	int _max = 1 << 31;//int类型最小值
	int imax = 1;
	int imin = 1;
	for (int i = 0; i < N; i++)
	{
		if (A[i] < 0)
		{
			swap(imax, imin);
		}
		imax = max(imax*A[i], A[i]);
		imin = min(imin*A[i], A[i]);

		_max = max(_max, imax);
	}
	return _max;
}

int main()
{
	int a[] = { 2,-1,4,5,-7,3,7,-3 };
	int max = maxSubsequence(a, 8);
	int min = minSubsequence(a, 8);
	int minPositive = minPositiveSubsequence(a, 8);
	int max_mul = maxSubsequenceMultiply(a, 8);
	return 0;
}
