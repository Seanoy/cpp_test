#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//人狼羊菜过河问题,使用位向量表示
//状态迁移，从0000到1111
//目标在起始岸为0，在目标岸为1

//确认每个角色位置的函数
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

//安全状态判断
bool safe(int status)
{
	//羊和菜一起而且没有农夫，则错误
	if ((goat(status) == cabbage(status)) &&
		(goat(status) != farmer(status)))
		return false;

	//羊和狼一起而且没有农夫，则错误
	else if ((goat(status) == wolf(status)) &&
		(goat(status) != farmer(status)))
		return false;

	else
		return true;//其他状态安全
}

//0000->1111由合法序列构成
//使用队列moveTo表示可以安全到达的中间状态
//定义一个数据结构用于记录被访问过的各个状态route[i]
#define END 0X0F //1111B
void solve(void) 
{
	int movers, i;
	int status, newstatus;

	vector<int> route(END + 1, -1);//填充数据
	queue<int> moveTo;

	moveTo.push(0x00);
	route[0] = 0;

	while (!moveTo.empty() && (route[15] == -1))
	{
		//得到现在的状态
		status = moveTo.front();
		moveTo.pop();
		for (movers = 1; movers <= 8; movers <<= 1)
		{
			//农夫总在移动，随农夫移动的只能是和农夫同侧的东西
			if (farmer(status) == (bool)(status&movers))
			{
				newstatus = status ^ (0x08 | movers);
				//安全的未被考虑的走法
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

//提灯过河问题
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
