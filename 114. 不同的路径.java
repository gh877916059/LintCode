public class Solution 
{
    public int uniquePaths(int m, int n) 
    {
        int[] dp = new int[n+1];
        dp[0]=0;
        for(int i=1;i<=n;++i)
        {
            dp[i]=1;
        }
        for(int i=2;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dp[j]+=dp[j-1];
            }
        }
        return dp[n];
    }
}
