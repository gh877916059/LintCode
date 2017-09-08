class Solution
{
public:
	vector<int> dx = { 1,0,0,-1 };
	vector<int> dy = { 0, 1, -1, 0 };
	int n, m;
	void removeIsland(vector<vector<bool>>& grid, int x, int y)
	{
		grid[x][y] = false;
		for (int i = 0; i<4; ++i)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX >= 0 && nextX<n&&nextY >= 0 && nextY<m)
			{
				if (grid[nextX][nextY])
					removeIsland(grid,nextX, nextY);
			}
		}
	}
	int numIslands(vector<vector<bool>>& grid)
	{
		n = grid.size();
		if (n == 0)
			return 0;
		m = grid[0].size();
		if (m == 0)
			return 0;
		int count = 0;
		for (int i = 0; i<n; ++i)
		{
			for (int j = 0; j<m; ++j)
			{
				if (grid[i][j])
				{
					removeIsland(grid, i, j);
					++count;
				}
			}
		}
		return count;
	}
};
