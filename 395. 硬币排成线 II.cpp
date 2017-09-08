class Solution 
{  
public:  
    bool firstWillWin(vector<int> &values) 
    {  
        int n = values.size();  
        if(n<=2)  
            return true;  
        vector<pair<int,int> > dp(n,make_pair(0,0));  
        dp[n-1] = make_pair(values[n-1],0);  
        dp[n-2] = make_pair(values[n-1]+values[n-2],0);  
        for(int i=n-3;i>=0;i--)  
        {  
            pair<int,int> p1 = dp[i+1];  
            pair<int,int> p2 = dp[i+2];  
            if(p1.second+values[i]>p2.second+values[i]+values[i+1])  
            {  
                dp[i] = make_pair(p1.second+values[i],p1.first);  
            }  
            else  
            {  
                dp[i] = make_pair(p2.second+values[i]+values[i+1],p2.first);  
            }  
        }  
        return dp[0].first>dp[0].second;  
    }  
};  
