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
	bool isIsomorphic(string& s, string& t)
	{
		if (s.size() != t.size())
			return false;
		map<char, int>test, comp;
		for (int i = 0; i <= s.size(); i++)
		{
			test[s[i]]++;
			comp[t[i]]++;
		}
		int flag = 0;
		for (int i = 0; i <= s.size(); i++)
		{
			if (test[s[i]] != comp[t[i]])
				return false;
		}
		return true;
	}
};
