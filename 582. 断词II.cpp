#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict)
	{
		vector<string> result;
		vector<string> path;
		const int s_len = s.length();
		vector<bool> f(s_len + 1, false);
		// prev[i][j] 为 true，表示 s[j, i-1] 是一个合法单词，可以从 j 处切开，第一行没有用  
		vector<vector<bool> > prev(s_len + 1, vector<bool>(s_len));
		f[0] = true;
		for (int i = 1; i <= s_len; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (f[j] && (dict.find(s.substr(j, i - j)) != dict.end()))
				{
					f[i] = true;
					prev[i][j] = true;//表示s[j,i-1]是一个合法单词  
				}
			}
		}
		DFS(s, prev, s_len, path, result);
		return result;
	}
	void DFS(string &s, vector<vector<bool> > &prev, int cur, vector<string> &path, vector<string> &result)
	{
		const int s_len = s.length();
		if (cur == 0)
		{
			string tmp;
			for (auto iter = path.rbegin(); iter != path.rend(); iter++)
			{
				tmp += *iter + " ";
			}
			tmp.erase(tmp.end() - 1);
			result.push_back(tmp);
		}
		for (int i = 0; i < s_len; i++)
		{
			if (prev[cur][i])
			{
				path.push_back(s.substr(i, cur - i));
				DFS(s, prev, i, path, result);
				path.pop_back();
			}
		}
	}
};
