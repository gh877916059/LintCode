class Solution
{
public:
	vector<string> result;
	vector<vector<char>> map;
	string cur;
	vector<string> letterCombinations(string& digits)
	{
		if (digits.length() == 0)
			return result;
		vector<char> temp;
		map.push_back(temp);
		map.push_back(temp);
		temp = { 'a','b','c' };
		map.push_back(temp);
		temp = { 'd','e','f' };
		map.push_back(temp);
		temp = { 'g','h','i' };
		map.push_back(temp);
		temp = { 'j','k','l' };
		map.push_back(temp);
		temp = { 'm','n','o' };
		map.push_back(temp);
		temp = { 'p','q','r','s' };
		map.push_back(temp);
		temp = { 't','u','v' };
		map.push_back(temp);
		temp = { 'w','x','y','z' };
		map.push_back(temp);
		diGui(digits, 0);
		return result;
	}
	void diGui(string& digits, int pos)
	{
		if (pos == digits.length())
			result.push_back(cur);
		else
		{
			for (int i = 0; i<map[digits[pos] - '0'].size(); ++i)
			{
				cur += map[digits[pos] - '0'][i];
				diGui(digits, pos + 1);
				cur = cur.substr(0, cur.length() - 1);
			}
		}
	}
};
