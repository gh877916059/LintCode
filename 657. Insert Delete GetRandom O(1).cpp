#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

class RandomizedSet
{
public:
	RandomizedSet() {}

	bool insert(int val)
	{
		if (m.count(val))
			return false;
		nums.push_back(val);
		m[val] = nums.size() - 1;
		return true;
	}

	bool remove(int val)
	{
		if (!m.count(val))
			return false;
		int last = nums.back();
		m[last] = m[val];
		nums[m[val]] = last;
		nums.pop_back();
		m.erase(val);
		return true;
	}

	int getRandom()
	{
		return nums[rand() % nums.size()];
	}
private:
	//真正存储数本身的数组
	vector<int> nums;
	//m[val]表示数val在nums中的下标（只存储下标，而不存储数本身）
	unordered_map<int, int> m;
};
