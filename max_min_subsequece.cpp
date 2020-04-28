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

//�����������֮��
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

//����С������֮��
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

//����С��������֮��
//��β������
void CocktailSort(int A[], int N) {
	int left = 0;										//��ʼ����߽�
	int right = N - 1;									//��ʼ���ұ߽�
	while (left < right)
	{
		for (int i = left; i < right; i++)				//ǰ�벿�֣������Ԫ�ط��ں���
		{
			if (A[i] > A[i + 1])
			{
				swap(A[i + 1], A[i]);
			}
		}
		right--;
		for (int i = right; i > left; i--)				//��벿��,����СԪ�طŵ�ǰ��
		{
			if (A[i - 1] > A[i])
			{
				swap(A[i - 1], A[i]);
			}
		}
		left++;
	}
}

//����˼·����������ͣ�A[i] += A[i+1]����Ȼ�����򣬴Ӻ���ǰ�������̬��ȡ��Сֵ
//�ο����ӣ�http://blog.sina.com.cn/s/blog_6abc30e501012yhr.html
int minPositiveSubsequence(const int A[], const int N)
{
	int *temp = new int[N + 1];
	int min = (unsigned int)(-1)>>1;//ȡint�������ֵ
	int sum = 0;
	int first_zero = 1;
	if (N == 0)
		return 0;

	temp[0] = 0;

	//��ͷ�����ۼ� ע���һ����0
	for (int i = 0; i < N; i++)
		temp[i+1] = temp[i] + A[i];
	
	//����
	CocktailSort(temp, N + 1);

	//Ѱ����������ȳ�����ĵط�
	for (int i = 0; i < N + 1; i++)
	{
		if (temp[i]!=0)
			first_zero++;
		else
			break;
	}

	if (temp[N] == 0 && first_zero == N + 1)//���ȫ��Ԫ�ض�����Ļ�����
		return 0;

	//�Ӻ���ǰ��
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


//��������г˻� ��̬�滮DP�����������ȡ���ֵ����Сֵ��
//���������������ǰ���ֵ��ɵ�ǰ��Сֵ����ǰ��Сֵ�䵱ǰ���ֵ��
//Ȼ����бȽϲ�������ֵ����ȡ���ֵ��
int maxSubsequenceMultiply(const int A[], int N)
{
	int _max = 1 << 31;//int������Сֵ
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
