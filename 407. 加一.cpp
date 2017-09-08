class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int> result;
        int jin_wei=1;
        for(int i=digits.size()-1;i>=0;--i)
        {
            int temp=digits[i]+jin_wei;
            result.push_back(temp);
            jin_wei=temp/10;
        }
        if(jin_wei>0)
            result.push_back(jin_wei);
        reverse(result.begin(),result.end());
        return result;
    }
};
