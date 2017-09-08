class Solution
{
public:
	vector<int> continuousSubarraySum(vector<int>& A)
	{
		vector<int> result;
		if (A.size() == 0)
			return result;
		int cur_start = 0;
		int max_start = 0;
		int end = 0;
		int sum = A[0];
		int max_sum = A[0];
		for (int i = 1; i<A.size(); ++i)
		{
			if (sum>0)
				sum += A[i];
			else
			{
				sum = A[i];
				cur_start = i;
			}
			if (sum>max_sum)
			{
				max_sum = sum;
				max_start=cur_start;
				end = i;
			}
		}
		result.push_back(max_start);
		result.push_back(end);
		return result;
	}
};
