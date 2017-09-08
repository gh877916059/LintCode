class Solution
{
public:
	int majorityNumber(vector<int> nums, int k)
	{
		unordered_map<int, int> counters;
		for (auto i : nums)
		{
			if (counters.find(i) != counters.end())
				++counters[i];
			else
			{
				if (counters.size() < k - 1)
					++counters[i];
				else
				{
					for (unordered_map<int, int>::iterator it = counters.begin(); it != counters.end();)
					{
						--it->second;
						if (it->second == 0)
							it = counters.erase(it);
						else
							++it;
					}
				}
			}
		}
		for (auto i : counters)
		{
			i.second = 0;
		}
		for (auto i : nums)
		{
			if (counters.find(i) != counters.end())
				++counters[i];
		}
		int max_counter = 0;
		int max_key = 0;
		for (auto i : counters)
		{
			if (i.second>max_counter)
			{
				max_counter = i.second;
				max_key = i.first;
			}
		}
		return max_key;
	}
};
