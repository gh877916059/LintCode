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
using namespace std;

class Solution
{
public:
	bool canCross(vector<int>& stones)
	{
		map<pair<int, int>, bool> m;
		return dfs(stones, 0, 0, m);
	}
	bool dfs(vector<int>& stones, int pos, int jump, map<pair<int, int>, bool>& m)
	{
		int n = stones.size();
		pair<int, int> key = make_pair(pos, jump);
		if (pos >= n - 1)
			return true;
		if (m.count(key))
			return m[key];
		for (int i = pos + 1; i < n; ++i)
		{
			int dist = stones[i] - stones[pos];
			if (dist < jump - 1)
				continue;
			if (dist > jump + 1)
				return m[key] = false;
			if (dfs(stones, i, dist, m))
				return m[key] = true;
		}
		return m[key] = false;
	}
};
