#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int icount = 0;
		int iflag = 0;
		for (int i = 0; i < data.size(); i++)
		{
			if (data[i] == k)
			{
				iflag = 1;
				icount++;
			}
			else if (iflag == 1)
				break;
		}
		return icount;
	}
};

int main(void)
{


	return 0;
}
