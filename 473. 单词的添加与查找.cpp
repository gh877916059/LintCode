class DicNode
{
public:
	DicNode* children[26];
	string* str;
	DicNode()
	{
		for (int i = 0; i < 26; ++i)
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
		if (children[(c-'a')] == NULL)
			children[(c-'a')] = new DicNode();
		children[(c-'a')]->put(s, pos + 1);
	}
};
class WordDictionary
{
public:
	DicNode* root = new DicNode();
	void addWord(string word)
	{
		root->put(word);
	}
	bool search(string word)
	{
		if (word.length() == 0)
			return true;
		return find(root, word, 0);
	}
	bool find(DicNode* gen, string& word, int pos)
	{
		if (pos == word.length())
			return gen->str != NULL;
		char c = word[pos];
		if (c == '.')
		{
			for (int i = 0; i<26; ++i)
			{
				if (gen->children[i] != NULL&&find(gen->children[i], word, pos + 1))
					return true;
			}
			return false;
		}
		else
		{
			if (gen->children[(c-'a')])
				return find(gen->children[(c-'a')], word, pos + 1);
		}
	}
};
