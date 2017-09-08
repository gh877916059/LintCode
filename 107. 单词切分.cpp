class Solution
{
public:
	bool wordBreak(string s, unordered_set<string> &dict)
	{
		if (s == "")
			return true;
		int max_length = 0;
		for (auto i : dict)
		{
			max_length = max(max_length, (int)i.length());
		}
		vector<bool> canSegment(s.length() + 1, false);
		canSegment[0] = true;
		for (int i = 1; i <= s.length(); ++i)
		{
		    canSegment[i] = false;
			for (int j = 1; j <= i&&j <= max_length; ++j)
			{
				if (!canSegment[i - j])
					continue;
				if (dict.find(s.substr(i - j, j)) != dict.end())
				{
					canSegment[i] = true;
					break;
				}
			}
		}
		return canSegment[s.length()];
	}
};
