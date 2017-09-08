class Solution
{
public:
	vector<vector<string> > result;
	vector<vector<string> > ceng;
	vector<string> cur;
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
	{
		unordered_map<string, bool> check;
		if (start.length() != end.length())
			return result;
		int counter = 0;
		dict.insert(start);
		dict.insert(end);
		for (auto i : dict)
		{
			if (i.length() == start.length())
			{
				check[i] = false;
			}
			else
			{
				dict.erase(i);
			}
		}
		queue<string> Q;
		Q.push(start);
		check[start] = true;
		vector<string> cur_ceng;
		int counter1 = 1;
		int counter2 = 0;
		bool zhao_dao = false;
		while (!Q.empty())
		{
			cur_ceng.clear();
			while (counter1-->0)
			{
				string temp = Q.front();
				Q.pop();
				cur_ceng.push_back(temp);
				if (temp == end)
				{
					zhao_dao = true;
					break;
				}
				for (int i = 0; i<temp.length(); ++i)
				{
					for (char j = 'a'; j <= 'z'; ++j)
					{
						if (temp[i] != j)
						{
							string temp2 = temp.substr(0, i) + j + temp.substr(i + 1);
							if (dict.find(temp2) != dict.end() && !check[temp2])
							{
								Q.push(temp2);
								check[temp2] = true;
								++counter2;
							}
						}
					}
				}
			}
			if (zhao_dao)
				break;
			counter1 = counter2;
			counter2 = 0;
			ceng.push_back(cur_ceng);
			++counter;
		}
		cur.push_back(end);
		diGui(end, counter - 1);
		for (int i = 0; i<result.size(); ++i)
		{
			reverse(result[i].begin(), result[i].end());
		}
		return result;
	}
	void diGui(string yuan, int mu_biao)
	{
		if (mu_biao == 0)
		{
			cur.push_back(ceng[0][0]);
			result.push_back(cur);
			cur.pop_back();
			return;
		}
		else
		{
			for (int j = 0; j<ceng[mu_biao].size(); j++)
			{
				if (onlyOne(yuan, ceng[mu_biao][j]))
				{
					cur.push_back(ceng[mu_biao][j]);
					diGui(ceng[mu_biao][j], mu_biao - 1);
					cur.pop_back();
				}
			}
		}
	}
	bool onlyOne(string a, string b)
	{
		if (a.length() != b.length())
			return false;
		int counter = 0;
		for (int i = 0; i<a.length(); ++i)
		{
			if (a[i] == b[i])
				++counter;
		}
		if (counter == a.length() - 1)
			return true;
		else
			return false;
	}
};
