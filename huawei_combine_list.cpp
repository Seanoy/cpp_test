#include <iostream>

using namespace std;
#define ARRAY_SIZE 1000
int main(void)
{
	int num_arr[ARRAY_SIZE] = { 0 };
	int count, key, value;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		scanf_s("%d %d", &key, &value);
		num_arr[key] += value;
	}
	for (int j = 0; j < ARRAY_SIZE; j++)
		if (num_arr[j] != 0)
			cout << j << " " << num_arr[j] << endl;
	return 0;
}
