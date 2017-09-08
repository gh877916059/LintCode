#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
using namespace std;

class Solution
{
public:
	/*
	我们使用双端队列容器存储最大值在数组中的索引。队列头部是以前窗口中最大值的最大值。
	当以前窗口的最大值被滑出窗口时，需要从队列头部删除。
	当新值大于队列中数字最大的数字时，删除队列中的所有数字，存储新值到队列头。（新值索引靠后，老值已经没有可能成为新窗口的最大值）
	当新值不大于原有最大值时，当滑动新窗口时，仍有可能成为最大值，首先从队列尾依次删除比新值小的数字，然后存储到新值队列尾。
	*/
	vector<int> maxSlidingWindow(vector<int> &nums, int k)
	{
		deque<int> Q;
		vector<int> result;
		if (k == 0)
			return result;
		for (int i = 0; i<k; ++i)
		{
			while (!Q.empty() && nums[i] >= nums[Q.back()])
				Q.pop_back();
			Q.push_back(i);
		}
		for (int i = k; i<nums.size(); ++i)
		{
			result.push_back(nums[Q.front()]);
			while (!Q.empty() && nums[i] >= nums[Q.back()])
				Q.pop_back();
			while (!Q.empty() && Q.front() <= i - k)
				Q.pop_front();
			Q.push_back(i);
		}
		result.push_back(nums[Q.front()]);
		return result;
	}
};
