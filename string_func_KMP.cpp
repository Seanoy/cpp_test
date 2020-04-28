#include <iostream>
using namespace std;

char *strcpy(char* d, char* s)
{
	int i = 0;
	while (s[i] != 0)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return d;
}

int strcmp(const char* s1, const char* s2)
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return 1;
		else if (s1[i] < s2[i])
			return -1;
		i++;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return -1;
	else if (s1[i] != '\0' && s2[i] == '\0')
		return 1;
	return 0;
}

int strcmp1(const char* s1, const char* s2)
{
	int i;
	for (i = 0; s1[i] == s2[i]; ++i)
	{
		if (s1[i] == '\0'&&s2[i] == '\0')
			return 0;
	}
	return (s1[i] - s2[i]) / abs(s1[i] - s2[i]);
}

int *findNext(string P)
{
	int j, k;
	int m = P.length();
	_ASSERT(m > 0);
	//int *next = new int[m];//申请内存
	int next[10] = { 0 };
	_ASSERT(next != NULL);
	next[0] = -1;
	j = 0;k = -1;
	while (j < m - 1)
	{
		while (k >= 0 && P[k] != P[j])//若不等，采用KMP找首尾子串
			k = next[k];//k递归向前找
		j++;
		k++;
		//if (P[k] == P[j])//这一步是为了优化算法，消除冗余步骤
		//	next[j] = next[k];//找更小的k值
		//else
			next[j] = k;
	}
	return next;
}

int KMPStrMatching(string T, string P, int start)
{
	int j = 0;
	int i = start;
	int pLen = P.length();
	int tLen = T.length();
	int *next = findNext(P);
	if (tLen - pLen < start)
		return (-1);
	while (j < pLen && i < tLen)
	{
		if (j == -1 || T[i] == P[j])//字符匹配，移动到下一个待比较的字符位置
		{
			i++; j++;
		}
		else
			j = next[j];//不匹配，将匹配串相对于主串的位置进行移动
	}
	if (j >= pLen)
	{
		free(next);//释放内存
		return i - pLen;
	}
	else
	{
		free(next);//释放内存
		return -1;
	}
}

int main(int argc, char* argv[])
{
	cout << KMPStrMatching(string("ababababaabababbab"), string("abababb"), 0) << endl;
	return 0;
}
