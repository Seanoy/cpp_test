#include <iostream>
#include <string.h>
#include <stdlib.h> 
#include <cstdlib> 

using namespace std;

int main(int argc, char* argv[]) {
	char num_old[100] = {0};
	char num_new[100] = {0};
	char temp;
	int length = 0;
	int i = 0, j = 0;
	int old_buffer[10] = {0};
	int new_buffer[10] = {0};

	//获取字符串
	cout << "please input a number" << endl;
	cin >> num_old;

	//获取字符串长度
	while ((temp = num_old[length]) != '\0') {
		length++;
	}

	if(num_old[0]>'4') {//如果最高位大于4则右移一位
		length++;
		for (j = length - 1; j > 0; j--)
		{
			num_old[j] = num_old[j - 1];
		}
		num_old[0] = '0';
	}
	//cout << num_old << endl;
	
	j = length;

	do {
		temp = num_old[j-1] - 48;
		temp *= 2;
		if (temp > 9) {
			num_new[j-2] += 1;
			temp -= 10;
		}
		num_new[j - 1] += temp + 48;
		j--;
		//cout << temp << endl;
	} while (j != 0);

	//cout << "input num:" << num_old << endl;
	//cout << "double num:" << num_new << endl;

	for (j = length; j > 0; j--)
	{
		if (num_old[j-1] != '0') {
			old_buffer[num_old[j - 1]-48] += 1;
		}
		if (num_new[j - 1] != '0') {
			new_buffer[num_new[j - 1] - 48] += 1;
		}
	}


	if (memcmp(new_buffer, old_buffer, 10)) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	cout << num_new << endl;
	
	system("pause");

//	return 0;
}
