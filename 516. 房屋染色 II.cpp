class Solution
{
public:
	int minCostII(vector<vector<int>>& costs)
	{
		if (costs.size() == 0)
			return 0;
		for (int i = 1; i<costs.size(); ++i)
		{
			int min_index = 0, ci_min_index = 0;
			for (int j = 1; j<costs[0].size(); ++j)
			{
				if (costs[i - 1][j]<costs[i - 1][min_index])
					min_index = j;
			}
			if(min_index==0)
			    ++ci_min_index;
			for (int j = 1; j<costs[0].size(); ++j)
			{
				if (j != min_index&&costs[i - 1][j]<costs[i - 1][ci_min_index])
					ci_min_index = j;
			}
			for (int j = 0; j<costs[0].size(); ++j)
			{
				if (j != min_index)
					costs[i][j] += costs[i - 1][min_index];
				else
					costs[i][j] += costs[i - 1][ci_min_index];
			}
		}
		int result = costs[costs.size() - 1][0];
		for (int j = 1; j<costs[0].size(); ++j)
		{
			if (result>costs[costs.size() - 1][j])
				result = costs[costs.size() - 1][j];
		}
		return result;
	}
};
