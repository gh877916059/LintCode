class Solution
{
public:
	bool isNumber(string& s)
	{
		int len = s.length();
		int i = 0, e = len - 1;
		while (i <= e&&s[i] == ' ')
			++i;
		if (i>len - 1)
			return false;
		while (e >= i&&s[e] == ' ')
			--e;
		if (s[i] == '+' || s[i] == '-')
			++i;
		bool num = false;
		bool dot = false;
		bool exp = false;
		while (i <= e)
		{
			char c = s[i];
			if (c >= '0'&&c <= '9')
				num = true;
			else if (c == '.')
			{
				if (exp || dot)
					return false;
				dot = true;
			}
			else if (c == 'e')
			{
				if (exp || num == false)
					return false;
				exp = true;
				num = false;
			}
			else if (c == '+' || c == '-')
			{
				if (s[i - 1] != 'e')
					return false;
			}
			else
				return false;
			++i;
		}
		return num;
	}
};
