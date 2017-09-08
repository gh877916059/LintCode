class Solution 
{  
public:  
    int kSum(vector<int> A, int k, int target) 
    {  
        int n = A.size();  
        vector<vector<int> > dp(k+1,vector<int>(target+1,0));  
        dp[0][0] = 1;  
        for(auto a:A)  
        {  
            for(int i=k;i>=1;i--)  
            {  
                for(int j=target;j>=a;j--)  
                {  
                    dp[i][j] += dp[i-1][j-a];  
                }  
            }  
        }  
        return dp[k][target];  
    }  
}; 
