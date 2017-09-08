class Solution 
{
public:   
    string longestCommonPrefix(vector<string> &strs) 
    {
        if(strs.size()==0)
            return "";
        string ret = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            string cur = strs[i];
            string temp = ret;
            ret = "";
            for(int j=0;j<min(temp.length(),cur.length());j++)
            {
                if(temp[j]==cur[j])
                    ret+=cur[j];
                else
                    break;
            }
        }
        return ret;
    }
};
