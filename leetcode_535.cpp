#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//关于hasp表操作
//https://www.cnblogs.com/slothrbk/p/8823092.html
//https://leetcode-cn.com/problems/encode-and-decode-tinyurl/solution/tinyurlde-jia-mi-yu-jie-mi-by-leetcode/
class Solution {
private:
	string shorturl_prefix = "http://tinyurl.com/";
	string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unordered_map<string, string> map;
	int count = 1;

public:

	string getString() {
		int c = count;
		string s;
		while (c > 0) {
			c--;
			s.insert(s.end(), chars[c % 62]);
			c /= 62;
		}
		return s;
	}

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string key = getString();
		map.insert(make_pair(key, longUrl));
		count++;
		return (shorturl_prefix + key);
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		string code = shortUrl.substr(shorturl_prefix.size());
		unordered_map<string,string>::const_iterator temp = map.find(code);
		if (temp == map.end())
			return nullptr;
		else
			return temp->second;
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(void)
{
	Solution s;
	cout << s.encode("www.baidu.com") << endl;
	cout << s.decode("http://tinyurl.com/0") << endl;
	//unordered_map<string, string> a = { {"123", "aaa"}, {"456" , "bbb"} } ;
	//cout << a.find("123")->first<< a.find("123")->second << endl;
	return 0;
}
