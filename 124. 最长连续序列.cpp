class Solution 
{
public:
    int longestConsecutive(vector<int> &num) 
    {
        int size = num.size();
        unordered_set<int> data;
        unordered_set<int> visited;
        if(size < 0)
            return 0;
        for(int i = 0; i < size; i++)
        {
            data.insert(num[i]);
        }
        int maxlen = 0;
        for(int i = 0; i < size; i++)
        {
            if(visited.find(num[i]) == visited.end())
            {
                visited.insert(num[i]);
                int tmplen = 1;
                int tmp = num[i] - 1;
                while(data.find(tmp) != data.end())
                {
                    tmplen++;
                    visited.insert(tmp);
                    tmp--;
                }
                tmp = num[i] + 1;
                while(data.find(tmp) != data.end())
                {
                    tmplen++;
                    visited.insert(tmp);
                    tmp++;
                }
                if(tmplen > maxlen)
                    maxlen = tmplen;
            }
        }
        return maxlen;
    }
};
