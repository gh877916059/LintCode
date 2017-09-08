class Solution 
{
public:
    int longestIncreasingSubsequence(vector<int> nums) 
    {
        const int n=nums.size();
        if(n==0)
            return 0;
        vector<int> dp(n,1);
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[i]>nums[j]&&(dp[j]+1>dp[i]))
                    dp[i]=dp[j]+1;
            }
        }
        int result =-1;
        for(int i=0;i<n;++i)
        {
            if(dp[i]>result)
                result=dp[i];
        }
        return result;
    }
};
