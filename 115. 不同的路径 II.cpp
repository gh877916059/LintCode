class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
    {
        int n = obstacleGrid.size();
        if(n==0)
            return 0;
        int m = obstacleGrid[0].size();
        int** dp = new int* [n];
        for(int i=0;i<n;++i)
        {
            dp[i]=new int[m];
        }
        if(obstacleGrid[0][0]==1)
            return 0;
        dp[0][0]=1;
        bool you_zhang_ai=false;
        for(int i=1;i<n;++i)
        {
            if(obstacleGrid[i][0]==1)
                you_zhang_ai=true;
            if(you_zhang_ai)
                dp[i][0]=0;
            else
                dp[i][0]=1;
        }
        you_zhang_ai=false;
        for(int i=1;i<m;++i)
        {
            if(obstacleGrid[0][i]==1)
                you_zhang_ai=true;
            if(you_zhang_ai)
                dp[0][i]=0;
            else
                dp[0][i]=1;
        }
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};
