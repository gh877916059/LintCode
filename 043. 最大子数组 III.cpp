class Solution 
{  
public:  
    int maxSubArray(vector<int> nums, int k) 
    {  
        int n = nums.size();
        vector<vector<int> > dp_must(n+1,vector<int>(k+1,-999999));
        vector<vector<int> > dp_not(n+1,vector<int>(k+1,-999999));
        for(int i=0;i<=n;++i)
        {
            dp_must[i][0]=0;
            dp_not[i][0]=0;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=k;++j)
            {
                dp_must[i][j] = max(dp_not[i-1][j-1] + nums[i-1], dp_must[i-1][j] + nums[i-1]); 
                dp_not[i][j] = max(dp_must[i][j], dp_not[i-1][j]);
            }
        }
        return dp_not[n][k];
    }  
};  
