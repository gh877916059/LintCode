#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution
{
public:
	int guessNumber(int n)
	{
		if (n <= 0)
		{
			return -1;
		}
		long long l = 1;
		long long r = n;
		r += 1;
		while (l < r)
		{
			int mid = int(l + (r - l) / 2);
			int guess_ret = guess(mid);
			if (guess_ret == -1)
			{
				r = mid;
			}
			if (guess_ret == 1)
			{
				l = mid + 1;
			}
			if (guess_ret == 0)
			{
				r = mid;
			}
		}
		return l;
	}
};
