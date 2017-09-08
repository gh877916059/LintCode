class Solution 
{
public:
    bool isScramble(string& s1, string& s2) 
    {
        if(s1.length()!=s2.length())
            return false;
        if(s1=="")
            return true;
        int n=s1.length();
        vector<vector<vector<int>>> rst(n,vector<vector<int>>(n,vector<int>(n,0)));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                rst[0][i][j]=(s1[i]==s2[j]);
            }
        }
        for(int len=2;len<=n;++len)
        {
            for(int i=n-len;i>=0;--i)
            {
                for(int j=n-len;j>=0;--j)
                {
                    bool r = false;
                    for(int k=1;k<len&&!r;++k)
                    {
                        r=(rst[k-1][i][j]&&rst[len-k-1][i+k][j+k])||(rst[k-1][i][j+len-k]&&rst[len-k-1][i+k][j]);
                    }
                    rst[len-1][i][j]=r;
                }
            }
        }
        return rst[n-1][0][0];
    }
};
