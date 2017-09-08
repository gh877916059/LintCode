#include <iostream>
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
	int firstUniqChar(string &s)
	{
		unordered_map<char, int> char_counter;
		unordered_map<char, int> char_to_first_index;
		int s_len = s.length();
		for (int i = 0; i < s_len; ++i)
		{
			if (++char_counter[s[i]] == 1)
			{
				char_to_first_index[s[i]] = i;
			}
		}
		int ret = INT_MAX;
		for (auto itr = char_counter.begin(); itr != char_counter.end(); ++itr)
		{
			char target_char = itr->first;
			int times = itr->second;
			if (times == 1)
			{
				int first_index = char_to_first_index[target_char];
				ret = min(ret, first_index);
			}
		}
		if (ret == INT_MAX)
			ret = -1;
		return ret;
	}
};
