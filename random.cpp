#include <iostream>
#include <ctime>
using namespace std;

int RandInt(int i, int j)		//srand()放在主函数中了
{
	if (i == 0)
		return rand() % (j + 1);
	else
		return rand() % (j - i + 1) + i;
}
void fun1(int a[], int n)
{
	int tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = RandInt(1, n);
		for (int j = 0; j < i; j++)
		{
			if (tmp == a[j])
			{
				tmp = RandInt(1, n);
				j = -1;
			}
		}
		a[i] = tmp;
	}
}

int used[100] = {0};
void fun2(int a[], int n)
{
	int tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = RandInt(1, n);
		while (used[tmp] != 0)
			tmp = RandInt(1, n);
		a[i] = tmp;
		used[tmp] = 1;
	}
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void fun3(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	for (int i = 1; i < n; i++)
	{
		swap(a[i], a[RandInt(0, i)]);
	}
}
int main()
{
	srand(unsigned(time(NULL)));
	int a[5], b[5], c[5];
	fun1(a, 5);
	fun2(b, 5);
	fun3(c, 5);

	return 0;
}
