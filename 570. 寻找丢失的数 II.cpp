#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
	int findMissing2(int n, string &str)
	{
		//标记数组
		vector<bool> visited(n + 1, false);
		return dfs(n, str, 0, visited);
	}
	int getNumber(string& str, int start, int len)
	{
		return atoi(str.substr(start, len).c_str());
	}
	int dfs(int n, string& str, int index, vector<bool>& visited)
	{
		//如果已经搜索完毕，开始判断  
		if (index == str.length())
		{
			vector<int> result;
			for (int i = 1; i <= n; i++)
			{
				if (!visited[i])
					result.push_back(i);
			}
			if (result.size() == 1)
				return result[0];
			else
				return -1;//不存在  
		}
		//去掉单独的0的情况
		if (str[index] == '0')
		{
			return -1;
		}
		//判断每一个位置的1位和2位的数
		for (int i = 1; i<3; i++)
		{ 
			int num = getNumber(str, index, i);
			if (num >= 1 && num <= n && !visited[num])
			{
				visited[num] = true;
				int target = dfs(n, str, index + i, visited);
				if (target != -1)
					return target;
				//回复原值，判断下一种情况
				visited[num] = false;
			}
		}
		return -1;
	}
};
