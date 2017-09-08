class Solution
{
public:
	vector<vector<string>> result;
	vector<string> cur;
	vector<vector<string>> partition(string s)
	{
		int n = s.length();
		vector<vector<bool> > dp1(n, vector<bool>(n, false));
		for (int len = 1; len <= n; len++)
		{
			for (int i = 0; i + len - 1<n; i++)
			{
				int j = i + len - 1;
				if (len == 1)
				{
					dp1[i][j] = true;
				}
				else
				{
					if (s[i] == s[j] && (i == j - 1 || dp1[i + 1][j - 1]))
						dp1[i][j] = true;
				}
			}
		}
		diGui(dp1, s, 0);
		return result;
	}
	void diGui(vector<vector<bool>>& check, string& s, int pos)
	{
		if (pos == s.length())
		{
			result.push_back(cur);
			return;
		}
		for (int j = pos; j<s.length(); ++j)
		{
			if (check[pos][j])
			{
				cur.push_back(s.substr(pos, j - pos + 1));
				diGui(check, s, j + 1);
				cur.pop_back();
			}
		}
	}
};
