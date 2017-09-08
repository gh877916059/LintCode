class Solution 
{
public:
    int numSquares(int n) 
    {
        vector<int> dp(n+1,INT_MAX);
        for(int i=0;i*i<=n;++i)
            dp[i*i]=1;
        for(int a=0;a<=n;++a)
        {
            for(int b=0;a+b*b<=n;++b)
            {
                dp[a+b*b]=min(dp[a]+1,dp[a+b*b]);
            }
        }
        return dp[n];
    }
};
