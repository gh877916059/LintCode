class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        map<pair<int, int>, bool> visited;
        vector<vector<int>> result(n,vector<int>(n,0));
        int counter=1;
        int state=0;
        for (int i = -1; i <= n; ++i)
		{
			visited[make_pair(i,-1)] = true;
			visited[make_pair(i,n)] = true;
		}
		for (int i = -1; i <= n; ++i)
		{
			visited[make_pair(-1,i)] = true;
			visited[make_pair(n,i)] = true;
		}
		int i=0,j=0;
		while (counter<=n*n)
		{
			if (!visited[make_pair(i, j)])
			{
				result[i][j]=counter;
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
