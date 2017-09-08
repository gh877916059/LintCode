class Solution 
{
public:
    int maxProfit(int k, vector<int> &prices) 
    {
        int len = prices.size();
        if(k>=len/2)
            return quickSolve(prices);
        vector<vector<int>> t(k+1,vector<int>(len,0));
        for(int i=1;i<=k;++i)
        {
            int tmpMax = -prices[0];
            for(int j=1;j<len;++j)
            {
                t[i][j]=max(t[i][j-1],prices[j]+tmpMax);
                tmpMax=max(tmpMax,t[i-1][j-1]-prices[j]);
            }
        }
        return t[k][len-1];
    }
    int quickSolve(vector<int> &prices)
    {
        int len=prices.size(),profit=0;
        for(int i=1;i<len;++i)
            if(prices[i]>prices[i-1])
                profit += prices[i]-prices[i-1];
        return profit;
    }
};
