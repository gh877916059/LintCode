#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
	int getMoneyAmount(int n)
	{
		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
		for (int width = 2; width <= n; ++width)
		{
			for (int i = 1; i < n; ++i)
			{
				int j = i + width - 1;
				if (j > n)
					break;
				int min_cost = INT_MAX;
				for (int k = i; k <= j; ++k)
				{
					int temp = k + max(dp[i][k - 1], dp[k + 1][j]);
					if (temp < min_cost)
						min_cost = temp;
				}
				dp[i][j] = min_cost;
			}
		}
		return dp[1][n];
	}
};
