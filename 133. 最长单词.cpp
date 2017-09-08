class Solution 
{
public:
    vector<string> longestWords(vector<string> &dictionary) 
    {
        vector<string> res;
        for(auto str:dictionary)
        {
            if(res.empty()||res[0].length()<str.length())
            {
                res.clear();
                res.push_back(str);
            }
            else if(res[0].length()==str.length())
                res.push_back(str);
        }
        return res;
    }
};
