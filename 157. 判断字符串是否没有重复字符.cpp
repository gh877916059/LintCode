class Solution 
{
public:
    bool isUnique(string &str) 
    {
        unordered_map<char,int> map;
        for(auto i:str)
        {
            ++map[i];
        }
        for(auto i:map)
        {
            if(i.second>1)
                return false;
        }
        return true;
    }
};
