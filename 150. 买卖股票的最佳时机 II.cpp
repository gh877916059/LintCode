class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        int n=prices.size();
        if(n<=1)
            return 0;
        int result=0;
        for(int i=1;i<n;++i)
        {
            if(prices[i]>prices[i-1])
                result+=prices[i]-prices[i-1];
        }
        return result;
    }
};
