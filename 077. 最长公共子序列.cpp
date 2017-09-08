class Solution 
{
public:
    int longestCommonSubsequence(string A, string B) 
    {
        int n=A.length();
        int m=B.length();
        int result=0;
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(A[i-1]==B[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    if(dp[i][j]>result)
                        result=dp[i][j];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return result;
    }
};
