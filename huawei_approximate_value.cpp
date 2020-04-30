#include <iostream>

using namespace std;

int main(void)
{
	float in = 0.0;
	cin >> in;
	if (((int)(in * 10) % 10) < 5)
		cout << (int)in;
	else
		cout << (int)in + 1;
	return 0;
}
