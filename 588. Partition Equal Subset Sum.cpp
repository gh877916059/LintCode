#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

class Solution 
{
public:
	bool canPartition(vector<int> &nums)
	{
		int sum = 0;
		for (auto itr = nums.begin(); itr != nums.end(); ++itr)
		{
			sum += (*itr);
		}
		if (sum % 2 != 0)
			return false;
		int half = sum / 2;
		int n = nums.size();
		vector<vector<int>> dp(n+1, vector<int>(half+1, 0));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= half; ++j)
			{
				int i_weight = nums[i-1];
				if (j >= i_weight)
				{
					dp[i][j] = max(dp[i][j], i_weight + dp[i - 1][j - i_weight]);
				}
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
		}
		return dp[n][half] == half;
	}
};
