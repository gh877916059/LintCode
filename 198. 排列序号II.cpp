class Solution
{
public:
	long long fac(int numerator)
	{
		long long now = 1;
		for (int i = 1; i <= numerator; ++i)
			now *= (long long)i;
		return now;
	}
	long long generateNum(unordered_map<int, int> &hash)
	{
		long long denominator = 1;
		int sum=0;
		for (auto val : hash)
		{
			if (val.second == 0)
				continue;
			denominator *= fac(val.second);
			sum += val.second;
		}
		if (sum == 0)
			return sum;
		return fac(sum) / denominator;
	}
	long long permutationIndexII(vector<int>& A)
	{
		unordered_map<int, int> hash;
		int n = A.size();
		for (int i = 0; i<n; ++i)
		{
			++hash[A[i]];
		}
		long long ans = 0;
		for (int i = 0; i<n; ++i)
		{
			unordered_map<int, int> flag;
			for (int j = i + 1; j<n; ++j)
			{
				if (A[j]<A[i] && flag[A[j]] == 0)
				{
					++flag[A[j]];
					--hash[A[j]];
					ans += generateNum(hash);
					++hash[A[j]];
				}
			}
			--hash[A[i]];
		}
		return ans + 1;
	}
};
