class TrieNode
{
public:
	TrieNode* children[256];
	string* str;
	TrieNode()
	{
		for (int i = 0; i<256; ++i)
			children[i] = NULL;
		str = NULL;
	}
	void put(string& s, int pos = 0)
	{
		if (pos == s.length())
		{
			str = &s;
			return;
		}
		char c = s[pos];
		if (children[c] == NULL)
			children[c] = new TrieNode();
		children[c]->put(s, pos + 1);
	}
};
class Trie
{
public:
	Trie()
	{
		root = new TrieNode();
	}
	void insert(string word)
	{
		root->put(word);
	}
	bool search(string word)
	{
		int pos = 0;
		if (word.length() == 0)
			return true;
		TrieNode* cur = root;
		for (; pos<word.length(); ++pos)
		{
			char c = word[pos];
			cur = cur->children[c];
			if (cur == NULL)
				return false;
		}
		if (cur->str == NULL)
			return false;
		return true;
	}
	bool startsWith(string prefix)
	{
		int pos = 0;
		if (prefix.length() == 0)
			return true;
		TrieNode* cur = root;
		for (; pos<prefix.length(); ++pos)
		{
			char c = prefix[pos];
			cur = cur->children[c];
			if (cur == NULL)
				return false;
		}
		return true;
	}

private:
	TrieNode* root;
};
