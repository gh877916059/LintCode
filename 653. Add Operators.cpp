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
	vector<string> addOperators(string &num, int target)
	{
		vector<string> res;
		if (num.length() == 0)
			return res;
		helper(res, "", num, 0, 0, 0, (long)target);
		return res;
	}
private:
	//res为存储符合最终条件的path的列表
	//path为当前递归的临时表达式
	//num为原数字字符串（我们需要往其中加运算符号）
	//pos表示当前只需要处理num[pos:]
	//sum为当前递归的临时计算结果
	//preVal为上次被加或者被减的数
	//target为最终的目标结果
	void helper(vector<string>& res, string path, string& num, int pos, long long sum, long long preVal, long long target)
	{
		if (pos == num.length())
		{
			if (sum == target)
			{
				res.push_back(path);
			}
			return;
		}
		for (int i = pos + 1; i <= num.length(); i++)
		{
			//避免出现类似于"05"这样以0开头的数的错误
			if (num[pos] == '0' && i>pos + 1)
				break;
			string curStr = num.substr(pos, i-pos);
			//选出了现递归阶段的操作目标数
			stringstream ss(curStr);
			long long cur;
			ss >> cur;
			if (pos == 0)
			{
				helper(res, curStr, num, i, cur, cur, target);
			}
			else
			{
				// '+'
				helper(res, path + "+" + curStr, num, i, sum + cur, cur, target);
				// '-'
				helper(res, path + "-" + curStr, num, i, sum - cur, -cur, target);
				// '*'
				helper(res, path + "*" + curStr, num, i, sum - preVal + preVal*cur, preVal*cur, target);
			}
		}
	}
};
