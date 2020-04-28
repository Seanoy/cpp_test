#include <iostream>
using namespace std;

long int pow(int x, int n)//O(logN)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return x;
	}
	if (n % 2 == 0)
	{
		return pow(x*x, n / 2);
	}
	else
		return pow(x*x, n / 2)*x;
}

long int horner(const int x, int power, const int coef[])
{
	long int poly = 0;
	for (int i = power - 1; i >= 0; i--)
	{
		poly = x*poly + coef[i];
	}
	return poly;
}

int main()
{
	long int x;
	x = pow(2, 10);
	int coef[4] = { 2,1,8,4 };
	x = horner(1, 4, coef);
	return 0;
}
