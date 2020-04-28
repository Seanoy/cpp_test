#include <iostream>
using namespace std;

unsigned int Gcd(unsigned int M, unsigned int N)
{
	unsigned Rem;
	while (N > 0)
	{
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}

int main()
{
	int gcd;
	gcd = Gcd(100, 12);
	return 0;
}
