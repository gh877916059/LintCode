#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;

class Solution
{
public:
	bool isOneEditDistance(string &s, string &t)
	{
		int m = s.length(), n = t.length();
		if (m == n)
			return isOneModified(s, t);
		if (m - n == 1)
			return isOneDeleted(s, t);
		if (n - m == 1)
			return isOneDeleted(t, s);
		// 长度差距大于2直接返回false
		return false;
	}
private:
	// 看是否只修改一个字符就能使两个字符串相等
	bool isOneModified(string &s, string &t)
	{
		int modified_counter = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != t[i])
			{
				++modified_counter;
				if (modified_counter > 1)
					return false;
			}
		}
		return modified_counter==1;
	}

	// 看是否只删除一个字符就能使两个字符串相等
	bool isOneDeleted(string &longer, string &shorter)
	{
		// 找到第一组不一样的字符，看后面是否一样
		for (int i = 0; i < shorter.length(); i++)
		{
			if (longer[i] != shorter[i])
			{
				return longer.substr(i + 1) == shorter.substr(i);
			}
		}
		return true;
	}
};
