class Solution {  
public:  
    int candy(vector<int>& ratings) 
    {  
        vector<int> dp(ratings.size(),1);  
        for(int i=0;i<ratings.size()-1;i++)  
        {  
            if(ratings[i]<ratings[i+1])  
                dp[i+1] = max(dp[i+1],dp[i]+1);  
        }  
        for(int i=ratings.size()-1;i>=1;i--)  
        {  
            if(ratings[i]<ratings[i-1])  
                dp[i-1] = max(dp[i-1],dp[i]+1);  
        }  
        return accumulate(dp.begin(),dp.end(),0);  
    }  
};  
