class Solution
{
public:
	vector<vector<int>> submatrixSum(vector<vector<int>>& matrix)
	{
		vector<vector<int>> result(2, vector<int>(2, 0));
		int N = matrix.size();
		if (N == 0)
			return result;
		int M = matrix[0].size();
		if (M == 0)
			return result;
		vector<vector<int>> sum(N + 1, vector<int>(M + 1, 0));
		for (int i = 0; i<N; ++i)
		{
			for (int j = 0; j<M; ++j)
				sum[i + 1][j + 1] = matrix[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
		}
		for (int l = 0; l<N; ++l)
		{
			for (int h = l + 1; h <= N; ++h)
			{
				map<int, int> map;
				for (int j = 0; j <= M; ++j)
				{
					int diff = sum[h][j] - sum[l][j];
					if (map.find(diff) != map.end())
					{
						int k = map[diff];
						result[0][0] = l;
						result[0][1] = k;
						result[1][0] = h - 1;
						result[1][1] = j - 1;
						return result;
					}
					else
						map[diff] = j;
				}
			}
		}
		return result;
	}
};
