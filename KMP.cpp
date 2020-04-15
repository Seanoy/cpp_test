#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//�ַ�����0��λ�ò��洢Ԫ��
int KMP(string haystack, string needle, int *next)
{
	int i = 1, j = 1;
	while (i <= haystack.length() && j <= needle.length())
	{
		if (j == 0 || haystack[i] == needle[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j > needle.length())
		return i - needle.length();
	else
		return 0;
}

void getNextVal(string needle, int nextval[], int next[])
{
	int j = 1, t = 0;
	next[1] = 0;
	nextval[1] = 0;
	while (j < needle.length())
	{
		if (t == 0 || needle[j] == needle[t])
		{
			next[++j] = ++t;
			if (needle[j] != needle[t])
				nextval[j] = next[j];
			else
				nextval[j] = nextval[next[t]];
		}
		else
			t = next[t];
	}
}


class Solution {
public:
	int KMP(string haystack, string needle) {
		if (needle.empty())return 0;
		int i = 0, m = haystack.size();//�ı�ָ��i����ָʾ�ı���
		int j = 0, n = needle.size();//ģʽָ��j����ָʾģʽ��
		vector<int> nextVal = get_next(needle);
		while (i < m&&j < n) {
			if (j == -1 || needle[j] == haystack[i])i++, j++;
			else j = nextVal[j];
		}
		return j == n ? i - j : -1;
	}

	//��ͨ��get_next
	vector<int> get_next(const string& pat) {
		int n = pat.size();
		vector<int> next(n + 1, -1);//���������СΪn+1��Ҫ����pat[n-1]
		int k = -1, j = 0;
		while (j < n) {
			if (k == -1 || pat[k] == pat[j]) next[++j] = ++k;//k��jָ�붼����һλ
			else k = next[k];//��׺ָ��k���˵�next[k]���±꣩��λ��
		}
		return next;
	}

	//�Ż���get_nextVal
	vector<int> get_nextVal(const string& pat) {
		int n = pat.size();
		vector<int> nextVal(n, -1);//����next�����СΪn���Ѿ�����pat[n-1]��
		int k = -1, j = 0;
		while (j < n - 1) {
			if (k == -1 || pat[k] == pat[j]) {
				if (pat[++j] != pat[++k]) nextVal[j] = k;
				else nextVal[j] = nextVal[k];
			}
			else k = nextVal[k];
		}
		return nextVal;
	}
};


int main(int argc, char* argv[])
{
	Solution solution;
	int n = solution.KMP("AAABABABABBABA", "ABABABB");

	return 0;
}
