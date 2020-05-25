#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
	vector<char> stringstream;
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		stringstream.push_back(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		bool appearTime[128] = {false};
		for (int i = 0; i < stringstream.size(); i++) {
			appearTime[stringstream[i]] = !appearTime[stringstream[i]];
		}
		for (int i = 0; i < stringstream.size(); i++) {
			if (true == appearTime[stringstream[i]])
				return stringstream[i];
		}
		return '#';
	}

};

int main(void)
{
	vector<char>a{ 'g' };
	Solution s;
	s.Insert('g');
	cout<<s.FirstAppearingOnce();
	s.Insert('o');
	cout << s.FirstAppearingOnce();
	s.Insert('o');
	cout << s.FirstAppearingOnce();
	s.Insert('g');
	cout << s.FirstAppearingOnce();
	s.Insert('l');
	cout << s.FirstAppearingOnce();
	s.Insert('e');
	cout << s.FirstAppearingOnce();
	return 0;
}
