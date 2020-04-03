#include <iostream>
using namespace std;
int cnt = 0;
void move(char X, char Y)
{
	cnt++;
	cout << "move" << X << "to" << Y << endl;
}

void hanoi(int n, char X, char Y, char Z)
{
	if (n <= 1)
	{
		move(X, Z);
	}
	else
	{
		hanoi(n - 1, X, Z, Y);
		move(X, Z);
		hanoi(n - 1, Y, X, Z);
		
	}
}

int main()
{	
	hanoi(10, 'A', 'B', 'C');
	cout << cnt << endl;
	/*
	int p[10] = { 1,-3,4,-5,6,1,5,-10,12,-1 };

	int sum = p[0];
	int max = p[0];
	int start, end;
	for (int i = 1; i < 10; i++) {
		if (sum > 0)
		{         // �ӵڶ������ж��Ƿ�Ϊ��ֵ 
			sum = sum + p[i];   // ���Ϊ������sum�������
			if (sum > max) {       // �ж��Ƿ�Ϊ������ǽ���ֵ��max������������ĩλ�øı� 
				max = sum;
				end = i;
			}
		}
		else {
			sum = p[i];           // �Ǹ����Ļ�������i+1������ֵ��sum 
			if (sum > max) {       // �ж��Ƿ�Ϊ����ǵĻ��͸�ֵ��sum�������������ʼ����ֹλ�øı� 
				max = sum;
				start = i;
				end = i;
			}
		}
	}
	*/
	return 0;
}
