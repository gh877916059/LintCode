class Solution
{
public:
	int maxTwoSubArrays(vector<int> nums)
	{
		int n = nums.size();
		vector<int> max_left(n, 0);
		vector<int> max_right(n, 0);
		maxSub(nums, max_left, n);
		reverse(nums.begin(), nums.end());
		maxSub(nums, max_right, n);
		int result = INT_MIN;
		for (int i = 1; i < n; ++i)
		{
			if (result<(max_left[i - 1] + max_right[n - i - 1]))
				result = max_left[i - 1] + max_right[n - i - 1];
		}
		return result;
	}
	void maxSub(vector<int>& nums, vector<int>& dp, int n)
	{
		int cur_sum = nums[0];
		int max_sum = nums[0];
		dp[0] = nums[0];
		for (int i = 1; i<n; ++i)
		{
			if (cur_sum>0)
				cur_sum += nums[i];
			else
				cur_sum = nums[i];
			if(cur_sum>max_sum)
			    max_sum=cur_sum;
			dp[i] = max_sum;
		}
		return;
	}
};
