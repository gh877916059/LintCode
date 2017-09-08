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
	string multiply(string &num1, string &num2)
	{
		if (num1 == "0" || num2 == "0")
			return "0";
		vector<int> num1_vector;
		vector<int> num2_vector;
		int num1_len = num1.length();
		int num2_len = num2.length();
		for (int i = num1_len - 1; i >= 0; --i)
		{
			num1_vector.push_back(num1[i] - '0');
		}
		for (int i = num2_len - 1; i >= 0; --i)
		{
			num2_vector.push_back(num2[i] - '0');
		}
		vector<int> final_result(num1_len + num2_len, 0);
		vector<int> temp_result(num1_len + num2_len, 0);
		for (int i = 0; i < num1_len; ++i)
		{
			int accumulation = 0;
			for (int j = 0; j < num2_len; ++j)
			{
				accumulation += num1_vector[i] * num2_vector[j];
				temp_result[i+j] = accumulation % 10;
				accumulation /= 10;
			}
			int offset = 0;
			if (accumulation > 0)
			{
				temp_result[i + num2_len + offset] = accumulation % 10;
				accumulation /= 10;
				offset += 1;
			}
			for (int k = 0; k < num1_len + num2_len; ++k)
			{
				accumulation += temp_result[k] + final_result[k];
				final_result[k] = accumulation % 10;
				accumulation /= 10;
			}
			temp_result.assign(num1_len + num2_len, 0);
		}
		string ret;
		int begin_index = num1_len + num2_len - 1;
		while (final_result[begin_index] == 0)
		{
			--begin_index;
		}
		for (int k = begin_index; k >= 0; --k)
		{
			char add_target = final_result[k] + '0';
			ret += add_target;
		}
		return ret;
	}
};
