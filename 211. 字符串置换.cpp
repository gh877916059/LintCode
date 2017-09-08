#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class Solution 
{
public:
	bool Permutation(string &A, string &B) 
	{
		unordered_map<char, int> A_char_counter;
		unordered_map<char, int> B_char_counter;
		int A_n = A.length();
		int B_n = B.length();
		for (int i = 0; i < A_n; ++i)
		{
			char target_char = A[i];
			A_char_counter[target_char] += 1;
		}
		for (int i = 0; i < B_n; ++i)
		{
			char target_char = B[i];
			B_char_counter[target_char] += 1;
		}
		bool ret = true;
		for (auto itr = A_char_counter.begin(); itr != A_char_counter.end(); ++itr)
		{
			char target_char = itr->first;
			int counter = itr->second;
			if (B_char_counter[target_char] != counter)
			{
				ret = false;
				break;
			}
		}
		for (auto itr = B_char_counter.begin(); itr != B_char_counter.end(); ++itr)
		{
			char target_char = itr->first;
			int counter = itr->second;
			if (A_char_counter[target_char] != counter)
			{
				ret = false;
				break;
			}
		}
		return ret;
	}
};
