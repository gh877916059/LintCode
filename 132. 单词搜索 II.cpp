class DicNode 
{  
public:  
    DicNode* children[256];  
    string* str;  
    DicNode() 
    {  
        for(int i = 0; i < 256; ++i) 
            children[i] = NULL;  
        str = NULL;  
    }  
    void put(string& s, int pos = 0) 
    {  
        if(pos == s.size()) 
        {  
            str = &s;  
            return;  
        }  
        char c = s[pos];  
        if(children[c] == NULL) 
            children[c] = new DicNode();  
        children[c]->put(s, pos + 1);  
    }  
};  
  
class Solution 
{  
public:  
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) 
    {  
        vector<string> r;  
        if(board.size() == 0) 
            return r;  
        DicNode* node = new DicNode();  
        for(int i = 0; i < words.size(); ++i) 
            node->put(words[i]);  
        for(int i = 0; i < board.size(); ++i) 
            for(int j = 0; j < board[i].size(); ++j) 
                sub(i, j, node, board, r);  
        return r;  
    }  
    void sub(int px, int py, DicNode* node, vector<vector<char> > &board, vector<string>& r) 
    {  
        if(px < 0 || px >= board.size() || py < 0 || py >= board[0].size()) 
            return;  
        char c = board[px][py];  
        DicNode* cur = node->children[c];   
        if(cur != NULL) 
        {  
            if(cur->str != NULL) 
            {  
                r.push_back(*(cur->str));  
                cur->str = NULL;  
            }   
            board[px][py] = '#';  
            sub(px + 1, py, cur, board, r);  
            sub(px - 1, py, cur, board, r);  
            sub(px, py + 1, cur, board, r);  
            sub(px, py - 1, cur, board, r);  
            board[px][py] = c;  
        }  
    }  
};  
