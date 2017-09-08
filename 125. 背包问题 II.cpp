class Solution 
{  
public:  
    int backPackII(int m, vector<int> A, vector<int> V) 
    {  
        int* dp = new int[m+1];  
        fill(dp,dp+m+1,0);  
        int ret = 0;  
        for(int i=0;i<A.size();i++)  
        {  
            for(int j=m;j>=A[i];j--)  
            {  
                dp[j] = max(dp[j],dp[j-A[i]]+V[i]);  
                ret = max(ret,dp[j]);  
            }  
        }  
        return ret;  
    }  
};  
