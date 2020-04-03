#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (array[j] < array[j - 1])
				swap(array[j], array[j - 1]);
		}
	}
}

int main()
{
	int aa[] = { 3,5,1,5,6,7,1 };
	for (int i = 0;i<7;i++)
		cout << aa[i] ;
	cout << endl;
	bubbleSort(aa, sizeof(aa) / sizeof(aa[0]));
	for (int i = 0; i<7; i++)
		cout << aa[i] ;
	cout << endl;
	return 0;
}
