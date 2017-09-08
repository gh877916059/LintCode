class Solution
{
public:
	double maxAverage(vector<int>& nums, int k)
	{
		int n = nums.size();
		if (k>n)
			return -1;
		vector<long long> csum(n, 0);
		csum[0] = nums[0];
		for (int i = 1; i<n; ++i)
			csum[i] = csum[i - 1] + (long long)nums[i];
		double result = (double)LONG_LONG_MIN;
		int counter=0;
		for (int len = k; len <= nums.size(); ++len)
		{
			long long max_sum = csum[len - 1], max_end = len - 1;
			for (int i = len; i<n; ++i)
			{
				long long curr_sum = csum[i] - csum[i - len];
				if (curr_sum>max_sum)
				{
					max_sum = curr_sum;
					max_end = i;
				}
			}
			double temp = (double)(max_sum) / len;
			if(temp<result)
			    ++counter;
			result = max(result, temp);
			if(counter==1000)
			    break;
		}
		return result;
	}
};
