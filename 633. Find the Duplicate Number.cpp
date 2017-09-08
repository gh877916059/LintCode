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
	int findDuplicate(vector<int>& nums)
	{
		int slow = 0, fast = 0, t = 0;
		while (true)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast)
				break;
		}
		while (true)
		{
			slow = nums[slow];
			t = nums[t];
			if (slow == t)
				break;
		}
		return slow;
	}
};
