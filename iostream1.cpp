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

	// �ٴ����ļ�д���û����������
	outfile << data << endl;

	// �رմ򿪵��ļ�
	outfile.close();

	infile.open(filename, ios::in);
	cout << "Reading from the file" << endl;
	stat(filename, &statbuf);
	while (infile)
	{
		infile.getline(data, 100);
		cout << data << endl;
	}
	// �رմ򿪵��ļ�
	infile.close();

	return 0;
}
