class Solution 
{
public:
    int longestIncreasingContinuousSubsequence(vector<int>& A) 
    {
        int len=A.size();
        if(len==0)
            return 0;
        int result=1;
        int cur=1;
        for(int i=1;i<len;++i)
        {
            if(A[i]>A[i-1])
            {
                ++cur;
                result=max(result,cur);
            }
            else
            {
                cur=1;
            }
        }
        cur=1;
        for(int i=len-2;i>=0;--i)
        {
            if(A[i]>A[i+1])
            {
                ++cur;
                result=max(result,cur);
            }
            else
            {
                cur=1;
            }
        }
        return result;
    }
};
