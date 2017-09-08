#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

inline int upper_bound(vector<int> A, int x, int y, int v)
{
	int m;
	while (x < y)
	{
		m = x + (y - x) / 2;
		if (A[m] <= v)
			x = m + 1;
		else
			y = m;
	}
	return x;
}

class Solution 
{
public:
	int triangleCount(vector<int> &S) 
	{
		int ret = 0;
		int n = S.size();
		sort(S.begin(), S.end());
		for (int i = 0; i<n; i++)
		{
			for (int j = i + 2; j<n; j++)
			{
				int target = S[j] - S[i];
				int upper_index = upper_bound(S, i+1, j, target);
				int how_many = j - upper_index;
				ret += how_many;
			}
		}
		return ret;
	}
};
