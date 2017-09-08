class Solution 
{  
public:  
    int backPack(int m, vector<int> A) 
    {  
        int *dp = new int[m+1];  
        fill(dp,dp+m+1,-1);  
        dp[0]=1;  
        for(auto x:A)  
        {  
            for(int i=m;i>=x;i--)  
            {  
                if(dp[i-x]==1)  
                    dp[i]=1;  
            }  
        }  
        int ret = m;  
        while(dp[ret]==-1)  
            ret--;  
        delete[] dp;  
        return ret;  
    }  
};  
