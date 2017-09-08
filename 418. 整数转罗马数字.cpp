class Solution
{
public:
	string intToRoman(int n)
	{
		if (n <= 0)
			return "";
		int nums[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int digit = 0;
		string res;
		while (n>0)
		{
			int times = n / nums[digit];
			n -= nums[digit] * times;
			for (; times>0; times--)
				res += symbols[digit];
			++digit;
		}
		return res;
	}
};
