class DicNode
{
public:
	DicNode* children[256];
	string* str;
	DicNode()
	{
		for (int i = 0; i < 256; ++i)
			children[i] = NULL;
		str = NULL;
	}
	void put(string& s, int pos = 0)
	{
		if (pos == s.size())
		{
			str = &s;
			return;
		}
		char c = s[pos];
		if (children[c] == NULL)
			children[c] = new DicNode();
		children[c]->put(s, pos + 1);
	}
};
class Solution
{
public:
	bool found = false;
	bool exist(vector<vector<char> > &board, string word)
	{
		if (board.size() == 0)
			return false;
		DicNode* node = new DicNode();
		node->put(word);
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[i].size(); ++j)
			{
				sub(i, j, node, board);
				if (found)
					return true;
			}
		return false;
	}
	void sub(int px, int py, DicNode* node, vector<vector<char> > &board)
	{
		if (px < 0 || px >= board.size() || py < 0 || py >= board[0].size())
			return;
		char c = board[px][py];
		DicNode* cur = node->children[c];
		if (cur != NULL)
		{
			if (cur->str != NULL)
			{
				found = true;
				return;
			}
			board[px][py] = '#';
			sub(px + 1, py, cur, board);
			if(found)
			    return;
			sub(px - 1, py, cur, board);
			if(found)
			    return;
			sub(px, py + 1, cur, board);
			if(found)
			    return;
			sub(px, py - 1, cur, board);
			board[px][py] = c;
		}
	}
};
