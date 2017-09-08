#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	string addStrings(string &num1, string &num2)
	{
		int accumulation = 0;
		string ret;
		int num1_len = num1.length();
		int num2_len = num2.length();
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int max_len = max(num1_len, num2_len);
		for (int i = 0; i < max_len; ++i)
		{
			if (i < num1_len)
			{
				accumulation += (num1[i] - '0');
			}
			if (i < num2_len)
			{
				accumulation += (num2[i] - '0');
			}
			ret = char(accumulation % 10 + '0') + ret;
			accumulation /= 10;
		}
		if (accumulation > 0)
		{
			ret = char(accumulation % 10 + '0') + ret;
		}
		return ret;
	}
};
