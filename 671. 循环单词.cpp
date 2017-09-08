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
	int countRotateWords(vector<string> words)
	{
		unordered_map<string, int> str_to_group_id;
		vector<int> group_id_to_word_num;
		for (auto itr = words.begin(); itr != words.end(); ++itr)
		{
			string target_str = *itr;
			if (str_to_group_id.find(target_str) == str_to_group_id.end())
			{
				int new_index = group_id_to_word_num.size();
				auto rotate_words = generateAllRotateWords(target_str);
				for (auto itr2 = rotate_words.begin(); itr2 != rotate_words.end(); ++itr2)
				{
					str_to_group_id[*itr2] = new_index;
				}
				group_id_to_word_num.push_back(1);
			}
			else
			{
				int group_id = str_to_group_id[target_str];
				++group_id_to_word_num[group_id];
			}
		}
		return group_id_to_word_num.size();
	}
private:
	vector<string> generateAllRotateWords(string source_str)
	{
		vector<string> ret;
		int str_len = source_str.length();
		for (int i = 0; i < str_len; ++i)
		{
			string first_half = source_str.substr(0, i);
			string second_half = source_str.substr(i, str_len - i);
			ret.push_back(second_half + first_half);
		}
		return ret;
	}
};
