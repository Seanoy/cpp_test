#include <iostream>
#include <string>
#include <csignal>
#include <stdlib.h>
#include <windows.h>
//#include <windows.h>
using namespace std;

void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << ")received" << endl;
	exit(signum);
}

int main(int argc, char*argv[])
{
	int i = 0;
	signal(SIGINT, signalHandler);

	while (++i)
	{
		cout << "Going to sleep..." << endl;
		if (i == 3) {
			raise(SIGINT);
		}
		Sleep(1000);
	}

	return 0;
}

