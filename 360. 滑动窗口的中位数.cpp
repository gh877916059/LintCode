#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
	vector<int> medianSlidingWindow(vector<int>& nums, int k)
	{
		vector<int> res;
		//small存储滑动窗口中比较小的数，large存储滑动窗口中比较大的数
		//并且保证有效状态：small的大小-large的大小∈{0,1}
		multiset<int> small, large;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i >= k)
			{
				if (small.count(nums[i - k]))
					small.erase(small.find(nums[i - k]));
				else if (large.count(nums[i - k]))
					large.erase(large.find(nums[i - k]));
			}
			if (small.size() <= large.size())
			{
				if (large.empty() || nums[i] <= *large.begin())
					small.insert(nums[i]);
				else
				{
					small.insert(*large.begin());
					large.erase(large.begin());
					large.insert(nums[i]);
				}
			}
			else
			{
				if (nums[i] >= *small.rbegin())
					large.insert(nums[i]);
				else
				{
					large.insert(*small.rbegin());
					small.erase(--small.end());
					small.insert(nums[i]);
				}
			}
			if (i >= (k - 1))
			{
				res.push_back(*small.rbegin());
			}
		}
		return res;
	}
};
