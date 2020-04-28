#include <iostream>

int main()
{
#pragma pack(2)
	typedef struct {
		unsigned long index;
		char name[9];
		char *attr[4];
	}tSA, *ptSA;

#pragma pack()
	tSA sa[5];
	char *str;
	ptSA psa1 = sa, psa2 = &sa[4];
	unsigned long i = (unsigned long)psa1, j = (unsigned long)psa2;
	printf("*str:%d\n", sizeof(str));
	printf("sizeof(tSA):%d\n", sizeof(tSA));
	printf("i = %d, j = %d\n", i, j);
	printf("psa2 - psa1 = %d, j-i = %d\n", psa2 - psa1, j - i);
	system("pause");
	return 0;
}
