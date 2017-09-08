public class Solution 
{
    public int longestCommonSubstring(String A, String B) 
    {
        char[] A_s = A.toCharArray();
        char[] B_s = B.toCharArray();
        int[] dp = new int[B_s.length+1];
        int max = 0;
        for(int i=1;i<=A_s.length;++i)
        {
            for(int j=B_s.length;j>=1;--j)
            {
                if(A_s[i-1]==B_s[j-1])
                {
                    dp[j]=dp[j-1]+1;
                    if(dp[j]>max)
                        max = dp[j];
                }
                else
                {
                    dp[j]=0;
                }
            }
        }
        return max;
    }
}
