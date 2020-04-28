#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//������˹�������,ʹ��λ������ʾ
//״̬Ǩ�ƣ���0000��1111
//Ŀ������ʼ��Ϊ0����Ŀ�갶Ϊ1

//ȷ��ÿ����ɫλ�õĺ���
//1xxx
bool farmer(int status)
{
	return ((status & 0x08) != 0);
}
//x1xx
bool wolf(int status)
{
	return ((status & 0x04) != 0);
}
//xx1x
bool cabbage(int status)
{
	return ((status & 0x02) != 0);
}
//xxx1
bool goat(int status)
{
	return ((status & 0x01) != 0);
}

//��ȫ״̬�ж�
bool safe(int status)
{
	//��Ͳ�һ�����û��ũ�������
	if ((goat(status) == cabbage(status)) &&
		(goat(status) != farmer(status)))
		return false;

	//�����һ�����û��ũ�������
	else if ((goat(status) == wolf(status)) &&
		(goat(status) != farmer(status)))
		return false;

	else
		return true;//����״̬��ȫ
}

//0000->1111�ɺϷ����й���
//ʹ�ö���moveTo��ʾ���԰�ȫ������м�״̬
//����һ�����ݽṹ���ڼ�¼�����ʹ��ĸ���״̬route[i]
#define END 0X0F //1111B
void solve(void) 
{
	int movers, i;
	int status, newstatus;

	vector<int> route(END + 1, -1);//�������
	queue<int> moveTo;

	moveTo.push(0x00);
	route[0] = 0;

	while (!moveTo.empty() && (route[15] == -1))
	{
		//�õ����ڵ�״̬
		status = moveTo.front();
		moveTo.pop();
		for (movers = 1; movers <= 8; movers <<= 1)
		{
			//ũ�������ƶ�����ũ���ƶ���ֻ���Ǻ�ũ��ͬ��Ķ���
			if (farmer(status) == (bool)(status&movers))
			{
				newstatus = status ^ (0x08 | movers);
				//��ȫ��δ�����ǵ��߷�
				if (safe(newstatus) && (route[newstatus] == -1))
				{
					route[newstatus] = status;
					moveTo.push(newstatus);
				}
			}
		}
		if (route[15] != -1)
		{
			cout << "The reverse path is:" << endl;
			for (int status = 15; status >= 0; status = route[status])
			{
				cout << "The status is: " << status << endl;
				if (status == 0)
					break;
			}
		}
		else
			cout << "No solution" << endl;
	}
}

//��ƹ�������
void cross_river(void)
{
	const int num = 5;
	int a[num] = { 1, 3, 6, 8, 12 };
	int t, sum = 0;

	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (a[j] < a[i])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}

	if (num % 2 == 0)
	{
		for (int i = num - 1; i > 1; i -= 2)
		{
			sum += a[i] + a[0] + a[1] + a[1];
		}
		sum += a[1];
	}
	else
	{
		for (int i = num - 1; i > 2; i -= 2)
		{
			sum += a[i] + a[0] + a[1] + a[1];
		}
		sum += a[0] + a[1] + a[2];
	}
	cout << sum << endl;
}



int main(int argc, char* argv[])
{
	//solve();
	cross_river();
	return 0;
}
