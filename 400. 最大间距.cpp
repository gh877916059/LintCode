class Solution
{
public:
	int maximumGap(vector<int> nums)
	{
		int n = nums.size();
		if (n<2)
			return 0;
		int max = nums[0];
		int min = nums[0];
		for (int i = 1; i<n; ++i)
		{
			max = std::max(max, nums[i]);
			min = std::min(min, nums[i]);
		}
		if(max==min)
		    return 0;
		vector<int> left(n, INT_MAX);
		vector<int> right(n, INT_MIN);
		vector<bool> is_kong(n, true);
		for (int i = 0; i<n; ++i)
		{
			int ind = floor((double)(nums[i] - min)*(n - 1) / (max - min));
			if (is_kong[ind])
			{
				left[ind] = nums[i];
				right[ind] = nums[i];
				is_kong[ind] = false;
			}
			else
			{
				left[ind] = std::min(left[ind], nums[i]);
				right[ind] = std::max(right[ind], nums[i]);
			}
		}
		int pre = min, res = 0;
		for (int i = 0; i<n; ++i)
		{
			if (!is_kong[i])
			{
				res = std::max(left[i] - pre, res);
				pre = right[i];
			}
		}
		return res;
	}
};
