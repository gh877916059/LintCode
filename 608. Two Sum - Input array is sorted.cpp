#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

class Solution 
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		vector<int> ret;
		int a_index = 0;
		int b_index = nums.size() - 1;
		if (b_index <= a_index)
			return ret;
		while (a_index < b_index)
		{
			int two_sum = nums[a_index] + nums[b_index];
			if (two_sum == target)
			{
				ret.push_back(a_index + 1);
				ret.push_back(b_index + 1);
				break;
			}
			else if (two_sum < target)
			{
				++a_index;
			}
			else
			{
				--b_index;
			}
		}
		return ret;
	}
};
