class Solution
{
public:
	int StrToInt(string str)
	{
		stringstream ss(str);
		int result;
		ss >> result;
		return result;
	}
	string IntToStr(int num)
	{
		string str;
		stringstream ss;
		ss << num;
		str = ss.str();
		return str;
	}
	bool isShu(string str)
	{
		if (str[0] >= '0'&&str[0] <= '9')
			return true;
		if (str[0] == '-' && str.length()>1)
			return true;
		return false;
	}
	int evalRPN(vector<string>& tokens)
	{
		int result;
		stack<string> stack;
		for (auto i : tokens)
		{
			if (isShu(i))
			{
				stack.push(i);
			}
			else
			{
				int hou = StrToInt(stack.top());
				stack.pop();
				int qian = StrToInt(stack.top());
				stack.pop();
				int result;
				if (i == "+")
				{
					result = qian + hou;
				}
				else if (i == "-")
				{
					result = qian - hou;
				}
				else if (i == "*")
				{
					result = qian*hou;
				}
				else
				{
					result = qian / hou;
				}
				stack.push(IntToStr(result));
			}
		}
		if (stack.empty())
			return 0;
		return StrToInt(stack.top());
	}
};
