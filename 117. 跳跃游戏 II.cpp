class Solution 
{
public:
    int jump(vector<int> A) 
    {
        int n = A.size();
        int res=0;
        int cur=0;
        int i=0;
        while(cur<n-1)
        {
            int pre=cur;
            while(i<=pre)
            {
                if(i+A[i]>cur)
                    cur=i+A[i];
                ++i;
            }
            ++res;
            if(pre==cur)
                return -1;
        }
        return res;
    }
};
