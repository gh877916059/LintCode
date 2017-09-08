class Solution
{
public:
	int StrToInt(string s)
	{
		stringstream ss(s);
		int a;
		ss >> a;
		return a;
	}
	int numDecodings(string& s)
	{
		if (s.length() == 0)
			return 0;
		if (s[0] == '0')
			return 0;
		vector<int> number(s.length() + 1);
		number[0] = 1;
		number[1] = 1;
		int tmp;
		for (int i = 2; i <= s.length(); ++i)
		{
			if (s[i - 1] != '0')
				number[i] = number[i - 1];
			if (s[i - 2] != '0')
			{
				tmp = StrToInt(s.substr(i - 2, 2));
				if (tmp>0 && tmp <= 26)
					number[i] += number[i - 2];
			}
		}
		return number[s.length()];
	}
};
