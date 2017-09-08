class Solution
{
public:
	unordered_map<char, vector<pair<int, int>>*> map;
	bool isValidSudoku(const vector<vector<char>>& board)
	{
		int n = board.size();
		if (n == 0)
			return true;
		int m = board[0].size();
		for (int i = 0; i<n; ++i)
		{
			for (int j = 0; j<m; ++j)
			{
				if (board[i][j] != '.')
				{
					if (map.find(board[i][j]) == map.end())
					{
						vector<pair<int, int>>* temp = new vector<pair<int, int>>();
						temp->push_back(make_pair(i, j));
						map[board[i][j]] = temp;
					}
					else
					{
						vector<pair<int, int>>* temp = map[board[i][j]];
						for (auto k : (*temp))
						{
							if (k.first == i)
								return false;
							if (k.second == j)
								return false;
							int new_i = (i / 3) * 3;
							int new_j = (j / 3) * 3;
							int new_ki = (k.first / 3) * 3;
							int new_kj = (k.second / 3) * 3;
							if (new_i == new_ki&&new_j == new_kj)
								return false;
						}
						temp->push_back(make_pair(i,j));
					}
				}
			}
		}
		return true;
	}
};
