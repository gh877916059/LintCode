class Solution
{
public:
	int y[4] = { 1,-1,0,0 };
	int x[4] = { 0,0,1,-1 };
	bool ok = true;
	void surroundedRegions(vector<vector<char>>& board)
	{
		int n = board.size();
		if (n == 0)
			return;
		int m = board[0].size();
		if (m == 0)
			return;
		vector<vector<bool>> checked(n, vector<bool>(m, false));
		for (int i = 0; i<n; ++i)
		{
			for (int j = 0; j<m; ++j)
			{
				if (board[i][j] == 'O' && !checked[i][j])
				{
					ok = true;
					check(checked, board, i, j);
					if (ok)
						tuSe(board, i, j);
				}
			}
		}
		return;
	}
	void check(vector<vector<bool>>& checked, vector<vector<char>>& board, int a, int b)
	{
		int n = board.size();
		int m = board[0].size();
		checked[a][b] = true;
		for (int i = 0; i<4; ++i)
		{
			if (a + y[i]<0 || a + y[i] >= n || b + x[i]<0 || b + x[i] >= m)
				ok = false;
			else if (board[a + y[i]][b + x[i]] == 'O' && !checked[a + y[i]][b + x[i]])
			{
				check(checked, board, a + y[i], b + x[i]);
			}
		}
		return;
	}
	void tuSe(vector<vector<char>>& board, int a, int b)
	{
		int n = board.size();
		int m = board[0].size();
		board[a][b] = 'X';
		for (int i = 0; i<4; ++i)
		{
			if (a + y[i]<0 || a + y[i] >= n || b + x[i]<0 || b + x[i] >= m)
				continue;
			if (board[a + y[i]][b + x[i]] == 'O')
			{
				tuSe(board, a + y[i], b + x[i]);
			}
		}
		return;
	}
};
