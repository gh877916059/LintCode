class Solution
{
public:
	int maxSquare(vector<vector<int> > &matrix)
	{
		int n = matrix.size();
		if (n == 0)
			return 0;
		int m = matrix[0].size();
		if (m == 0)
			return 0;
		vector<vector<int>> dp(n, vector<int>(m, 0));
		for (int i = 0; i<n; ++i)
			dp[i][0] = matrix[i][0];
		for (int j = 0; j<m; ++j)
			dp[0][j] = matrix[0][j];
		for (int i = 1; i<n; ++i)
		{
			for (int j = 1; j<m; ++j)
			{
				if (matrix[i][j] == 1)
				{
					dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
				}
				else
					dp[i][j] = 0;
			}
		}
		int max_len = 0;
		for (int i = 0; i<n; ++i)
		{
			for (int j = 0; j<m; ++j)
			{
				if (max_len<dp[i][j])
					max_len = dp[i][j];
			}
		}
		return max_len*max_len;
	}
};
