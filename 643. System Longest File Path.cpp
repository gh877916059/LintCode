#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int lengthLongestPath(string input)
	{
		int res = 0;
		istringstream ss(input);
		unordered_map<int, int> m{ { 0, 0 } };
		string line = "";
		while (getline(ss, line))
		{
			int level = line.find_last_of('\t') + 1;
			int len = line.substr(level).length();
			//如果是文件
			if (line.find('.') != string::npos)
			{
				res = max(res, m[level] + len);
			}
			//如果是目录
			else
			{
				m[level + 1] = m[level] + len + 1;
			}
		}
		return res;
	}
};
