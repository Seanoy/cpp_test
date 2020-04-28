#include <iostream>
using namespace std;

#define ElementType int

int binarySearch(const ElementType A[], ElementType X, int N)
{
	int low, mid, high;
	low = 0;
	high = N - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (A[mid] < X)
		{
			low = mid + 1;
		}
		else if (A[mid] > X)
		{
			high = mid - 1;
		}
		else
			return mid;
	}
	return -1;
}

int main()
{
	ElementType arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int found;
	found = binarySearch(arr, 3, 10);
	return 0;
}
