#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int longestPalindrome(string s)
	{
		unordered_map<char, int> char_counter;
		for (int i = s.length() - 1; i >= 0; --i)
		{
			++char_counter[s[i]];
		}
		int ret = 0;
		bool has_ood = false;
		for (auto itr = char_counter.begin(); itr != char_counter.end(); ++itr)
		{
			int times = itr->second;
			ret += (times / 2) * 2;
			if (times % 2 == 1)
				has_ood = true;
		}
		if (has_ood)
			++ret;
		return ret;
	}
};
