class StringUtils
{
public:
	static string leftPad(string& originalStr, int size, char padChar = ' ')
	{
		string result = originalStr;
		for (int i = 0; i<(size - (int)originalStr.length()); ++i)
		{
			result = padChar + result;
		}
		return result;
	}
};
