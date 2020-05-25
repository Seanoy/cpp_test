#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
���ӣ�https://www.nowcoder.com/questionTerminal/bd7f978302044eee894445e244c7eee6?answerType=1&f=discussion
��Դ��ţ����

˼·�Ƿֱ�����λ��ʮλ����λ........�ϳ��� 1 �ĸ�����
��  n = 216Ϊ����
��λ�ϣ� 1 ��11��21��31��.....211����λ�Ϲ����֣�216 / 10�� + 1�� 1 ����Ϊ����ȡ����210~216���λ�ϵ�1ȡ�������������Ǽ�8��λ�������˵Ϊʲô����9��n = 211��ô�죬��������ȡ���ĸ�λ��Ϊ1�ĵ������ǣ������¿���
ʮλ�ϣ�10~19��110~119��210~216.   ʮλ�Ͽɿ��� ��216 / 10�� = 21 ��λ�ϵ�1�ĸ���Ȼ���10�������ٴΰ����ȡ����ʮλ��Ϊ1�ĵ����ó�������210~216Ҫ�������� ������Ϊ��216 % 10�� + 1.�����8�ͱ������жϵĹ��̡�
�����Դ����ơ�
ʱ�临�Ӷ� O(logN)
*/
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		int temp = 0;

		for (int m = 1; m <= n; m *= 10)
		{
			int a = n / m;//��
			int b = n % m;//��
			count += (a + 8) / 10 * m + (a % 10 == 1 ? b + 1 : 0);
		}
		return count;
	}
};

int main(void)
{
	Solution s;
	cout<<s.NumberOf1Between1AndN_Solution(21);

	return 0;
}
