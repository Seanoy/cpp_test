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
	//int *next = new int[m];//�����ڴ�
	int next[10] = { 0 };
	_ASSERT(next != NULL);
	next[0] = -1;
	j = 0;k = -1;
	while (j < m - 1)
	{
		while (k >= 0 && P[k] != P[j])//�����ȣ�����KMP����β�Ӵ�
			k = next[k];//k�ݹ���ǰ��
		j++;
		k++;
		//if (P[k] == P[j])//��һ����Ϊ���Ż��㷨���������ಽ��
		//	next[j] = next[k];//�Ҹ�С��kֵ
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
		if (j == -1 || T[i] == P[j])//�ַ�ƥ�䣬�ƶ�����һ�����Ƚϵ��ַ�λ��
		{
			i++; j++;
		}
		else
			j = next[j];//��ƥ�䣬��ƥ�䴮�����������λ�ý����ƶ�
	}
	if (j >= pLen)
	{
		free(next);//�ͷ��ڴ�
		return i - pLen;
	}
	else
	{
		free(next);//�ͷ��ڴ�
		return -1;
	}
}

int main(int argc, char* argv[])
{
	cout << KMPStrMatching(string("ababababaabababbab"), string("abababb"), 0) << endl;
	return 0;
}
