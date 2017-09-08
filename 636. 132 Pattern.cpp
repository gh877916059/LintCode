#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	bool find132pattern(vector<int>& nums)
	{
		if (nums.size() <= 2)
			return false;
		//i, j, k分别为132模式三个数在nums数组中的下标索引
		int n = nums.size(), i = 0, j = 0, k = 0;
		while (i < n)
		{
			//如果发现当前数字大于等于后面一个数字，我们就往下继续遍历，直到当前数字小于下一个数字停止
			while (i < n - 1 && nums[i] >= nums[i + 1])
				++i;
			j = i + 1;
			//如果我们发现当前数字小于等于下一个数字就继续遍历，直到当前数字大于下一个数字停止
			while (j < n - 1 && nums[j] <= nums[j + 1])
				++j;
			k = j + 1;
			while (k < n)
			{
				if (nums[k] > nums[i] && nums[k] < nums[j])
					return true;
				++k;
			}
			i = j + 1;
		}
		return false;
	}
};
