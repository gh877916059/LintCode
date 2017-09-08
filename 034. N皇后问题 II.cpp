class Solution
{
public:
	int totalNQueens(int n)
	{
		vector<int> queens(n,-1);
		int result = 0;
		diGui(result, queens, 0, n);
		return result;
	}
	void diGui(int& result, vector<int>& queens, int pos, int n)
	{
		if (pos == n)
		{
			++result;
			return;
		}
		for (int i = 0; i<n; ++i)
		{
			queens[pos] = i;
			if (check(queens, pos))
			{
				diGui(result, queens, pos + 1, n);
			}
		}
		return;
	}
	bool check(vector<int>& queens, int pos)
	{
		for (int i = 0; i<=pos; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (queens[i] == queens[j])
					return false;
				if (abs(i - j) == abs(queens[i] - queens[j]))
					return false;
			}
		}
		return true;
	}
};
