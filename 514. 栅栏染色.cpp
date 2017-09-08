class Solution 
{
public:
    int numWays(int n, int k) 
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
        if (n == 2)
            return k*k;
        int pre = k;
        int now = k*k;
        for (int i = 3; i <= n; i++)
        {
            int tmp = now;
            now = (pre+now) * (k-1);
            pre = tmp;
        }
        return now;
    }
};
