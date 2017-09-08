class Solution 
{
public:
    vector<int> grayCode(int n) 
    {
        vector<int> result;
        if(n==0)
        {
            result.push_back(0);
            return result;
        }
        if(n==1)
        {
            result.push_back(0);
            result.push_back(1);
            return result;
        }
        vector<int> list = grayCode(n-1);
        for(int i=0;i<list.size();++i)
            result.push_back(list[i]);
        for(int i=list.size()-1;i>=0;--i)
            result.push_back((int)pow(2,n-1)+list[i]);
        return result;
    }
};
