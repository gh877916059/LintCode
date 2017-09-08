class Solution 
{  
public:  
    int minCut(string s) 
    {  
        int n = s.length();  
        vector<vector<bool> > dp1(n,vector<bool>(n,false));  
        for(int len = 1;len<=n;len++)  
        {  
            for(int i=0;i+len-1<n;i++)  
            {  
                int j = i+len-1;  
                if(len==1)  
                {  
                    dp1[i][j]=true;  
                }  
                else  
                {  
                    if(s[i]==s[j]&&(i==j-1||dp1[i+1][j-1]))  
                        dp1[i][j] = true;  
                }  
            }  
        }  
        vector<int > dp2(n,INT_MAX);  
        for(int i=0;i<n;i++)  
        {  
            if(dp1[0][i])  
                dp2[i] = 0;  
            for(int j=0;j<i;j++)  
            {  
                if(dp1[j+1][i])  
                    dp2[i] = min(dp2[i],dp2[j]+1);  
            }  
        }  
        return dp2[n-1];  
    }  
      
};  
