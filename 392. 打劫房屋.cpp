class Solution 
{  
public:  
    long long houseRobber(vector<int> A) 
    {  
        int n = A.size();  
        if(n==0)  
            return 0;  
        long long ret = A[0];  
        vector<long long> dp(3,0);  
        for(int i=0;i<n;i++)  
        {  
            long long temp = 0;  
            for(int j=0;j<2;j++)  
            {  
                temp = max(temp,dp[j]+A[i]);  
            }  
            ret = max(ret,temp);  
            dp.push_back(temp);  
            dp.erase(dp.begin());  
        }  
        return ret;  
    }  
};  
