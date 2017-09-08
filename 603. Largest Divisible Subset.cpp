#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		vector<int> dp(nums.size(), 0), parent(nums.size(), 0), res;
		int mx = 0, mx_idx = 0;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			for (int j = i; j < nums.size(); ++j)
			{
				if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					parent[i] = j;
					if (mx < dp[i])
					{
						mx = dp[i];
						mx_idx = i;
					}
				}
			}
		}
		for (int i = 0; i < mx; ++i)
		{
			res.push_back(nums[mx_idx]);
			mx_idx = parent[mx_idx];
		}
		return res;
	}
};
