class Solution
{
public:
	bool isMatch(const char *s, const char *p)
	{
		int n1 = strlen(s);
		int n2 = strlen(p);
		int countXing = 0;
		for (int i=0;i<n2;++i)
		{
			if (p[i] == '*')
				++countXing;
		}
		if (n2 - countXing>n1)
			return false;
		vector<vector<bool> > dp(n2 + 1, vector<bool>(n1 + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= n2; ++i)
		{
			char s2_char = p[i - 1];
			dp[i][0] = dp[i - 1][0] && s2_char == '*';
			for (int j = 1; j <= n1; ++j)
			{
				char s1_char = s[j - 1];
				if (s2_char == '*')
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				else
					dp[i][j] = dp[i - 1][j - 1] && (s2_char == '?' || s1_char == s2_char);
			}
		}
		return dp[n2][n1];
	}
};
