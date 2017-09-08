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
	int maxEnvelopes(vector<pair<int, int>>& envelopes)
	{
		vector<int> dp;
		//现在问题就简化了成了找高度数字中的LIS，完全就和之前那道Longest Increasing Subsequence一样了
		sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b)
		{
			if (a.first == b.first)
				return a.second > b.second;
			return a.first < b.first;
		});
		for (int i = 0; i < envelopes.size(); ++i)
		{
			auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
			if (it == dp.end())
				dp.push_back(envelopes[i].second);
			else
				*it = envelopes[i].second;
		}
		return dp.size();
	}
};
