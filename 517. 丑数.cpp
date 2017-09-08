class Solution
{
public:
	bool isUgly(int num)
	{
		if (num == 1)
			return true;
		vector<int> chou_shu;
		chou_shu.push_back(1);
		int two_index = 0;
		int three_index = 0;
		int five_index = 0;
		int next = 1;
		while (next<num)
		{
			next = min(chou_shu[two_index] * 2, min(chou_shu[three_index] * 3, chou_shu[five_index] * 5));
			if (next == chou_shu[two_index] * 2)two_index++;
			if (next == chou_shu[three_index] * 3)three_index++;
			if (next == chou_shu[five_index] * 5)five_index++;
			chou_shu.push_back(next);
			if (next == num)
				return true;
		}
		return false;
	}
};
