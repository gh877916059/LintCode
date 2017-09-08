class Solution 
{
public:
    int minimumTotal(vector<vector<int> > &triangle) 
    {
        int n=triangle.size();
        if(n==0)
            return 0;
        int m=triangle[n-1].size();
        int** dp=new int*[n];
        for(int i=0;i<n;++i)
        {
            dp[i]=new int[m];
        }
        for(int i=0;i<m;++i)
        {
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;--i)
        {
            for(int j=0;j<=i;++j)
            {
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
