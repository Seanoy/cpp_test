#include <iostream>

struct data {
	uint16_t a;
	uint8_t b;
	uint16_t c;
}*example;

int main(int argc, char* argv[]) {
	uint8_t num[] = { 1,2,3,4,5,6,7 };
	example =(struct data*)num;
	printf("%x %x %x", example->a, *(&(example->b)+1), example->c);
	system("pause");
	return 0;
}