#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <functional>
#include <sstream>
using namespace std;

class Solution 
{
public:
	bool isPalindrome(int num) 
	{
		stringstream ss;
		ss << num;
		string str = ss.str();
		int max_offset = str.length() / 2 - 1;
		for (int offset = 0; offset <= max_offset; ++offset)
		{
			if (str[offset] != str[str.length() - 1 - offset])
			{
				return false;
			}
		}
		return true;
	}
};
