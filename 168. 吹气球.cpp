class Solution
{
public:
	int maxCoins(vector<int>& nums)
	{
		int *ass = new int[nums.size() + 2]; 
		int n_len = 1;
		for (int n : nums)
		    ass[n_len++] = n;
		ass[0] = ass[n_len++] = 1;
		vector<vector<int>> result(n_len, vector<int>(n_len));
		for (int n_window = 2; n_window < n_len; ++n_window)
		{
			for (int left = 0; left < n_len - n_window; ++left)
			{
				int right = left + n_window;
				for (int n_middle = left + 1; n_middle < right; ++n_middle)
					result[left][right] = max(result[left][right],
						ass[left] * ass[n_middle] * ass[right] +
						result[left][n_middle] + result[n_middle][right]);
			}
		}
		delete[]ass;
		return result[0][n_len - 1];
	}
};
