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
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<int> ru_du_list(numCourses, 0);
		vector<vector<int>> after_can_learn_list(numCourses, vector<int>());
		for (auto itr = prerequisites.begin(); itr != prerequisites.end(); ++itr)
		{
			//a依赖于b
			int a = (*itr).first;
			int b = (*itr).second;
			ru_du_list[a] += 1;
			after_can_learn_list[b].push_back(a);
		}
		vector<int> ret;
		vector<int> curr_list;
		for (int i = ru_du_list.size() - 1; i >= 0; --i)
		{
			if (ru_du_list[i] == 0)
			{
				curr_list.push_back(i);
			}
		}
		while (curr_list.size()>0)
		{
			int curr_chosen = curr_list[curr_list.size() - 1];
			curr_list.pop_back();
			ret.push_back(curr_chosen);
			for (int j = after_can_learn_list[curr_chosen].size() - 1; j >= 0; --j)
			{
				int target = after_can_learn_list[curr_chosen][j];
				ru_du_list[target] -= 1;
				if (ru_du_list[target] == 0)
				{
					curr_list.push_back(target);
				}
			}
		}
		if (ret.size() < numCourses)
		{
			ret.clear();
		}
		return ret;
	}
};
