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
	vector<int> findAnagrams(string &s, string &p)
	{
		const int s_len = s.length();
		const int p_len = p.length();
		vector<int> ret;
		int left_index = 0;
		int right_index = 0;
		int matched_count = 0;
		unordered_map<char, int> char_counter;
		for (int i = 0; i < p_len; ++i)
		{
			++char_counter[p[i]];
		}
		while (right_index < s_len)
		{
			if (--char_counter[s[right_index]] >= 0)
			{
				++matched_count;
			}
			if (right_index - left_index + 1 > p_len)
			{
				if (++char_counter[s[left_index]] > 0)
				{
					--matched_count;
				}
				++left_index;
			}
			if (matched_count == p_len)
			{
				ret.push_back(left_index);
			}
			++right_index;
		}
		return ret;
	}
};
