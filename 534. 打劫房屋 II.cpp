class Solution 
{
public:
    int houseRobber2(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        vector<vector<int>> dp(nums.size(),vector<int>(2,0));
        dp[0][1]=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
            dp[i][1]=dp[i-1][0]+nums[i];
        }
        int r1=dp[nums.size()-1][0];
        dp[0][1]=0;
        for(int i=1;i<nums.size();++i)
        {
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
            dp[i][1]=dp[i-1][0]+nums[i];
        }
        return max(dp[nums.size()-1][1],r1);
    }
};
