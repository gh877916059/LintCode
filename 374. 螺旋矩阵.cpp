class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		map<pair<int, int>, bool> visited;
		vector<int> result;
		int n = matrix.size();
		if (n == 0)
			return result;
		int m = matrix[0].size();
		int state = 0;
		int counter = 0;
		for (int i = -1; i <= n; ++i)
		{
			visited[make_pair(i,-1)] = true;
			visited[make_pair(i,m)] = true;
		}
		for (int i = -1; i <= m; ++i)
		{
			visited[make_pair(-1,i)] = true;
			visited[make_pair(n,i)] = true;
		}
		int i = 0, j = 0;
		while (counter<n*m)
		{
			if (!visited[make_pair(i, j)])
			{
				result.push_back(matrix[i][j]);
				visited[make_pair(i, j)] = true;
				++counter;
			}
			switch (state)
			{
			case 0:
				if (!visited[make_pair(i, j + 1)])
					++j;
				else
				{
					++state;
				}
				break;
			case 1:
				if (!visited[make_pair(i + 1, j)])
					++i;
				else
				{
					++state;
				}
				break;
			case 2:
				if (!visited[make_pair(i, j - 1)])
					--j;
				else
				{
					++state;
				}
				break;
			case 3:
				if (!visited[make_pair(i - 1, j)])
					--i;
				else
				{
					++state;
				}
				break;
			}
			state %= 4;
		}
		return result;
	}
};
