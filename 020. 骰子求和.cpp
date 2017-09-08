class Solution
{
public:
	vector<pair<int, double>> dicesSum(int n)
	{
		vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1, 0));
		for (int i = 1; i <= 6; ++i)
		{
			dp[1][i] = 1;
		}
		for (int i = 2; i <= n; ++i)
		{
			for (int j = i; j <= 6 * i; ++j)
			{
				for (int k = 1; k <= 6; ++k)
				{
					if ((j - k) >= i - 1 && (j - k) <= 6 * (i - 1))
						dp[i][j] += dp[i - 1][j - k];
				}
			}
		}
		vector<pair<int, double>> result;
		double sum = 0;
		for (int i = n; i <= 6 * n; ++i)
		{
			sum += dp[n][i];
		}
		for (int i = n; i <= 6 * n; ++i)
		{
			result.push_back(make_pair(i, dp[n][i] / sum));
		}
		return result;
	}
};
