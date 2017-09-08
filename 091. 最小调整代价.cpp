class Solution 
{  
public:  
    int MinAdjustmentCost(vector<int> A, int target) 
    {  
        if(A.size()<2)  
            return 0;  
        vector<vector<int> > dp(A.size(),vector<int>(101,0));  
        for(int i=0;i<101;i++)  
            dp[0][i] = abs(A[0]-i);  
        for(int i=1;i<A.size();i++)  
        {  
            for(int j=0;j<101;j++)  
            {  
                dp[i][j] = INT_MAX;  
                int diff = abs(j-A[i]);  
                int upper = min(j+target,100);  
                int lower = max(j-target,0);  
                for(int k=lower;k<=upper;k++)  
                {  
                    dp[i][j] = min(dp[i][j],dp[i-1][k]+diff);  
                }  
            }  
        }  
        int ret = INT_MAX;  
        for(int i=0;i<101;i++)  
            ret = min(ret,dp[A.size()-1][i]);  
        return ret;  
          
    }  
};  
