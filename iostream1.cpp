#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
using namespace std;

int main()
{
	char data[100];
	ofstream outfile;
	ifstream infile;
	char *filename = "F:\\VSProject\\Project18\\Project18\\hello.txt";
	struct stat statbuf;
	outfile.open(filename, ios::out|ios::app);
	cout << "Writing to the file" << endl;
	cout << "Enter your name: ";
	cin.getline(data, 100);
	outfile << data << endl;

	cout << "Enter your age: ";
	cin >> data;
	cin.ignore();

	// 再次向文件写入用户输入的数据
	outfile << data << endl;

	// 关闭打开的文件
	outfile.close();

	infile.open(filename, ios::in);
	cout << "Reading from the file" << endl;
	stat(filename, &statbuf);
	while (infile)
	{
		infile.getline(data, 100);
		cout << data << endl;
	}
	// 关闭打开的文件
	infile.close();

	return 0;
}
