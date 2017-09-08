class Solution 
{  
public:  
    string getPermutation(int n, int k) 
    {  
        int cnt[10];  
        cnt[0] = 1;  
        for (int i = 1; i < 10; i++)  
            cnt[i] = cnt[i - 1] * i;  
        map<int, bool> m;  
        string ret = "";  
        for (int i = 1; i <= n; i++)  
        {  
            int t = (k / cnt[n - i]) + (k%cnt[n - i] == 0 ? 0 : 1);  
            k -= (t - 1)*cnt[n - i];  
            int j = 1;  
            for (; j <= n; j++)  
            {  
                if (!m[j])  
                {  
                    t--;  
                    if (t == 0)  
                        break;  
                }  
            }  
            m[j] = true;  
            char c = '0' + j;  
            ret += c;  
        }  
        return ret;  
    }  
};  
