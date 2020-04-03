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
		{         // 从第二个数判断是否为负值 
			sum = sum + p[i];   // 如果为正，则将sum与其相加
			if (sum > max) {       // 判断是否为最大，若是将赋值给max，并将子数组末位置改变 
				max = sum;
				end = i;
			}
		}
		else {
			sum = p[i];           // 是负数的话，将第i+1个数赋值给sum 
			if (sum > max) {       // 判断是否为最大，是的话就赋值给sum，并将子数组初始与终止位置改变 
				max = sum;
				start = i;
				end = i;
			}
		}
	}
	*/
	return 0;
}
