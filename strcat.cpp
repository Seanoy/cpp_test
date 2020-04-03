#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
using namespace std;
char* combine(const char* str1, const char* str2)
{
	char* result = NULL;
	result = (char *)malloc(strlen(str1) + strlen(str2));
	result = strcat((char *)str1, (char *)str2);
	return result;
}

int main(int argc, char*argv)
{
	char a[20] = "Hello ";
	char b[] = "world";
	cout << combine(a, b) << endl;
	system("pause");
	return 0;
}