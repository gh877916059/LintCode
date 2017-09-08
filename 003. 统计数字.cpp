class Solution 
{
public:
    int digitCounts(int k, int n) 
    {
        int cnt = 0, j;
        for (int i = 1;j = n / i;i *= 10) 
        {
            int high = j / 10;
            if (k == 0) 
            {
                if (high) 
                    high--;
                else 
                    break;
            }
            cnt += high * i;
            int cur = j % 10;
            if (cur > k) 
            cnt += i;
            else if (cur == k) 
                cnt += n - j * i + 1;
        }
        if(k==0)
            ++cnt;
        return cnt;
    }
};
