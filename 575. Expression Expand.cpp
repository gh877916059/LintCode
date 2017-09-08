#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
#include <sstream>
using namespace std;

struct NumOrChar
{
	bool is_num;
	int num_val;
	char char_val;
	NumOrChar(bool _is_num, int _num_val, char _char_val) :is_num(_is_num), num_val(_num_val), char_val(_char_val) {}
};

class Solution
{
public:
	string expressionExpand(string &s)
	{
		stack<NumOrChar> str_stack;
		int num = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] >= '0'&&s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
			}
			else if (s[i] == '[')
			{
				auto element = NumOrChar(true, num, '?');
				str_stack.push(element);
				num = 0;
			}
			else if (s[i] == ']')
			{
				strStackTransform(str_stack);
			}
			else
			{
				auto element = NumOrChar(false, -1, s[i]);
				str_stack.push(element);
			}
		}
		string str_final;
		while (!str_stack.empty())
		{
			str_final = str_stack.top().char_val + str_final;
			str_stack.pop();
		}
		return str_final;
	}
	void strStackTransform(stack<NumOrChar>& str_stack)
	{
		string str_once;
		while (!str_stack.empty() && !str_stack.top().is_num)
		{
			str_once = str_stack.top().char_val + str_once;
			str_stack.pop();
		}
		int times = 1;
		if (str_stack.top().is_num)
		{
			times = str_stack.top().num_val;
			str_stack.pop();
		}
		for (int i = 0; i < times; ++i)
		{
			for (int j = 0; j < str_once.length(); ++j)
			{
				auto element = NumOrChar(false, -1, str_once[j]);
				str_stack.push(element);
			}
		}
	}
};
